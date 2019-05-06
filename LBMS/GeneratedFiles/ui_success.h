/********************************************************************************
** Form generated from reading UI file 'success.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESS_H
#define UI_SUCCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_success
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *success)
    {
        if (success->objectName().isEmpty())
            success->setObjectName(QString::fromUtf8("success"));
        success->resize(116, 51);
        textBrowser = new QTextBrowser(success);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(-80, 0, 256, 192));

        retranslateUi(success);

        QMetaObject::connectSlotsByName(success);
    } // setupUi

    void retranslateUi(QWidget *success)
    {
        success->setWindowTitle(QApplication::translate("success", "success", nullptr));
        textBrowser->setHtml(QApplication::translate("success", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">\346\210\220\345\212\237</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class success: public Ui_success {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESS_H
