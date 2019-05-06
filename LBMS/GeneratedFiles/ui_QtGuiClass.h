/********************************************************************************
** Form generated from reading UI file 'QtGuiClass.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUICLASS_H
#define UI_QTGUICLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *quit;
    QPushButton *return_2;
    QLineEdit *username;
    QLineEdit *usercode;
    QLabel *label_4;
    QPushButton *enter;

    void setupUi(QWidget *QtGuiClass)
    {
        if (QtGuiClass->objectName().isEmpty())
            QtGuiClass->setObjectName(QString::fromUtf8("QtGuiClass"));
        QtGuiClass->resize(400, 359);
        label = new QLabel(QtGuiClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 80, 72, 15));
        label_2 = new QLabel(QtGuiClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 110, 72, 15));
        label_3 = new QLabel(QtGuiClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 170, 72, 15));
        quit = new QPushButton(QtGuiClass);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(280, 260, 93, 28));
        return_2 = new QPushButton(QtGuiClass);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(280, 230, 93, 28));
        username = new QLineEdit(QtGuiClass);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(130, 110, 141, 21));
        usercode = new QLineEdit(QtGuiClass);
        usercode->setObjectName(QString::fromUtf8("usercode"));
        usercode->setGeometry(QRect(130, 170, 141, 21));
        label_4 = new QLabel(QtGuiClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 50, 141, 21));
        enter = new QPushButton(QtGuiClass);
        enter->setObjectName(QString::fromUtf8("enter"));
        enter->setGeometry(QRect(150, 210, 93, 28));

        retranslateUi(QtGuiClass);
        QObject::connect(quit, SIGNAL(clicked()), QtGuiClass, SLOT(close()));
        QObject::connect(return_2, SIGNAL(clicked()), QtGuiClass, SLOT(slot1()));
        QObject::connect(enter, SIGNAL(clicked()), QtGuiClass, SLOT(slot2()));

        QMetaObject::connectSlotsByName(QtGuiClass);
    } // setupUi

    void retranslateUi(QWidget *QtGuiClass)
    {
        QtGuiClass->setWindowTitle(QApplication::translate("QtGuiClass", "QtGuiClass", nullptr));
        label->setText(QApplication::translate("QtGuiClass", "\347\231\273\351\231\206", nullptr));
        label_2->setText(QApplication::translate("QtGuiClass", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("QtGuiClass", "\345\257\206\347\240\201\357\274\232", nullptr));
        quit->setText(QApplication::translate("QtGuiClass", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        return_2->setText(QApplication::translate("QtGuiClass", "\345\233\236\345\210\260\345\212\237\350\203\275\351\241\265", nullptr));
        label_4->setText(QApplication::translate("QtGuiClass", "LBMS\345\233\276\344\271\246\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        enter->setText(QApplication::translate("QtGuiClass", "\347\231\273\351\231\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiClass: public Ui_QtGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUICLASS_H
