#include "personal_cen.h"
#include "personal_change_password.h"
#include "success.h"
#include "personal_change_name.h"
#include "QMessageBox"
#include <string>
#include "json.h"

using namespace rapidjson;
using namespace std;

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
void personal_change_password::slot2() {// �޸�����ȷ��
	/* This function was written by F.B. */
	string oldPasswd = ui.oldPasswd->text().toStdString();
	string newPasswd = ui.newPasswd->text().toStdString();
	string configNewPasswd = ui.configNewPasswd->text().toStdString();
	Json config(".config.json"); // ��ȡJson�ļ�
	string con_passwd = config.doc["password"].GetString(); // ��ȡ����
	if (con_passwd != oldPasswd) { // ���������¼����
		QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("������ľ����벻��ȷ��"), QMessageBox::Ok);
		// Message box ��ʽ�������
	}
	else {
		if (configNewPasswd != newPasswd) {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("��������������벻һ�¡�"), QMessageBox::Ok);
			// Message box ��ʽ�������
		}
		else {
			config.strModify("password", newPasswd);
			config.update();
			config.SaveJson(".config.json");
			QMessageBox::information(NULL, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit("�����Ѹ��£��´ε�¼���������롣"), QMessageBox::Ok);
			// Message box ��ʽ�����ɹ�
		}
	}
}
void personal_change_name::slot1() {
	personal_cen* x = new personal_cen;
	x->show();
	this->hide();
}
void personal_change_name::slot2() {// �޸��û���ȷ��
	/* This function was written by F.B. */
	string passwd = ui.passwd->text().toStdString();
	string username = ui.username->text().toStdString();
	Json config(".config.json"); // ��ȡJson�ļ�
	string con_passwd = config.doc["password"].GetString(); // ��ȡ����
	if (con_passwd != passwd) { // �������¼����
		QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("����������벻��ȷ��"), QMessageBox::Ok);
		// Message box ��ʽ�������
	}
	else {
		config.strModify("user", username);
		config.update();
		config.SaveJson(".config.json");
		QMessageBox::information(NULL, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit("�û����Ѹ��£��´ε�¼�������û�����"), QMessageBox::Ok);
		// Message box ��ʽ�����ɹ�
	}
}

