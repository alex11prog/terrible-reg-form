/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_phone;
    QPushButton *Button_register;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_pw;
    QLineEdit *lineEdit_pw2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_generator;
    QPushButton *btn_clear;
    QPushButton *reg2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(643, 503);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit_phone = new QLineEdit(centralwidget);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(210, 80, 113, 26));
        Button_register = new QPushButton(centralwidget);
        Button_register->setObjectName(QString::fromUtf8("Button_register"));
        Button_register->setGeometry(QRect(10, 290, 621, 151));
        QFont font;
        font.setPointSize(50);
        Button_register->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 70, 121, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 30, 61, 21));
        lineEdit_login = new QLineEdit(centralwidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(210, 30, 113, 26));
        lineEdit_pw = new QLineEdit(centralwidget);
        lineEdit_pw->setObjectName(QString::fromUtf8("lineEdit_pw"));
        lineEdit_pw->setGeometry(QRect(210, 140, 113, 26));
        lineEdit_pw2 = new QLineEdit(centralwidget);
        lineEdit_pw2->setObjectName(QString::fromUtf8("lineEdit_pw2"));
        lineEdit_pw2->setGeometry(QRect(210, 190, 113, 26));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 140, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 180, 171, 41));
        pushButton_generator = new QPushButton(centralwidget);
        pushButton_generator->setObjectName(QString::fromUtf8("pushButton_generator"));
        pushButton_generator->setGeometry(QRect(350, 30, 261, 31));
        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(350, 80, 261, 29));
        reg2 = new QPushButton(centralwidget);
        reg2->setObjectName(QString::fromUtf8("reg2"));
        reg2->setGeometry(QRect(290, 380, 5, 5));
        reg2->setText(QString::fromUtf8(""));
        reg2->setIconSize(QSize(5, 5));
#if QT_CONFIG(shortcut)
        reg2->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 643, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Button_register->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\320\262\320\276\320\275\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        pushButton_generator->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));
        btn_clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\271 \321\201\320\270\320\274\320\262\320\276\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
