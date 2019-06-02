#include "borrow_return_book.h"
#include "adminitor_con.h"
#include "domysql.h"
#include "scanner.h"

borrow_return_book::borrow_return_book(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

borrow_return_book::~borrow_return_book()
{
}

void borrow_return_book::slot1() {
	adminitor_con* x = new adminitor_con;
	x->show();
	this->hide();
}//返回
void borrow_return_book::slot2() {
	QString ISBN = ui.isbn->text();
	Operate borrowBook;
	if (borrowBook.connect()) {
		if (borrowBook.borrow_book(ISBN.toStdString())) {
			QMessageBox::information(NULL, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("借书操作成功！"), QMessageBox::Ok);
		}
		else {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("借书操作错误，请重试。"), QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("远程数据库连接错误，请重试。"), QMessageBox::Ok);
	}
}//借书
void borrow_return_book::slot3() {
	QString ISBN = ui.isbn->text();
	Operate returnBook;
	if (returnBook.connect()) {
		if (returnBook.return_book(ISBN.toStdString())) {
			QMessageBox::information(NULL, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("还书操作成功!"), QMessageBox::Ok);
		}
		else {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("还书操作错误，请重试。"), QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("远程数据库连接错误，请重试。"), QMessageBox::Ok);
	}
}//还书
void borrow_return_book::slot4() {
	QString ISBN = QString::fromLocal8Bit(get_ISBN().c_str());
	ui.isbn->setText(ISBN);
}//opencv