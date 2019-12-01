/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabwidget;
    QWidget *tab;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QScrollBar *verticalScrollBar;
    QScrollBar *horizontalScrollBar;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *ttt2;
    QWidget *tab_3;
    QMenuBar *menuBar;
    QMenu *menuFunctionality_Analysis;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1142, 710);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabwidget = new QTabWidget(centralWidget);
        tabwidget->setObjectName(QStringLiteral("tabwidget"));
        tabwidget->setGeometry(QRect(0, 0, 1141, 671));
        tabwidget->setStyleSheet(QStringLiteral("border-color: rgb(114, 159, 207);"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(410, 460, 541, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        verticalSlider = new QSlider(tab);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(940, 40, 20, 431));
        verticalSlider->setOrientation(Qt::Vertical);
        verticalScrollBar = new QScrollBar(tab);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(1020, 40, 16, 160));
        verticalScrollBar->setOrientation(Qt::Vertical);
        horizontalScrollBar = new QScrollBar(tab);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(410, 510, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(410, 40, 531, 421));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 60, 89, 25));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 100, 89, 25));
        tabwidget->addTab(tab, QString());
        ttt2 = new QWidget();
        ttt2->setObjectName(QStringLiteral("ttt2"));
        tabwidget->addTab(ttt2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabwidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1142, 22));
        menuFunctionality_Analysis = new QMenu(menuBar);
        menuFunctionality_Analysis->setObjectName(QStringLiteral("menuFunctionality_Analysis"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFunctionality_Analysis->menuAction());

        retranslateUi(MainWindow);

        tabwidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Functionality Analysis", 0));
#ifndef QT_NO_WHATSTHIS
        tabwidget->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>test</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        tab->setToolTip(QApplication::translate("MainWindow", "tab", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("MainWindow", "velocity", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "positions", 0));
        tabwidget->setTabText(tabwidget->indexOf(tab), QApplication::translate("MainWindow", "currentTab1", 0));
        tabwidget->setTabText(tabwidget->indexOf(ttt2), QApplication::translate("MainWindow", "currentTab2", 0));
        tabwidget->setTabText(tabwidget->indexOf(tab_3), QApplication::translate("MainWindow", "currentTab3", 0));
        menuFunctionality_Analysis->setTitle(QApplication::translate("MainWindow", "Functionality Analysis", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
