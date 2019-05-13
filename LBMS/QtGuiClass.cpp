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
	Json config(".config.json"); // 读取Json文件 TODO: 改成SQL？
	QString con_name = config.doc["user"].GetString(); // 提取用户名
	QString con_passwd = config.doc["password"].GetString(); // 提取密码
	x = new adminitor_con;
	fa = new fail;
	name = ui.username->text();
	code = ui.usercode->text();
	if (name == con_name && code == con_passwd) {
		x->show();
		QTextToSpeech* tts = new QTextToSpeech(this);
		// tts->setLocale(QLocale::Chinese); // 设置语言
		// tts->setRate(-0.1);// 设置语速-1.0到1.0
		// tts->setPitch(1.0);// 设置音高-1.0到1.0
		// tts->setVolume(1.0);// 设置音量0.0-1.0
		if (tts->state() == QTextToSpeech::Ready)
		{
			tts->say(name);
			tts->say(QString::fromLocal8Bit("高级驾驶员。道路千万条，安全第一条，行车不规范，亲人两行泪。"));
		}
		this->hide();
	}
	else {
		// Message box 形式提出错误 -by F.B.
		QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("用户名或密码错误，请重试。"), QMessageBox::Ok);
	}
}
void adminitor_con::slot1() {
	QtGuiClass *x = new QtGuiClass;
	x->show();
	this->hide();
}
