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
	isbn = ui.isbn->text();//isbn号
	name = ui.name->text();//书名
	writer = ui.writer->text();//作者
	press = ui.press->text();//出版社
	many = ui.amount->text();//数量
	Operate uploadBook;
	if (isbn != "" && name != "" && writer != "" && press != "" && many != "") {
		if (uploadBook.connect()) {
			if (uploadBook.addBook(isbn.toStdString(), name.toStdString(), writer.toStdString(), press.toStdString(), many.toInt())) {
				QMessageBox::information(NULL, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("添加图书操作成功！"), QMessageBox::Ok);
			}
			else {
				QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("添加图书操作错误，请重试。"), QMessageBox::Ok);
			}
		}
		else {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("远程数据库连接错误，请重试。"), QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("请检查您没有输入的内容!"), QMessageBox::Ok);
	}

}//add
void scan_input::slot3() {
	QString ISBN = QString::fromLocal8Bit(get_ISBN().c_str());
	ui.isbn->setText(ISBN);
}//opencv