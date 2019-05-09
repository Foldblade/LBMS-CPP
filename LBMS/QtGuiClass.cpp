#include "QtGuiClass.h"
#include "qstring.h"
#include "json.h"

QtGuiClass::QtGuiClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QtGuiClass::~QtGuiClass()
{
}
void QtGuiClass::slot2() {
	QString name;
	QString code;
	Json config(".config.json"); // 读取Json文件 TODO: 改成SQL？
	QString con_name = config.doc["user"].GetString(); // 提取用户名
	QString con_passwd = config.doc["password"].GetString(); // 提取密码
	x = new adminitor_con;
	fa = new fail;
	name = ui.username->text();
	code = ui.usercode->text();
	if (name == con_name && code == con_passwd) {
		x->show();
		this->hide();
	}
	else {
		fa->show();
	}
}
void adminitor_con::slot1() {
	QtGuiClass *x = new QtGuiClass;
	x->show();
	this->hide();
}
