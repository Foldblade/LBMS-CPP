#include "QtGuiClass.h"
#include "QMessageBox"
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
	Json config(".config.json"); // ��ȡJson�ļ� TODO: �ĳ�SQL��
	QString con_name = config.doc["user"].GetString(); // ��ȡ�û���
	QString con_passwd = config.doc["password"].GetString(); // ��ȡ����
	x = new adminitor_con;
	fa = new fail;
	name = ui.username->text();
	code = ui.usercode->text();
	if (name == con_name && code == con_passwd) {
		x->show();
		this->hide();
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("�û�����������������ԡ�"), QMessageBox::Ok);
	}
}
void adminitor_con::slot1() {
	QtGuiClass *x = new QtGuiClass;
	x->show();
	this->hide();
}
