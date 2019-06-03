#include "edit_book.h"
#include "search_book_man.h"
#include "domysql.h"
#include "QMessageBox"

QString isbn, title, writer, publisher, many, inside, outside, ID;

edit_book::edit_book(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

edit_book::~edit_book()
{
}

void edit_book::go() {
	/* Below works are modified by F.B. */
	ui.isbn->setText(isbn);
	ui.book_name->setText(title);
	ui.writer->setText(writer);
	ui.publishing_house->setText(publisher);
	ui.amount->setText(many);
	ui.inside->setText(inside);
	ui.outside->setText(outside);
}

void edit_book::saving() {
	/* Below works are modified by F.B. */
	QByteArray isbn, title, writer, publisher;
	isbn = ui.isbn->text().toLocal8Bit();
	title = ui.book_name->text().toLocal8Bit();
	writer = ui.writer->text().toLocal8Bit();
	publisher = ui.publishing_house->text().toLocal8Bit();
	int many, inside, outside, id;
	many = ui.amount->text().toInt();
	inside = ui.inside->text().toInt();
	outside = ui.outside->text().toInt();
	id = ID.toInt();
	Operate save;
	if (save.connect()) {
		if (save.updateBook(string(isbn), string(title), string(writer), string(publisher), many, inside, outside, id)) {
			QMessageBox::information(NULL, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("保存图书操作成功！"), QMessageBox::Ok);
		}
		else {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("保存操作错误，请重试。"), QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("远程数据库连接错误，请重试。"), QMessageBox::Ok);
	}
}//保存
void edit_book::deleting() {
	/* Below works are modified by F.B. */
	QMessageBox::StandardButton rb = QMessageBox::question(NULL, QString::fromLocal8Bit("删除？"), QString::fromLocal8Bit("你确定要删除这条记录么？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	if (rb == QMessageBox::Yes)
	{
		int id;
		id = ID.toInt();
		Operate dele;
		if (dele.connect()) {
			if (dele.delBook(id)) {
				QMessageBox::information(NULL, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("删除图书操作成功！"), QMessageBox::Ok);
				search_book_man* x = new search_book_man;
				x->show();
				this->hide();
			}
			else {
				QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("删除操作错误，请重试。"), QMessageBox::Ok);
			}
		}
		else {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("远程数据库连接错误，请重试。"), QMessageBox::Ok);
		}
	}
	
}//删除
void edit_book::back() {
	search_book_man* x = new search_book_man;
	x->show();
	this->hide();
}//返回

void edit_book::receive_book_data(QString isbn, QString title, QString writer, QString publisher, QString many, QString inside, QString outside, QString ID) {
	/* Below works are modified by F.B. */
	::isbn = isbn;
	::title = title;
	::writer = writer;
	::publisher = publisher;
	::many = many;
	::inside = inside;
	::outside = outside;
	::ID = ID;
}