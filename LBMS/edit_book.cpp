#include "edit_book.h"
#include "search_book_man.h"
edit_book::edit_book(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

edit_book::~edit_book()
{
}
void edit_book::saving() {

}//����
void edit_book::deleting() {

}//ɾ��
void edit_book::back() {
	search_book_man* x = new search_book_man;
	x->show();
	this->hide();
}//����
