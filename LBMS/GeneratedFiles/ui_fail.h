/********************************************************************************
** Form generated from reading UI file 'fail.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAIL_H
#define UI_FAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fail
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *fail)
    {
        if (fail->objectName().isEmpty())
            fail->setObjectName(QString::fromUtf8("fail"));
        fail->resize(223, 46);
        textBrowser = new QTextBrowser(fail);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 10, 221, 31));

        retranslateUi(fail);

        QMetaObject::connectSlotsByName(fail);
    } // setupUi

    void retranslateUi(QWidget *fail)
    {
        fail->setWindowTitle(QApplication::translate("fail", "fail", nullptr));
        textBrowser->setHtml(QApplication::translate("fail", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\257\206\347\240\201\351\224\231\350\257\257\346\210\226\347\224\250\346\210\267\345\220\215\344\270\215\345\255\230\345\234\250\350\257\267\351\207\215\350\257\225</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fail: public Ui_fail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAIL_H
