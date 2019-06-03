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
			QMessageBox::information(NULL, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit("����ͼ������ɹ���"), QMessageBox::Ok);
		}
		else {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("����������������ԡ�"), QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("Զ�����ݿ����Ӵ��������ԡ�"), QMessageBox::Ok);
	}
}//����
void edit_book::deleting() {
	/* Below works are modified by F.B. */
	QMessageBox::StandardButton rb = QMessageBox::question(NULL, QString::fromLocal8Bit("ɾ����"), QString::fromLocal8Bit("��ȷ��Ҫɾ��������¼ô��"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	if (rb == QMessageBox::Yes)
	{
		int id;
		id = ID.toInt();
		Operate dele;
		if (dele.connect()) {
			if (dele.delBook(id)) {
				QMessageBox::information(NULL, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit("ɾ��ͼ������ɹ���"), QMessageBox::Ok);
				search_book_man* x = new search_book_man;
				x->show();
				this->hide();
			}
			else {
				QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("ɾ���������������ԡ�"), QMessageBox::Ok);
			}
		}
		else {
			QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("Զ�����ݿ����Ӵ��������ԡ�"), QMessageBox::Ok);
		}
	}
	
}//ɾ��
void edit_book::back() {
	search_book_man* x = new search_book_man;
	x->show();
	this->hide();
}//����

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