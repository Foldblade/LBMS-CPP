/********************************************************************************
** Form generated from reading UI file 'personal_cen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONAL_CEN_H
#define UI_PERSONAL_CEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_personal_cen
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *change_password;
    QPushButton *change_name;
    QPushButton *return_2;

    void setupUi(QWidget *personal_cen)
    {
        if (personal_cen->objectName().isEmpty())
            personal_cen->setObjectName(QString::fromUtf8("personal_cen"));
        personal_cen->resize(400, 300);
        label = new QLabel(personal_cen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 191, 51));
        label_2 = new QLabel(personal_cen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 72, 15));
        change_password = new QPushButton(personal_cen);
        change_password->setObjectName(QString::fromUtf8("change_password"));
        change_password->setGeometry(QRect(60, 110, 93, 101));
        change_name = new QPushButton(personal_cen);
        change_name->setObjectName(QString::fromUtf8("change_name"));
        change_name->setGeometry(QRect(210, 117, 93, 91));
        return_2 = new QPushButton(personal_cen);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(290, 250, 93, 28));

        retranslateUi(personal_cen);
        QObject::connect(return_2, SIGNAL(clicked()), personal_cen, SLOT(slot1()));
        QObject::connect(change_password, SIGNAL(clicked()), personal_cen, SLOT(slot2()));
        QObject::connect(change_name, SIGNAL(clicked()), personal_cen, SLOT(slot3()));

        QMetaObject::connectSlotsByName(personal_cen);
    } // setupUi

    void retranslateUi(QWidget *personal_cen)
    {
        personal_cen->setWindowTitle(QApplication::translate("personal_cen", "personal_cen", nullptr));
        label->setText(QApplication::translate("personal_cen", "LBMS \345\233\276\344\271\246\351\246\206\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\n"
"", nullptr));
        label_2->setText(QApplication::translate("personal_cen", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        change_password->setText(QApplication::translate("personal_cen", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        change_name->setText(QApplication::translate("personal_cen", "\344\277\256\346\224\271\347\224\250\346\210\267\345\220\215", nullptr));
        return_2->setText(QApplication::translate("personal_cen", "\350\277\224\345\233\236\347\256\241\347\220\206\344\270\255\345\277\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class personal_cen: public Ui_personal_cen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONAL_CEN_H
