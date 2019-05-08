#include "adminitor_con.h"
#include "scan_input.h"
#include "success.h"
#include "qstring.h"
#include "personal_cen.h"
#include "search_book_man.h"
#include "search_book_result_man.h"
#include "personal_change_password.h"
#include "personal_change_name.h"
#include "borrow_return_book.h"
adminitor_con::adminitor_con(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

adminitor_con::~adminitor_con()
{
}
void adminitor_con::slot2() {
	scan_input* x = new scan_input;
	x->show();
	this->hide();
}//scan_input
void adminitor_con::slot3() {
	personal_cen* x = new personal_cen;
	x->show();
	this->hide();
}//personal_cen
void adminitor_con::slot4() {
	search_book_man* x = new search_book_man;
	x->show();
	this->hide();
}
void adminitor_con::slot5() {
	borrow_return_book* x = new borrow_return_book;
	x->show();
	this->hide();
}
void scan_input::slot1() {
	adminitor_con* x = new adminitor_con;
	x->show();
	this->hide();
}//return 
void scan_input::slot2() {
	QString isbn, name, writer, press, book_no;
	isbn = ui.isbn->text();//isbn号
	name = ui.name->text();//书名
	writer = ui.writer->text();//作者
	press = ui.press->text();//出版社
	book_no = ui.book_no->text();//书号
	success* x = new success;
	x->show();
}//add
void scan_input::slot3() {

}//opencv
void personal_cen::slot1() {
	adminitor_con* x = new adminitor_con;
	x->show();
	this->hide();
}//return 
void personal_cen::slot2() {
	personal_change_password* x = new personal_change_password;
	x->show();
	this->hide();
}//change password
void personal_cen::slot3() {
	personal_change_name* x = new personal_change_name;
	x->show();
	this->hide();
}//change name
void search_book_man::slot1() {
	adminitor_con* x = new adminitor_con;
	x->show();
	this->hide();
}//返回
void search_book_man::slot2() {
	search_book_result_man* x = new search_book_result_man;
	x->show();
	this->hide();
}//查询
void borrow_return_book::slot1() {
	adminitor_con* x = new adminitor_con;
	x->show();
	this->hide();
}//返回
void borrow_return_book::slot2() {
	success* x = new success;
	x->show();
}//借书
void borrow_return_book::slot3() {
	success* x = new success;
	x->show();
}//还书
void borrow_return_book::slot4() {

}//opencv