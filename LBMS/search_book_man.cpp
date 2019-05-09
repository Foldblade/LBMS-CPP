#include "search_book_man.h"
#include "search_book_result_man.h"

search_book_man::search_book_man(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

search_book_man::~search_book_man()
{
}
void search_book_result_man::slot1() {
	search_book_man* x = new search_book_man;
	x->show();
	this->hide();
}