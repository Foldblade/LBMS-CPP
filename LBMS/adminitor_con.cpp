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
	Json config(".config.json"); // 读取Json文件 TODO: 改成SQL？
	string con_name = config.doc["user"].GetString();// 提取用户名
	string welcome = con_name + "，欢迎您！";
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
	QMessageBox message(QMessageBox::NoIcon, QString::fromLocal8Bit("关于"), 
		QString::fromLocal8Bit("<p>程序由F.B.与X.H.联合出品。</p><p>F.B.主要负责后端（扫码、数据库、配置文件等）、UI设计和前后端连接，<br />X.H.主要负责前端（Qt框架与GUI）。</p><p>程序<a href='https://github.com/Foldblade/LBMS-CPP'>在Github开源</a>。更多内容，请参阅ReadMe.md。</p>"));
	message.setIconPixmap(QPixmap("icon.png"));
	message.exec();
}
