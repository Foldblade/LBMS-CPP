#pragma once

#include <QWidget>
#include "ui_adminitor_con.h"

class adminitor_con : public QWidget
{
	Q_OBJECT

public:
	adminitor_con(QWidget *parent = Q_NULLPTR);
	~adminitor_con();

private:
	Ui::adminitor_con ui;
private slots:
	void slot1();//���ص�½����
	void slot2();//ɨ��¼��
	void slot3();//��������
	void slot4();//�鼮����
	void slot5();//���Ĺ���
	void about();//����
};
