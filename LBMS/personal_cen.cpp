#include "personal_cen.h"
#include "personal_change_password.h"
#include "personal_change_name.h"
#include "adminitor_con.h"

using namespace std;

personal_cen::personal_cen(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

personal_cen::~personal_cen()
{
}

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

