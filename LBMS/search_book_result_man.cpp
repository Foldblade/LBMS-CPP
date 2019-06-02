#include "search_book_result_man.h"
#include "domysql.h"
#include "QMessageBox"
#include "search_book_man.h"
#include <boost/format.hpp>

using namespace std;

/* UI initial by X.H., but modified by F.B. */
string isbn2, book_name2, writer2, publishing_house2;

search_book_result_man::search_book_result_man(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

search_book_result_man::~search_book_result_man()
{
}

void search_book_result_man::slot1() {
	search_book_man* x = new search_book_man;
	x->show();
	this->hide();
} // 返回

void search_book_result_man::slot2() {

}// 确认修改
void search_book_result_man::go() {
	Operate search_book_result_man;
	if (search_book_result_man.connect()) {
		if (!search_book_result_man.searchBook(isbn2, book_name2, writer2, publishing_house2)) {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("查询操作错误，请重试。"), QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("远程数据库连接错误，请重试。"), QMessageBox::Ok);
	}
	//这里需要加入数据库；
	/*So the left work are made by F.B.*/

	if (search_book_result_man.length == 0) {
		ui.resultLabel->setText(QString::fromLocal8Bit("很遗憾，数据库中并没有您查询的书籍。"));
	}
	else {
		boost::format f = boost::format("查找到%d本相关书籍：") % search_book_result_man.length;
		string s = f.str();
		ui.resultLabel->setText(QString::fromLocal8Bit(s.data()));
	}

	//QTextCodec* codec = QTextCodec::codecForName("GBK");
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	int NumOfReg = search_book_result_man.length; // 行数
	ui.tableWidget->setColumnCount(8);
	ui.tableWidget->setRowCount(NumOfReg);
	/* 设置 tableWidget */
	ui.tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit("ISBN") << QString::fromLocal8Bit("书名") << QString::fromLocal8Bit("作者") << QString::fromLocal8Bit("出版社")
		<< QString::fromLocal8Bit("总数") << QString::fromLocal8Bit("馆藏") << QString::fromLocal8Bit("借出") << QString::fromLocal8Bit("记录ID"));
	

	QString(*content)[8] = new QString[search_book_result_man.length][8];
	for (int i = 0; i < search_book_result_man.length; i++) {
		content[i][0] = { QString::fromLocal8Bit(any_cast<string>(search_book_result_man.results[i]["ISBN"]).data()) };
		content[i][1] = { QString::fromLocal8Bit(any_cast<string>(search_book_result_man.results[i]["title"]).data()) };
		content[i][2] = { QString::fromLocal8Bit(any_cast<string>(search_book_result_man.results[i]["author"]).data()) };
		content[i][3] = { QString::fromLocal8Bit(any_cast<string>(search_book_result_man.results[i]["publisher"]).data()) };
		content[i][4] = { QString::number(any_cast<int>(search_book_result_man.results[i]["many"])) };
		content[i][5] = { QString::number(any_cast<int>(search_book_result_man.results[i]["inside"])) };
		content[i][6] = { QString::number(any_cast<int>(search_book_result_man.results[i]["outside"])) };
		content[i][7] = { QString::number(any_cast<int>(search_book_result_man.results[i]["id"])) };
	}
	/*int linenumber, columnnumber;
	linenumber = ;
	columnnumber = 6;
	QString content[linenumber][columnnumber];
	for (int i = 0; i < linenumber; i++) {
		for (int j = 0; j < columnnumber; j++) {
			QTableWidgetItem* item = new QTableWidgetItem(content[i][j]);
			ui.tableWidget->setItem(i, j, item);//setItem(行，列，内容)
		}
	}*/
	for (int i = 0; i < search_book_result_man.length; i++) {
		for (int j = 0; j < 8; j++) {
			QTableWidgetItem* item = new QTableWidgetItem(content[i][j]);
			ui.tableWidget->setItem(i, j, item);//setItem(行，列，内容)
		}
	}
	ui.tableWidget->resizeColumnsToContents(); //根据内容调整列宽
	//ui.tableWidget->verticalHeader()->setVisible(false); // 隐藏水平header
	// ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);   // 单个选中
	//ui.tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 可以选中多个
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	/* 整行选中 -by F.B. */
}

void search_book_result_man::receive_book_data(QString isbn, QString book_name, QString writer, QString publishing_house) {
	::isbn2 = isbn.toLocal8Bit();
	::book_name2 = book_name.toLocal8Bit();
	::writer2 = writer.toLocal8Bit();
	::publishing_house2 = publishing_house.toLocal8Bit();
}
