/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_16;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QPushButton *pushButton_13;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_7;
    QMenuBar *menuBar;
    QMenu *menu12;
    QMenu *menu23;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1251, 757);
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 490, 118, 59));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(420, 460, 118, 59));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setMinimumSize(QSize(50, 50));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 10, 811, 480));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_16 = new QPushButton(verticalLayoutWidget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(150, 50));
        pushButton_16->setMaximumSize(QSize(150, 50));

        horizontalLayout_3->addWidget(pushButton_16);

        pushButton_15 = new QPushButton(verticalLayoutWidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(150, 50));
        pushButton_15->setMaximumSize(QSize(150, 50));

        horizontalLayout_3->addWidget(pushButton_15);

        pushButton_14 = new QPushButton(verticalLayoutWidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(150, 50));
        pushButton_14->setMaximumSize(QSize(150, 50));

        horizontalLayout_3->addWidget(pushButton_14);

        pushButton_13 = new QPushButton(verticalLayoutWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(150, 50));
        pushButton_13->setMaximumSize(QSize(150, 50));

        horizontalLayout_3->addWidget(pushButton_13);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_9 = new QPushButton(verticalLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(150, 50));
        pushButton_9->setMaximumSize(QSize(150, 50));

        horizontalLayout_4->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(verticalLayoutWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(150, 50));
        pushButton_10->setMaximumSize(QSize(150, 50));

        horizontalLayout_4->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(verticalLayoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(150, 50));
        pushButton_11->setMaximumSize(QSize(150, 50));

        horizontalLayout_4->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(verticalLayoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(150, 50));
        pushButton_12->setMaximumSize(QSize(150, 50));

        horizontalLayout_4->addWidget(pushButton_12);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(150, 150));
        pushButton->setMaximumSize(QSize(150, 150));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(150, 150));
        pushButton_2->setMaximumSize(QSize(150, 150));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(150, 150));
        pushButton_4->setMaximumSize(QSize(150, 150));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setMinimumSize(QSize(150, 150));
        pushButton_5->setMaximumSize(QSize(150, 150));

        horizontalLayout->addWidget(pushButton_5);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_17 = new QPushButton(verticalLayoutWidget);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        sizePolicy.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy);
        pushButton_17->setMinimumSize(QSize(150, 150));
        pushButton_17->setMaximumSize(QSize(150, 150));

        horizontalLayout_2->addWidget(pushButton_17);

        pushButton_18 = new QPushButton(verticalLayoutWidget);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        sizePolicy.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy);
        pushButton_18->setMinimumSize(QSize(150, 150));
        pushButton_18->setMaximumSize(QSize(150, 150));

        horizontalLayout_2->addWidget(pushButton_18);

        pushButton_19 = new QPushButton(verticalLayoutWidget);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        sizePolicy.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy);
        pushButton_19->setMinimumSize(QSize(150, 150));
        pushButton_19->setMaximumSize(QSize(150, 150));

        horizontalLayout_2->addWidget(pushButton_19);

        pushButton_20 = new QPushButton(verticalLayoutWidget);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        sizePolicy.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy);
        pushButton_20->setMinimumSize(QSize(150, 150));
        pushButton_20->setMaximumSize(QSize(150, 150));

        horizontalLayout_2->addWidget(pushButton_20);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 480, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1251, 23));
        menu12 = new QMenu(menuBar);
        menu12->setObjectName(QString::fromUtf8("menu12"));
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
        menuBar->addAction(menu12->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\210\227\350\241\250", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\232\204\351\241\271", nullptr));
        pushButton_16->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_15->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_14->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_13->setText(QApplication::translate("MainWindow", "4", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "6", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "7", nullptr));
        pushButton_12->setText(QApplication::translate("MainWindow", "8", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "4", nullptr));
        pushButton_17->setText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton_18->setText(QApplication::translate("MainWindow", "6", nullptr));
        pushButton_19->setText(QApplication::translate("MainWindow", "7", nullptr));
        pushButton_20->setText(QApplication::translate("MainWindow", "8", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        menu12->setTitle(QApplication::translate("MainWindow", "12", nullptr));
        menu23->setTitle(QApplication::translate("MainWindow", "23", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
