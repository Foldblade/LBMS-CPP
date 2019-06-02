#include "scan_input.h"
#include <string>
#include "qstring.h"
#include "domysql.h"
#include "adminitor_con.h"
#include "qmessagebox.h"
#include "scanner.h"

using namespace sql;
using namespace boost;
using namespace std;

scan_input::scan_input(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

scan_input::~scan_input()
{
}

void scan_input::slot1() {
	adminitor_con* x = new adminitor_con;
	x->show();
	this->hide();
}//return

void scan_input::slot2() {
	QString isbn, name, writer, press, many;
	isbn = ui.isbn->text();//isbn��
	name = ui.name->text();//����
	writer = ui.writer->text();//����
	press = ui.press->text();//������
	many = ui.amount->text();//����
	Operate uploadBook;
	if (isbn != "" && name != "" && writer != "" && press != "" && many != "") {
		if (uploadBook.connect()) {
			if (uploadBook.addBook(isbn.toStdString(), name.toStdString(), writer.toStdString(), press.toStdString(), many.toInt())) {
				QMessageBox::information(NULL, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit("���ͼ������ɹ���"), QMessageBox::Ok);
			}
			else {
				QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("���ͼ��������������ԡ�"), QMessageBox::Ok);
			}
		}
		else {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("Զ�����ݿ����Ӵ��������ԡ�"), QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("������û�����������!"), QMessageBox::Ok);
	}

}//add
void scan_input::slot3() {
	QString ISBN = QString::fromLocal8Bit(get_ISBN().c_str());
	ui.isbn->setText(ISBN);
}//opencv