#pragma once
#ifndef QTGUICLASS_H
#define QTGUICLASS_H

#include <QWidget>
#include "ui_QtGuiClass.h"
#include "adminitor_con.h"
#include "fail.h"

class QtGuiClass : public QWidget
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();
	adminitor_con* x;//Ϊ�˽�ʡ����һ�У�����û����ע��
	fail* fa;//Ϊ�˽�ʡ����һ�У�����û����ע��
private:
	Ui::QtGuiClass ui;

private slots:
	void slot1();//���ص�½����
	void slot2();//��½
};
#endif // !QTGUICLASS
