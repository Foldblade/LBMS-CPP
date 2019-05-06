/********************************************************************************
** Form generated from reading UI file 'search_book_result_no.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_BOOK_RESULT_NO_H
#define UI_SEARCH_BOOK_RESULT_NO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_search_book_result_no
{
public:
    QLabel *label;
    QPushButton *returnsearch;

    void setupUi(QWidget *search_book_result_no)
    {
        if (search_book_result_no->objectName().isEmpty())
            search_book_result_no->setObjectName(QString::fromUtf8("search_book_result_no"));
        search_book_result_no->resize(400, 300);
        label = new QLabel(search_book_result_no);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 181, 31));
        returnsearch = new QPushButton(search_book_result_no);
        returnsearch->setObjectName(QString::fromUtf8("returnsearch"));
        returnsearch->setGeometry(QRect(280, 250, 93, 28));

        retranslateUi(search_book_result_no);
        QObject::connect(returnsearch, SIGNAL(clicked()), search_book_result_no, SLOT(slot1()));

        QMetaObject::connectSlotsByName(search_book_result_no);
    } // setupUi

    void retranslateUi(QWidget *search_book_result_no)
    {
        search_book_result_no->setWindowTitle(QApplication::translate("search_book_result_no", "search_book_result_no", nullptr));
        label->setText(QApplication::translate("search_book_result_no", "LBMS \345\233\276\344\271\246\351\246\206\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\n"
"", nullptr));
        returnsearch->setText(QApplication::translate("search_book_result_no", "\350\277\224\345\233\236\346\237\245\350\257\242\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class search_book_result_no: public Ui_search_book_result_no {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_BOOK_RESULT_NO_H
