#include "personal_change_password.h"
#include "personal_cen.h"
#include <string>
#include "json.h"
#include "QMessageBox"

using namespace rapidjson;

personal_change_password::personal_change_password(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

personal_change_password::~personal_change_password()
{
}

void personal_change_password::slot1() {
	personal_cen* x = new personal_cen;
	x->show();
	this->hide();
}
void personal_change_password::slot2() {// 修改密码确认
	/* This function was written by F.B. */
	string oldPasswd = ui.oldPasswd->text().toStdString();
	string newPasswd = ui.newPasswd->text().toStdString();
	string configNewPasswd = ui.configNewPasswd->text().toStdString();
	Json config(".config.json"); // 读取Json文件
	string con_passwd = config.doc["password"].GetString(); // 提取密码
	if (con_passwd != oldPasswd) { // 旧密码与记录不符
		QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("您输入的旧密码不正确。"), QMessageBox::Ok);
		// Message box 形式提出错误
	}
	else {
		if (configNewPasswd != newPasswd) {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("两次输入的新密码不一致。"), QMessageBox::Ok);
			// Message box 形式提出错误
		}
		else {
			config.strModify("password", newPasswd);
			config.update();
			config.SaveJson(".config.json");
			QMessageBox::information(NULL, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("密码已更新，下次登录请用新密码。"), QMessageBox::Ok);
			// Message box 形式给出成功
		}
	}
}