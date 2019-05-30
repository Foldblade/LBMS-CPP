#include "search_book.h"
#include "qstring.h"
#include "search_book_result_no.h"
#include "domysql.h"

search_book::search_book(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

search_book::~search_book()
{
}
void search_book_result_no::slot1() {
	search_book* y = new search_book;
	y->show();
	this->hide();
}
void search_book::slot2() {
	x = new search_book_result_no;
	QString isbn = ui.isbn->text();
	QString book_name = ui.book_name->text();
	QString writer = ui.writer->text();
	QString publishing_house = ui.publishing_house->text();
	//这里需要加入数据库；
	/*So the left work are made by F.B.*/
	Operate search_book_no;
	search_book_no.searchBook(isbn.toStdString(), book_name.toStdString(), writer.toStdString(), publishing_house.toStdString());
	x->show();
	this->hide();
}