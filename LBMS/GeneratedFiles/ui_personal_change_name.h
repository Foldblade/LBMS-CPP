/********************************************************************************
** Form generated from reading UI file 'personal_change_name.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONAL_CHANGE_NAME_H
#define UI_PERSONAL_CHANGE_NAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_personal_change_name
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *change_sure;
    QPushButton *return_2;

    void setupUi(QWidget *personal_change_name)
    {
        if (personal_change_name->objectName().isEmpty())
            personal_change_name->setObjectName(QString::fromUtf8("personal_change_name"));
        personal_change_name->resize(400, 300);
        label = new QLabel(personal_change_name);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 191, 51));
        label_2 = new QLabel(personal_change_name);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 80, 171, 31));
        label_3 = new QLabel(personal_change_name);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 110, 72, 15));
        label_4 = new QLabel(personal_change_name);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 150, 72, 15));
        lineEdit = new QLineEdit(personal_change_name);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 110, 113, 21));
        lineEdit_2 = new QLineEdit(personal_change_name);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 150, 113, 21));
        change_sure = new QPushButton(personal_change_name);
        change_sure->setObjectName(QString::fromUtf8("change_sure"));
        change_sure->setGeometry(QRect(120, 200, 93, 28));
        return_2 = new QPushButton(personal_change_name);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(290, 240, 93, 28));

        retranslateUi(personal_change_name);
        QObject::connect(return_2, SIGNAL(clicked()), personal_change_name, SLOT(slot1()));
        QObject::connect(change_sure, SIGNAL(clicked()), personal_change_name, SLOT(slot2()));

        QMetaObject::connectSlotsByName(personal_change_name);
    } // setupUi

    void retranslateUi(QWidget *personal_change_name)
    {
        personal_change_name->setWindowTitle(QApplication::translate("personal_change_name", "personal_change_name", nullptr));
        label->setText(QApplication::translate("personal_change_name", "LBMS \345\233\276\344\271\246\351\246\206\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\n"
"", nullptr));
        label_2->setText(QApplication::translate("personal_change_name", "\344\270\252\344\272\272\344\270\255\345\277\203-\344\277\256\346\224\271\347\224\250\346\210\267\345\220\215\n"
"", nullptr));
        label_3->setText(QApplication::translate("personal_change_name", "\345\257\206\347\240\201\357\274\232\n"
"", nullptr));
        label_4->setText(QApplication::translate("personal_change_name", "\347\224\250\346\210\267\345\220\215\357\274\232\n"
"", nullptr));
        change_sure->setText(QApplication::translate("personal_change_name", "\347\241\256\350\256\244", nullptr));
        return_2->setText(QApplication::translate("personal_change_name", "\350\277\224\345\233\236\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class personal_change_name: public Ui_personal_change_name {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONAL_CHANGE_NAME_H
