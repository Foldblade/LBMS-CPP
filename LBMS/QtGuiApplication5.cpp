#include "QtGuiApplication5.h"

QtGuiApplication5::QtGuiApplication5(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}
QtGuiApplication5::~QtGuiApplication5() {

}
void QtGuiApplication5::slot1() {
	x = new QtGuiClass;
	x->show();
	this->hide();
}
void QtGuiApplication5::slot2() {
	x1 = new search_book;
	x1->show();
	this->hide();
}
void QtGuiClass::slot1() {
	QtGuiApplication5* y = new QtGuiApplication5;
	y->show();
	this->hide();
}
void search_book::slot1() {
	QtGuiApplication5* y1 = new QtGuiApplication5;
	y1->show();
	this->hide();
}