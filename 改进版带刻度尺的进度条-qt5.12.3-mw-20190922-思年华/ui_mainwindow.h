/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <ruler.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action2;
    QWidget *centralWidget;
    Ruler *progressBar;
    QPushButton *pushButton;
    QLabel *label;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu23;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1444, 916);
        action2 = new QAction(MainWindow);
        action2->setObjectName(QString::fromUtf8("action2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        progressBar = new Ruler(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(650, 100, 471, 531));
        progressBar->setMaximum(100);
        progressBar->setValue(1);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Vertical);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::BottomToTop);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(610, 50, 211, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 20, 291, 31));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(180, 60, 351, 111));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1444, 23));
        menu23 = new QMenu(menuBar);
        menu23->setObjectName(QString::fromUtf8("menu23"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu23->menuAction());
        menu23->addAction(action2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\350\277\233\345\272\246\346\235\241\345\275\223\345\211\215\345\200\274", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Qt\344\270\255\345\233\275\347\276\244~\346\200\235\345\271\264\345\215\216", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\236\202\347\233\264\345\222\214\346\260\264\345\271\263\350\277\233\345\272\246\345\210\273\345\272\246\346\216\247\344\273\266,\345\217\252\350\246\201\344\277\256\346\224\271ruler.h\344\270\255\347\232\204shuiping_chuizhi0\346\260\264\345\271\263,1\345\236\202\347\233\264.\345\222\214\344\277\256\346\224\271\351\207\217\345\260\272\347\232\204\346\234\200\345\244\247\345\200\274,\346\234\200\345\260\217\345\210\273\345\272\246</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345"
                        "\205\266\344\275\231\345\217\202\346\225\260\351\203\275\344\270\215\347\224\250\346\224\271.</p></body></html>", nullptr));
        menu23->setTitle(QCoreApplication::translate("MainWindow", "23", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
