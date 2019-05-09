/********************************************************************************
** Form generated from reading UI file 'borrow_return_book.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROW_RETURN_BOOK_H
#define UI_BORROW_RETURN_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_borrow_return_book
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *opencv;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *isbn;
    QLineEdit *book_name;
    QLineEdit *writer;
    QLineEdit *publishing_house;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QPushButton *borrow;
    QPushButton *return_book;
    QPushButton *return_2;

    void setupUi(QWidget *borrow_return_book)
    {
        if (borrow_return_book->objectName().isEmpty())
            borrow_return_book->setObjectName(QString::fromUtf8("borrow_return_book"));
        borrow_return_book->resize(400, 300);
        label = new QLabel(borrow_return_book);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 181, 61));
        label_2 = new QLabel(borrow_return_book);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 70, 72, 15));
        opencv = new QPushButton(borrow_return_book);
        opencv->setObjectName(QString::fromUtf8("opencv"));
        opencv->setGeometry(QRect(130, 60, 93, 28));
        label_3 = new QLabel(borrow_return_book);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 100, 72, 15));
        label_4 = new QLabel(borrow_return_book);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 130, 72, 15));
        label_5 = new QLabel(borrow_return_book);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 160, 72, 15));
        label_6 = new QLabel(borrow_return_book);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 190, 72, 15));
        isbn = new QLineEdit(borrow_return_book);
        isbn->setObjectName(QString::fromUtf8("isbn"));
        isbn->setGeometry(QRect(110, 100, 151, 21));
        book_name = new QLineEdit(borrow_return_book);
        book_name->setObjectName(QString::fromUtf8("book_name"));
        book_name->setGeometry(QRect(110, 130, 151, 21));
        writer = new QLineEdit(borrow_return_book);
        writer->setObjectName(QString::fromUtf8("writer"));
        writer->setGeometry(QRect(110, 160, 151, 21));
        publishing_house = new QLineEdit(borrow_return_book);
        publishing_house->setObjectName(QString::fromUtf8("publishing_house"));
        publishing_house->setGeometry(QRect(110, 190, 151, 21));
        label_7 = new QLabel(borrow_return_book);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 220, 72, 15));
        lineEdit = new QLineEdit(borrow_return_book);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 220, 151, 21));
        borrow = new QPushButton(borrow_return_book);
        borrow->setObjectName(QString::fromUtf8("borrow"));
        borrow->setGeometry(QRect(60, 260, 93, 28));
        return_book = new QPushButton(borrow_return_book);
        return_book->setObjectName(QString::fromUtf8("return_book"));
        return_book->setGeometry(QRect(190, 260, 93, 28));
        return_2 = new QPushButton(borrow_return_book);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(290, 230, 101, 28));

        retranslateUi(borrow_return_book);
        QObject::connect(return_2, SIGNAL(clicked()), borrow_return_book, SLOT(slot1()));
        QObject::connect(borrow, SIGNAL(clicked()), borrow_return_book, SLOT(slot2()));
        QObject::connect(return_book, SIGNAL(clicked()), borrow_return_book, SLOT(slot3()));
        QObject::connect(opencv, SIGNAL(clicked()), borrow_return_book, SLOT(slot4()));

        QMetaObject::connectSlotsByName(borrow_return_book);
    } // setupUi

    void retranslateUi(QWidget *borrow_return_book)
    {
        borrow_return_book->setWindowTitle(QApplication::translate("borrow_return_book", "borrow_return_book", nullptr));
        label->setText(QApplication::translate("borrow_return_book", "LBMS \345\233\276\344\271\246\351\246\206\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\n"
"", nullptr));
        label_2->setText(QApplication::translate("borrow_return_book", "\345\275\225\345\205\245\344\277\241\346\201\257\357\274\232", nullptr));
        opencv->setText(QApplication::translate("borrow_return_book", "\345\274\200\345\220\257\346\211\253\347\240\201\346\234\272", nullptr));
        label_3->setText(QApplication::translate("borrow_return_book", "ISBN :", nullptr));
        label_4->setText(QApplication::translate("borrow_return_book", "\344\271\246\345\220\215 \357\274\232", nullptr));
        label_5->setText(QApplication::translate("borrow_return_book", "\344\275\234\350\200\205 \357\274\232", nullptr));
        label_6->setText(QApplication::translate("borrow_return_book", "\345\207\272\347\211\210\347\244\276\357\274\232", nullptr));
        writer->setText(QString());
        label_7->setText(QApplication::translate("borrow_return_book", "\344\271\246\345\217\267\357\274\232", nullptr));
        borrow->setText(QApplication::translate("borrow_return_book", "\345\200\237\344\271\246", nullptr));
        return_book->setText(QApplication::translate("borrow_return_book", "\350\277\230\344\271\246", nullptr));
        return_2->setText(QApplication::translate("borrow_return_book", "\345\233\236\345\210\260\347\256\241\347\220\206\344\270\255\345\277\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class borrow_return_book: public Ui_borrow_return_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROW_RETURN_BOOK_H
