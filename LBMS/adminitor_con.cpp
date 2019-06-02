#include "adminitor_con.h"
#include "scan_input.h"
#include "success.h"
#include "qstring.h"
#include "scanner.h"
#include "personal_cen.h"
#include "search_book_man.h"
#include "search_book_result_man.h"
#include "personal_change_password.h"
#include "personal_change_name.h"
#include "borrow_return_book.h"
#include "domysql.h"

using namespace std;
using namespace sql;
using namespace boost;

adminitor_con::adminitor_con(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Json config(".config.json"); // ��ȡJson�ļ� TODO: �ĳ�SQL��
	string con_name = config.doc["user"].GetString();// ��ȡ�û���
	string welcome = con_name + "����ӭ����";
	ui.welcome->setText(QString::fromLocal8Bit(welcome.data()));
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
void adminitor_con::about() {
	QMessageBox message(QMessageBox::NoIcon, QString::fromLocal8Bit("����"), 
		QString::fromLocal8Bit("<p>������F.B.��X.H.���ϳ�Ʒ��</p><p>F.B.��Ҫ�����ˣ�ɨ�롢���ݿ⡢�����ļ��ȣ���UI��ƺ�ǰ������ӣ�<br />X.H.��Ҫ����ǰ�ˣ�Qt�����GUI����</p><p>����<a href='https://github.com/Foldblade/LBMS-CPP'>��Github��Դ</a>���������ݣ������ReadMe.md��</p>"));
	// message.setIconPixmap(QPixmap("icon.png"));
	message.exec();
}
void scan_input::slot1() {
	adminitor_con* x = new adminitor_con;
	x->show();
	this->hide();
}//return 
void scan_input::slot2() {
	QString isbn, name, writer, press, book_no;
	isbn = ui.isbn->text();//isbn��
	name = ui.name->text();//����
	writer = ui.writer->text();//����
	press = ui.press->text();//������
	success* x = new success;
	x->show();
}//add
void scan_input::slot3() {
	QString ISBN = QString::fromLocal8Bit(get_ISBN().c_str());
	ui.isbn->setText(ISBN);
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

void borrow_return_book::slot1() {
	adminitor_con* x = new adminitor_con;
	x->show();
	this->hide();
}//����
void borrow_return_book::slot2() {
	success* x = new success;
	x->show();
}//����
void borrow_return_book::slot3() {
	success* x = new success;
	x->show();
}//����
void borrow_return_book::slot4() {
	QString ISBN = QString::fromLocal8Bit(get_ISBN().c_str());
	ui.isbn->setText(ISBN);
}//opencv

