#include "adminitor_con.h"
#include "scan_input.h"
#include "qstring.h"
#include "personal_cen.h"
#include "search_book_man.h"
#include "borrow_return_book.h"
#include "json.h"
#include "qmessagebox.h"


using namespace std;

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
	message.setIconPixmap(QPixmap("icon.png"));
	message.exec();
}
