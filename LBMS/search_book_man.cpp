#include "search_book_man.h"
#include "search_book_result_man.h"
#include "adminitor_con.h"

search_book_man::search_book_man(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

search_book_man::~search_book_man()
{
}

void search_book_man::slot1() {
	adminitor_con* x = new adminitor_con;
	x->show();
	this->hide();
}// 返回管理中心

void search_book_man::slot2() {
	/* Below works are modified by F.B. */
	search_book_result_man* x = new search_book_result_man;
	x->receive_book_data(ui.isbn->text(), ui.book_name->text(), ui.writer->text(), ui.publishing_house->text());
	x->show();
	x->go();
	this->hide();
} // 查询

