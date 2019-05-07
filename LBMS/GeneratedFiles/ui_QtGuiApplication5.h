/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication5.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION5_H
#define UI_QTGUIAPPLICATION5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication5Class
{
public:
    QWidget *centralWidget;
    QPushButton *administor;
    QPushButton *search;
    QPushButton *quit;
    QLabel *label_2;
    QLabel *label;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication5Class)
    {
        if (QtGuiApplication5Class->objectName().isEmpty())
            QtGuiApplication5Class->setObjectName(QString::fromUtf8("QtGuiApplication5Class"));
        QtGuiApplication5Class->resize(600, 400);
        centralWidget = new QWidget(QtGuiApplication5Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        administor = new QPushButton(centralWidget);
        administor->setObjectName(QString::fromUtf8("administor"));
        administor->setGeometry(QRect(120, 140, 93, 91));
        search = new QPushButton(centralWidget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(350, 140, 93, 91));
        quit = new QPushButton(centralWidget);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(490, 300, 93, 28));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 280, 231, 51));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 30, 351, 81));
        QtGuiApplication5Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGuiApplication5Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiApplication5Class->setStatusBar(statusBar);

        retranslateUi(QtGuiApplication5Class);
        QObject::connect(quit, SIGNAL(clicked()), QtGuiApplication5Class, SLOT(close()));
        QObject::connect(administor, SIGNAL(clicked()), QtGuiApplication5Class, SLOT(slot1()));
        QObject::connect(search, SIGNAL(clicked()), QtGuiApplication5Class, SLOT(slot2()));

        QMetaObject::connectSlotsByName(QtGuiApplication5Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication5Class)
    {
        QtGuiApplication5Class->setWindowTitle(QApplication::translate("QtGuiApplication5Class", "QtGuiApplication5", nullptr));
        administor->setText(QApplication::translate("QtGuiApplication5Class", "\347\256\241\347\220\206\345\221\230\347\231\273\351\231\206", nullptr));
        search->setText(QApplication::translate("QtGuiApplication5Class", "\346\237\245\350\257\242\345\233\276\344\271\246", nullptr));
        quit->setText(QApplication::translate("QtGuiApplication5Class", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        label_2->setText(QApplication::translate("QtGuiApplication5Class", "Made by T.X. & X.H. with \342\235\244 ", nullptr));
        label->setText(QApplication::translate("QtGuiApplication5Class", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">LBMS\345\233\276\344\271\246\351\246\206\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication5Class: public Ui_QtGuiApplication5Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION5_H
