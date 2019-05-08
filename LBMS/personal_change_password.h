#pragma once

#include <QWidget>
#include "ui_personal_change_password.h"

class personal_change_password : public QWidget
{
	Q_OBJECT

public:
	personal_change_password(QWidget *parent = Q_NULLPTR);
	~personal_change_password();

private:
	Ui::personal_change_password ui;
private slots:
	void slot1();
	void slot2();
};
