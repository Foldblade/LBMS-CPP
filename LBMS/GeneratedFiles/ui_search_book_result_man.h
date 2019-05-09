/********************************************************************************
** Form generated from reading UI file 'search_book_result_man.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_BOOK_RESULT_MAN_H
#define UI_SEARCH_BOOK_RESULT_MAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_search_book_result_man
{
public:
    QLabel *label;
    QPushButton *return_2;

    void setupUi(QWidget *search_book_result_man)
    {
        if (search_book_result_man->objectName().isEmpty())
            search_book_result_man->setObjectName(QString::fromUtf8("search_book_result_man"));
        search_book_result_man->resize(400, 300);
        label = new QLabel(search_book_result_man);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 181, 31));
        return_2 = new QPushButton(search_book_result_man);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(290, 250, 93, 28));

        retranslateUi(search_book_result_man);
        QObject::connect(return_2, SIGNAL(clicked()), search_book_result_man, SLOT(slot1()));

        QMetaObject::connectSlotsByName(search_book_result_man);
    } // setupUi

    void retranslateUi(QWidget *search_book_result_man)
    {
        search_book_result_man->setWindowTitle(QApplication::translate("search_book_result_man", "search_book_result_man", nullptr));
        label->setText(QApplication::translate("search_book_result_man", "LBMS \345\233\276\344\271\246\351\246\206\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\n"
"", nullptr));
        return_2->setText(QApplication::translate("search_book_result_man", "\350\277\224\345\233\236\346\237\245\350\257\242\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class search_book_result_man: public Ui_search_book_result_man {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_BOOK_RESULT_MAN_H
