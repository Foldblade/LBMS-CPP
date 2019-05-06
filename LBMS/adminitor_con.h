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
	void slot1();
	void slot2();
	void slot3();//personal_cen
};
