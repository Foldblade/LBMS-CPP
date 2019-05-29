#include "search_book_result_man.h"
using namespace std;
search_book_result_man::search_book_result_man(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//QTextCodec* codec = QTextCodec::codecForName("GBK");
	int NumOfReg = 10000;
	ui.tableWidget->setColumnCount(7);
	ui.tableWidget->setRowCount(NumOfReg);
	/* 设置 tableWidget */
	ui.tableWidget->setHorizontalHeaderLabels(QStringList() << "ISBN" << QString::fromLocal8Bit("书名") << QString::fromLocal8Bit("作者") << QString::fromLocal8Bit("出版社") << QString::fromLocal8Bit("总数")<< QString::fromLocal8Bit("馆藏") << QString::fromLocal8Bit("借出")<<"id");
	//ui.tableWidget->verticalHeader()->setVisible(false); // 隐藏水平header
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);   // 单个选中
	ui.tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 可以选中多个
	QString content[5][5];
	content[0][0] = { "1" }; content[0][1] = { "a" }; content[0][2] = { "b" }; content[0][3] = { "c" }; content[0][4] = { "d" };
	content[1][0] = { "2" }; content[1][1] = { "a" }; content[1][2] = { "b" }; content[1][3] = { "c" }; content[1][4] = { "d" };
	content[2][0] = { "3" }; content[2][1] = { "a" }; content[2][2] = { "b" }; content[2][3] = { "c" }; content[2][4] = { "d" };
	content[3][0] = { "4" }; content[3][1] = { "a" }; content[3][2] = { "b" }; content[3][3] = { "c" }; content[3][4] = { "d" };
	content[4][0] = { "5" }; content[4][1] = { "a" }; content[4][2] = { "b" }; content[4][3] = { "c" }; content[4][4] = { "d" };
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
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			QTableWidgetItem* item = new QTableWidgetItem(content[i][j]);
			ui.tableWidget->setItem(i, j, item);//setItem(行，列，内容)
		}
	}
}

search_book_result_man::~search_book_result_man()
{
}
