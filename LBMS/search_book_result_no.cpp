#include "search_book_result_no.h"
#include "search_book.h"
#include "domysql.h"
#include "QMessageBox"
#include <iostream>
#include <string>
#include <boost/format.hpp>
//#include <qtextcodec.h>

string isbn, book_name, writer, publishing_house;

search_book_result_no::search_book_result_no(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void search_book_result_no::go() {
	
	Operate search_book_no;
	if (search_book_no.connect()) {
		search_book_no.searchBook(isbn, book_name, writer, publishing_house);
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("远程数据库连接错误，请重试。"), QMessageBox::Ok);
	}
	//这里需要加入数据库；
	/*So the left work are made by F.B.*/
	
	if (search_book_no.length == 0) {
		ui.resultLabel->setText(QString::fromLocal8Bit("很遗憾，数据库中并没有您查询的书籍。"));
	}
	else {
		boost::format f = boost::format("查找到%d本相关书籍：") % search_book_no.length;
		string s = f.str();
		ui.resultLabel->setText(QString::fromLocal8Bit(s.data()));
	}

	//QTextCodec* codec = QTextCodec::codecForName("GBK");
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	int NumOfReg = search_book_no.length; // 行数
	ui.tableWidget->setColumnCount(7);
	ui.tableWidget->setRowCount(NumOfReg);
	/* 设置 tableWidget */
	ui.tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit("ISBN") << QString::fromLocal8Bit("书名") << QString::fromLocal8Bit("作者") << QString::fromLocal8Bit("出版社")
		<< QString::fromLocal8Bit("总数") << QString::fromLocal8Bit("馆藏") << QString::fromLocal8Bit("借出"));
	//ui.tableWidget->verticalHeader()->setVisible(false); // 隐藏水平header
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);   // 单个选中
	ui.tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 可以选中多个

	QString(* content)[7] = new QString[search_book_no.length][7];
	for (int i = 0; i < search_book_no.length; i++) {
		content[i][0] = { QString::fromLocal8Bit(any_cast<string>(search_book_no.results[i]["ISBN"]).data()) };
		content[i][1] = { QString::fromLocal8Bit(any_cast<string>(search_book_no.results[i]["title"]).data()) };
		content[i][2] = { QString::fromLocal8Bit(any_cast<string>(search_book_no.results[i]["author"]).data()) };
		content[i][3] = { QString::fromLocal8Bit(any_cast<string>(search_book_no.results[i]["publisher"]).data()) };
		content[i][4] = { QString::number(any_cast<int>(search_book_no.results[i]["many"])) };
		content[i][5] = { QString::number(any_cast<int>(search_book_no.results[i]["inside"])) };
		content[i][6] = { QString::number(any_cast<int>(search_book_no.results[i]["outside"])) };
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
	for (int i = 0; i < search_book_no.length; i++) {
		for (int j = 0; j < 7; j++) {
			QTableWidgetItem* item = new QTableWidgetItem(content[i][j]);
			ui.tableWidget->setItem(i, j, item);//setItem(行，列，内容)
		}
	}
}

search_book_result_no::~search_book_result_no()
{
}

void search_book_result_no::send_book_data(QString isbn, QString book_name, QString writer, QString publishing_house) {
	::isbn = isbn.toLocal8Bit();
	::book_name = book_name.toLocal8Bit();
	::writer = writer.toLocal8Bit();
	::publishing_house = publishing_house.toLocal8Bit();
}