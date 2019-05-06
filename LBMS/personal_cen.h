#pragma once

#include <QWidget>
#include "ui_personal_cen.h"

class personal_cen : public QWidget
{
	Q_OBJECT

public:
	personal_cen(QWidget *parent = Q_NULLPTR);
	~personal_cen();

private:
	Ui::personal_cen ui;
private slots:
	void slot1();
	void slot2();
	void slot3();
};
