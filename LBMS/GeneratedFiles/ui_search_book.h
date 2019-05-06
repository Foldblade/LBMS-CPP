/********************************************************************************
** Form generated from reading UI file 'search_book.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_BOOK_H
#define UI_SEARCH_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_search_book
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *research;
    QPushButton *return_2;
    QPushButton *quit;
    QLineEdit *isbn;
    QLineEdit *book_name;
    QLineEdit *writer;
    QLineEdit *publishing_house;

    void setupUi(QWidget *search_book)
    {
        if (search_book->objectName().isEmpty())
            search_book->setObjectName(QString::fromUtf8("search_book"));
        search_book->resize(456, 403);
        label = new QLabel(search_book);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 60, 181, 41));
        label_2 = new QLabel(search_book);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 90, 72, 15));
        label_3 = new QLabel(search_book);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 130, 72, 15));
        label_4 = new QLabel(search_book);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 160, 72, 15));
        label_5 = new QLabel(search_book);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 190, 72, 15));
        label_6 = new QLabel(search_book);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 230, 72, 15));
        research = new QPushButton(search_book);
        research->setObjectName(QString::fromUtf8("research"));
        research->setGeometry(QRect(160, 270, 93, 28));
        return_2 = new QPushButton(search_book);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(360, 240, 93, 28));
        quit = new QPushButton(search_book);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(360, 270, 93, 28));
        isbn = new QLineEdit(search_book);
        isbn->setObjectName(QString::fromUtf8("isbn"));
        isbn->setGeometry(QRect(120, 130, 151, 21));
        book_name = new QLineEdit(search_book);
        book_name->setObjectName(QString::fromUtf8("book_name"));
        book_name->setGeometry(QRect(120, 160, 151, 21));
        writer = new QLineEdit(search_book);
        writer->setObjectName(QString::fromUtf8("writer"));
        writer->setGeometry(QRect(120, 190, 151, 21));
        publishing_house = new QLineEdit(search_book);
        publishing_house->setObjectName(QString::fromUtf8("publishing_house"));
        publishing_house->setGeometry(QRect(120, 230, 151, 21));

        retranslateUi(search_book);
        QObject::connect(return_2, SIGNAL(clicked()), search_book, SLOT(slot1()));
        QObject::connect(quit, SIGNAL(clicked()), search_book, SLOT(close()));
        QObject::connect(research, SIGNAL(clicked()), search_book, SLOT(slot2()));

        QMetaObject::connectSlotsByName(search_book);
    } // setupUi

    void retranslateUi(QWidget *search_book)
    {
        search_book->setWindowTitle(QApplication::translate("search_book", "search_book", nullptr));
        label->setText(QApplication::translate("search_book", "LBMS \345\233\276\344\271\246\351\246\206\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\n"
"", nullptr));
        label_2->setText(QApplication::translate("search_book", "\344\271\246\347\261\215\347\256\241\347\220\206", nullptr));
        label_3->setText(QApplication::translate("search_book", "ISBN :", nullptr));
        label_4->setText(QApplication::translate("search_book", "\344\271\246\345\220\215 \357\274\232", nullptr));
        label_5->setText(QApplication::translate("search_book", "\344\275\234\350\200\205 \357\274\232", nullptr));
        label_6->setText(QApplication::translate("search_book", "\345\207\272\347\211\210\347\244\276\357\274\232", nullptr));
        research->setText(QApplication::translate("search_book", "\346\237\245\350\257\242", nullptr));
        return_2->setText(QApplication::translate("search_book", "\345\233\236\345\210\260\345\212\237\350\203\275\351\241\265", nullptr));
        quit->setText(QApplication::translate("search_book", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        writer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class search_book: public Ui_search_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_BOOK_H
