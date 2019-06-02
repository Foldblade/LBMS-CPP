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