/********************************************************************************
** Form generated from reading UI file 'search_book_man.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_BOOK_MAN_H
#define UI_SEARCH_BOOK_MAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_search_book_man
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *search;
    QPushButton *return_2;

    void setupUi(QWidget *search_book_man)
    {
        if (search_book_man->objectName().isEmpty())
            search_book_man->setObjectName(QString::fromUtf8("search_book_man"));
        search_book_man->resize(400, 300);
        label = new QLabel(search_book_man);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 191, 31));
        label_2 = new QLabel(search_book_man);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 101, 31));
        label_3 = new QLabel(search_book_man);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 100, 72, 15));
        label_4 = new QLabel(search_book_man);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 130, 72, 15));
        label_5 = new QLabel(search_book_man);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 160, 72, 15));
        label_6 = new QLabel(search_book_man);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 190, 72, 15));
        lineEdit = new QLineEdit(search_book_man);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 100, 113, 21));
        lineEdit_2 = new QLineEdit(search_book_man);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 130, 113, 21));
        lineEdit_3 = new QLineEdit(search_book_man);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 160, 113, 21));
        lineEdit_4 = new QLineEdit(search_book_man);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(110, 190, 113, 21));
        search = new QPushButton(search_book_man);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(120, 230, 93, 28));
        return_2 = new QPushButton(search_book_man);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(290, 240, 93, 28));

        retranslateUi(search_book_man);
        QObject::connect(return_2, SIGNAL(clicked()), search_book_man, SLOT(slot1()));
        QObject::connect(search, SIGNAL(clicked()), search_book_man, SLOT(slot2()));

        QMetaObject::connectSlotsByName(search_book_man);
    } // setupUi

    void retranslateUi(QWidget *search_book_man)
    {
        search_book_man->setWindowTitle(QApplication::translate("search_book_man", "search_book_man", nullptr));
        label->setText(QApplication::translate("search_book_man", "LBMS \345\233\276\344\271\246\351\246\206\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\n"
"", nullptr));
        label_2->setText(QApplication::translate("search_book_man", "\344\271\246\347\261\215\347\256\241\347\220\206\n"
"", nullptr));
        label_3->setText(QApplication::translate("search_book_man", "ISBN:", nullptr));
        label_4->setText(QApplication::translate("search_book_man", "\344\271\246\345\220\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("search_book_man", "\344\275\234\350\200\205\357\274\232", nullptr));
        label_6->setText(QApplication::translate("search_book_man", "\345\207\272\347\211\210\347\244\276\357\274\232", nullptr));
        search->setText(QApplication::translate("search_book_man", "\346\237\245\350\257\242", nullptr));
        return_2->setText(QApplication::translate("search_book_man", "\350\277\224\345\233\236\347\256\241\347\220\206\344\270\255\345\277\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class search_book_man: public Ui_search_book_man {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_BOOK_MAN_H
