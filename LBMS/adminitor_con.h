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
	void slot1();//返回登陆界面
	void slot2();//扫描录入
	void slot3();//个人中心
	void slot4();//书籍管理
	void slot5();//借阅管理
	void about();//关于
};
