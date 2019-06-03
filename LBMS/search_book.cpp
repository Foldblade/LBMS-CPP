#include "search_book.h"
#include "qstring.h"
#include "search_book_result_no.h"


search_book::search_book(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

search_book::~search_book()
{
}

void search_book::slot2() {
	/* Below works are modified by F.B. */
	x = new search_book_result_no;
	x->show();
	x->receive_book_data(ui.isbn->text(), ui.book_name->text(), ui.writer->text(), ui.publishing_house->text());
	x->go();
	this->hide();
}

