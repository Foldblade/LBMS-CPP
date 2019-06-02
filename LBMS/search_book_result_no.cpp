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
		QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("Զ�����ݿ����Ӵ��������ԡ�"), QMessageBox::Ok);
	}
	//������Ҫ�������ݿ⣻
	/*So the left work are made by F.B.*/
	
	if (search_book_no.length == 0) {
		ui.resultLabel->setText(QString::fromLocal8Bit("���ź������ݿ��в�û������ѯ���鼮��"));
	}
	else {
		boost::format f = boost::format("���ҵ�%d������鼮��") % search_book_no.length;
		string s = f.str();
		ui.resultLabel->setText(QString::fromLocal8Bit(s.data()));
	}

	//QTextCodec* codec = QTextCodec::codecForName("GBK");
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	int NumOfReg = search_book_no.length; // ����
	ui.tableWidget->setColumnCount(7);
	ui.tableWidget->setRowCount(NumOfReg);
	/* ���� tableWidget */
	ui.tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit("ISBN") << QString::fromLocal8Bit("����") << QString::fromLocal8Bit("����") << QString::fromLocal8Bit("������")
		<< QString::fromLocal8Bit("����") << QString::fromLocal8Bit("�ݲ�") << QString::fromLocal8Bit("���"));
	//ui.tableWidget->verticalHeader()->setVisible(false); // ����ˮƽheader
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);   // ����ѡ��
	ui.tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  // ����ѡ�ж��

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
			ui.tableWidget->setItem(i, j, item);//setItem(�У��У�����)
		}
	}*/
	for (int i = 0; i < search_book_no.length; i++) {
		for (int j = 0; j < 7; j++) {
			QTableWidgetItem* item = new QTableWidgetItem(content[i][j]);
			ui.tableWidget->setItem(i, j, item);//setItem(�У��У�����)
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