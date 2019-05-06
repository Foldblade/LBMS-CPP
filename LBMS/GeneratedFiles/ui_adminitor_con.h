/********************************************************************************
** Form generated from reading UI file 'adminitor_con.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINITOR_CON_H
#define UI_ADMINITOR_CON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminitor_con
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *scan;
    QPushButton *bookcon;
    QPushButton *borrowecon;
    QPushButton *selfcen;
    QPushButton *return_2;

    void setupUi(QWidget *adminitor_con)
    {
        if (adminitor_con->objectName().isEmpty())
            adminitor_con->setObjectName(QString::fromUtf8("adminitor_con"));
        adminitor_con->resize(880, 537);
        label = new QLabel(adminitor_con);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 90, 141, 31));
        label_2 = new QLabel(adminitor_con);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 130, 72, 15));
        scan = new QPushButton(adminitor_con);
        scan->setObjectName(QString::fromUtf8("scan"));
        scan->setGeometry(QRect(170, 203, 93, 91));
        bookcon = new QPushButton(adminitor_con);
        bookcon->setObjectName(QString::fromUtf8("bookcon"));
        bookcon->setGeometry(QRect(310, 203, 93, 91));
        borrowecon = new QPushButton(adminitor_con);
        borrowecon->setObjectName(QString::fromUtf8("borrowecon"));
        borrowecon->setGeometry(QRect(450, 203, 93, 91));
        selfcen = new QPushButton(adminitor_con);
        selfcen->setObjectName(QString::fromUtf8("selfcen"));
        selfcen->setGeometry(QRect(580, 200, 93, 91));
        return_2 = new QPushButton(adminitor_con);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(580, 420, 93, 28));

        retranslateUi(adminitor_con);
        QObject::connect(return_2, SIGNAL(clicked()), adminitor_con, SLOT(slot1()));
        QObject::connect(scan, SIGNAL(clicked()), adminitor_con, SLOT(slot2()));
        QObject::connect(selfcen, SIGNAL(clicked()), adminitor_con, SLOT(slot3()));

        QMetaObject::connectSlotsByName(adminitor_con);
    } // setupUi

    void retranslateUi(QWidget *adminitor_con)
    {
        adminitor_con->setWindowTitle(QApplication::translate("adminitor_con", "adminitor_con", nullptr));
        label->setText(QApplication::translate("adminitor_con", "LBMS\345\233\276\344\271\246\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label_2->setText(QApplication::translate("adminitor_con", "\346\254\242\350\277\216\346\202\250\357\274\201", nullptr));
        scan->setText(QApplication::translate("adminitor_con", "\346\211\253\346\217\217\345\275\225\345\205\245", nullptr));
        bookcon->setText(QApplication::translate("adminitor_con", "\344\271\246\347\261\215\347\256\241\347\220\206", nullptr));
        borrowecon->setText(QApplication::translate("adminitor_con", "\345\200\237\351\230\205\347\256\241\347\220\206", nullptr));
        selfcen->setText(QApplication::translate("adminitor_con", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        return_2->setText(QApplication::translate("adminitor_con", "\350\277\224\345\233\236\347\231\273\351\231\206\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminitor_con: public Ui_adminitor_con {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINITOR_CON_H
