#include "QtGuiClass.h"
#include "qstring.h"
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
	x = new adminitor_con;
	fa = new fail;
	name = ui.username->text();
	code = ui.usercode->text();
	if (name == "bjmx" && code == "111") {
		x->show();
		this->hide();
	}
	else if (name == "fb" && code == "123") {
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
