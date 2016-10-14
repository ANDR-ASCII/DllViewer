/********************************************************************************
** Form generated from reading UI file 'dllviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLLVIEWER_H
#define UI_DLLVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DllViewerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DllViewerClass)
    {
        if (DllViewerClass->objectName().isEmpty())
            DllViewerClass->setObjectName(QStringLiteral("DllViewerClass"));
        DllViewerClass->resize(600, 400);
        menuBar = new QMenuBar(DllViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        DllViewerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DllViewerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DllViewerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DllViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DllViewerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DllViewerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DllViewerClass->setStatusBar(statusBar);

        retranslateUi(DllViewerClass);

        QMetaObject::connectSlotsByName(DllViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *DllViewerClass)
    {
        DllViewerClass->setWindowTitle(QApplication::translate("DllViewerClass", "DllViewer", 0));
    } // retranslateUi

};

namespace Ui {
    class DllViewerClass: public Ui_DllViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLLVIEWER_H
