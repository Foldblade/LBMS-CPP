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
}//����
void borrow_return_book::slot2() {
	QString ISBN = ui.isbn->text();
	Operate borrowBook;
	if (borrowBook.connect()) {
		if (borrowBook.borrow_book(ISBN.toStdString())) {
			QMessageBox::information(NULL, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit("��������ɹ���"), QMessageBox::Ok);
		}
		else {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("����������������ԡ�"), QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("Զ�����ݿ����Ӵ��������ԡ�"), QMessageBox::Ok);
	}
}//����
void borrow_return_book::slot3() {
	QString ISBN = ui.isbn->text();
	Operate returnBook;
	if (returnBook.connect()) {
		if (returnBook.return_book(ISBN.toStdString())) {
			QMessageBox::information(NULL, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit("��������ɹ�!"), QMessageBox::Ok);
		}
		else {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("����������������ԡ�"), QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("Զ�����ݿ����Ӵ��������ԡ�"), QMessageBox::Ok);
	}
}//����
void borrow_return_book::slot4() {
	QString ISBN = QString::fromLocal8Bit(get_ISBN().c_str());
	ui.isbn->setText(ISBN);
}//opencv