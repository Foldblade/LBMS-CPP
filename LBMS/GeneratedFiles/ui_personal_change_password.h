/********************************************************************************
** Form generated from reading UI file 'personal_change_password.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONAL_CHANGE_PASSWORD_H
#define UI_PERSONAL_CHANGE_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_personal_change_password
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *change_sure;
    QPushButton *return_2;

    void setupUi(QWidget *personal_change_password)
    {
        if (personal_change_password->objectName().isEmpty())
            personal_change_password->setObjectName(QString::fromUtf8("personal_change_password"));
        personal_change_password->resize(400, 300);
        label = new QLabel(personal_change_password);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 191, 61));
        label_2 = new QLabel(personal_change_password);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 70, 171, 31));
        label_3 = new QLabel(personal_change_password);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 110, 72, 15));
        label_4 = new QLabel(personal_change_password);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 150, 72, 15));
        label_5 = new QLabel(personal_change_password);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 190, 91, 16));
        lineEdit = new QLineEdit(personal_change_password);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 110, 113, 21));
        lineEdit_2 = new QLineEdit(personal_change_password);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 150, 113, 21));
        lineEdit_3 = new QLineEdit(personal_change_password);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 190, 113, 21));
        change_sure = new QPushButton(personal_change_password);
        change_sure->setObjectName(QString::fromUtf8("change_sure"));
        change_sure->setGeometry(QRect(150, 240, 93, 28));
        return_2 = new QPushButton(personal_change_password);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(290, 240, 93, 28));

        retranslateUi(personal_change_password);
        QObject::connect(return_2, SIGNAL(clicked()), personal_change_password, SLOT(slot1()));
        QObject::connect(change_sure, SIGNAL(clicked()), personal_change_password, SLOT(slot2()));

        QMetaObject::connectSlotsByName(personal_change_password);
    } // setupUi

    void retranslateUi(QWidget *personal_change_password)
    {
        personal_change_password->setWindowTitle(QApplication::translate("personal_change_password", "personal_change_password", nullptr));
        label->setText(QApplication::translate("personal_change_password", "LBMS \345\233\276\344\271\246\351\246\206\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\n"
"", nullptr));
        label_2->setText(QApplication::translate("personal_change_password", "\344\270\252\344\272\272\344\270\255\345\277\203-\344\277\256\346\224\271\345\257\206\347\240\201\n"
"", nullptr));
        label_3->setText(QApplication::translate("personal_change_password", "\346\227\247\345\257\206\347\240\201\357\274\232\n"
"", nullptr));
        label_4->setText(QApplication::translate("personal_change_password", "\346\226\260\345\257\206\347\240\201\357\274\232\n"
"", nullptr));
        label_5->setText(QApplication::translate("personal_change_password", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        change_sure->setText(QApplication::translate("personal_change_password", "\347\241\256\350\256\244", nullptr));
        return_2->setText(QApplication::translate("personal_change_password", "\350\277\224\345\233\236\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class personal_change_password: public Ui_personal_change_password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONAL_CHANGE_PASSWORD_H
