#pragma once

#include <QWidget>
#include "ui_personal_change_name.h"

class personal_change_name : public QWidget
{
	Q_OBJECT

public:
	personal_change_name(QWidget *parent = Q_NULLPTR);
	~personal_change_name();

private:
	Ui::personal_change_name ui;
private slots:
	void slot1();//·µ»Ø
	void slot2();//ÐÞ¸ÄÃû×Ö
};
