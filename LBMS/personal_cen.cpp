#include "personal_cen.h"
#include "personal_change_password.h"
#include "success.h"
#include "personal_change_name.h"
personal_cen::personal_cen(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

personal_cen::~personal_cen()
{
}
void personal_change_password::slot1() {
	personal_cen* x = new personal_cen;
	x->show();
	this->hide();
}
void personal_change_password::slot2() {
	success* x = new success;
	x->show();
}
void personal_change_name::slot1() {
	personal_cen* x = new personal_cen;
	x->show();
	this->hide();
}
void personal_change_name::slot2() {
	success* x = new success;
	x->show();
}

