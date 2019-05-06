#include "search_book.h"
#include "qstring.h"

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
	QString isbn;
	QString book_name;
	QString writer;
	QString publishing_house;
	isbn = ui.isbn->text();
	book_name = ui.book_name->text();
	writer = ui.writer->text();
	publishing_house = ui.publishing_house->text();
	//这里需要加入数据库；
	x->show();
	this->hide();
}