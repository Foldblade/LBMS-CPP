/********************************************************************************
** Form generated from reading UI file 'scan_input.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCAN_INPUT_H
#define UI_SCAN_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scan_input
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *openscan;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *isbn;
    QLineEdit *name;
    QLineEdit *writer;
    QLineEdit *press;
    QLineEdit *book_no;
    QPushButton *add;
    QPushButton *return_2;

    void setupUi(QWidget *scan_input)
    {
        if (scan_input->objectName().isEmpty())
            scan_input->setObjectName(QString::fromUtf8("scan_input"));
        scan_input->resize(723, 497);
        label = new QLabel(scan_input);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 50, 211, 41));
        label_2 = new QLabel(scan_input);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 110, 72, 15));
        openscan = new QPushButton(scan_input);
        openscan->setObjectName(QString::fromUtf8("openscan"));
        openscan->setGeometry(QRect(220, 100, 93, 28));
        label_3 = new QLabel(scan_input);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 150, 72, 15));
        label_4 = new QLabel(scan_input);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 190, 72, 15));
        label_5 = new QLabel(scan_input);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 230, 72, 15));
        label_6 = new QLabel(scan_input);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 270, 72, 15));
        label_7 = new QLabel(scan_input);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(120, 310, 72, 15));
        isbn = new QLineEdit(scan_input);
        isbn->setObjectName(QString::fromUtf8("isbn"));
        isbn->setGeometry(QRect(190, 150, 161, 21));
        name = new QLineEdit(scan_input);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(190, 190, 161, 21));
        writer = new QLineEdit(scan_input);
        writer->setObjectName(QString::fromUtf8("writer"));
        writer->setGeometry(QRect(190, 230, 161, 21));
        press = new QLineEdit(scan_input);
        press->setObjectName(QString::fromUtf8("press"));
        press->setGeometry(QRect(190, 270, 161, 21));
        book_no = new QLineEdit(scan_input);
        book_no->setObjectName(QString::fromUtf8("book_no"));
        book_no->setGeometry(QRect(190, 310, 161, 21));
        add = new QPushButton(scan_input);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(220, 350, 93, 28));
        return_2 = new QPushButton(scan_input);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(550, 400, 93, 28));

        retranslateUi(scan_input);
        QObject::connect(return_2, SIGNAL(clicked()), scan_input, SLOT(slot1()));
        QObject::connect(add, SIGNAL(clicked()), scan_input, SLOT(slot2()));
        QObject::connect(openscan, SIGNAL(clicked()), scan_input, SLOT(slot3()));

        QMetaObject::connectSlotsByName(scan_input);
    } // setupUi

    void retranslateUi(QWidget *scan_input)
    {
        scan_input->setWindowTitle(QApplication::translate("scan_input", "scan_input", nullptr));
        label->setText(QApplication::translate("scan_input", "LBMS \345\233\276\344\271\246\351\246\206\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\n"
"", nullptr));
        label_2->setText(QApplication::translate("scan_input", "\345\275\225\345\205\245\344\277\241\346\201\257\n"
"", nullptr));
        openscan->setText(QApplication::translate("scan_input", "\345\274\200\345\220\257\346\211\253\346\217\217\346\234\272", nullptr));
        label_3->setText(QApplication::translate("scan_input", "ISBN", nullptr));
        label_4->setText(QApplication::translate("scan_input", "\344\271\246\345\220\215", nullptr));
        label_5->setText(QApplication::translate("scan_input", "\344\275\234\350\200\205", nullptr));
        label_6->setText(QApplication::translate("scan_input", "\345\207\272\347\211\210\347\244\276", nullptr));
        label_7->setText(QApplication::translate("scan_input", "\344\271\246\345\217\267", nullptr));
        add->setText(QApplication::translate("scan_input", "\346\267\273\345\212\240", nullptr));
        return_2->setText(QApplication::translate("scan_input", "\350\277\224\345\233\236\347\256\241\347\220\206\344\270\255\345\277\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scan_input: public Ui_scan_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCAN_INPUT_H
