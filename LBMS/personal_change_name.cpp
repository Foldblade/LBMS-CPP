#include "personal_change_name.h"
#include "personal_cen.h"
#include <string>
#include "json.h"
#include "QMessageBox"

using namespace rapidjson;

personal_change_name::personal_change_name(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

personal_change_name::~personal_change_name()
{
}

void personal_change_name::slot1() {
	personal_cen* x = new personal_cen;
	x->show();
	this->hide();
}
void personal_change_name::slot2() {// 修改用户名确认
	/* This function was written by F.B. */
	string passwd = ui.passwd->text().toStdString();
	string username = ui.username->text().toStdString();
	Json config(".config.json"); // 读取Json文件
	string con_passwd = config.doc["password"].GetString(); // 提取密码
	if (con_passwd != passwd) { // 密码与记录不符
		QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("您输入的密码不正确。"), QMessageBox::Ok);
		// Message box 形式提出错误
	}
	else {
		config.strModify("user", username);
		config.update();
		config.SaveJson(".config.json");
		QMessageBox::information(NULL, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("用户名已更新，下次登录请用新用户名。"), QMessageBox::Ok);
		// Message box 形式给出成功
	}
}