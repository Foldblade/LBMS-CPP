#include "QtGuiClass.h"
#include "QTextToSpeech"
#include "QMessageBox"
#include "qstring.h"
#include "json.h"


QtGuiClass::QtGuiClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QtGuiClass::~QtGuiClass()
{
}
void QtGuiClass::slot2() {
	QString name;
	QString code;
	Json config(".config.json"); // ��ȡJson�ļ� TODO: �ĳ�SQL��
	QString con_name = config.doc["user"].GetString(); // ��ȡ�û���
	QString con_passwd = config.doc["password"].GetString(); // ��ȡ����
	x = new adminitor_con;
	fa = new fail;
	name = ui.username->text();
	code = ui.usercode->text();
	if (name == con_name && code == con_passwd) {
		x->show();
		QTextToSpeech* tts = new QTextToSpeech(this);
		// tts->setLocale(QLocale::Chinese); // ��������
		// tts->setRate(-0.1);// ��������-1.0��1.0
		// tts->setPitch(1.0);// ��������-1.0��1.0
		// tts->setVolume(1.0);// ��������0.0-1.0
		if (tts->state() == QTextToSpeech::Ready)
		{
			tts->say(name);
			tts->say(QString::fromLocal8Bit("�߼���ʻԱ����·ǧ��������ȫ��һ�����г����淶�����������ᡣ"));
		}
		this->hide();
	}
	else {
		// Message box ��ʽ������� -by F.B.
		QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("�û�����������������ԡ�"), QMessageBox::Ok);
	}
}
void adminitor_con::slot1() {
	QtGuiClass *x = new QtGuiClass;
	x->show();
	this->hide();
}
