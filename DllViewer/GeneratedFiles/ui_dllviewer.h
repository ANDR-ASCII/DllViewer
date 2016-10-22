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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DllViewerClass
{
public:
    QAction *actionTerminate_process;
    QAction *actionStart_new_process;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *searchLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *terminateButton;
    QPushButton *startProcessButton;
    QSplitter *splitter;
    QTreeView *processView;
    QTreeView *dllsView;
    QMenuBar *menuBar;
    QMenu *menuActions;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DllViewerClass)
    {
        if (DllViewerClass->objectName().isEmpty())
            DllViewerClass->setObjectName(QStringLiteral("DllViewerClass"));
        DllViewerClass->resize(1013, 676);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../visual-studio-2015-projects/ModuleViewer/ModuleViewer/icons/dll-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        DllViewerClass->setWindowIcon(icon);
        actionTerminate_process = new QAction(DllViewerClass);
        actionTerminate_process->setObjectName(QStringLiteral("actionTerminate_process"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("icons/Delete-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTerminate_process->setIcon(icon1);
        actionStart_new_process = new QAction(DllViewerClass);
        actionStart_new_process->setObjectName(QStringLiteral("actionStart_new_process"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("icons/new-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_new_process->setIcon(icon2);
        centralWidget = new QWidget(DllViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        searchLineEdit = new QLineEdit(centralWidget);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));

        horizontalLayout_2->addWidget(searchLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        terminateButton = new QPushButton(centralWidget);
        terminateButton->setObjectName(QStringLiteral("terminateButton"));

        horizontalLayout->addWidget(terminateButton);

        startProcessButton = new QPushButton(centralWidget);
        startProcessButton->setObjectName(QStringLiteral("startProcessButton"));

        horizontalLayout->addWidget(startProcessButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        processView = new QTreeView(splitter);
        processView->setObjectName(QStringLiteral("processView"));
        splitter->addWidget(processView);
        dllsView = new QTreeView(splitter);
        dllsView->setObjectName(QStringLiteral("dllsView"));
        splitter->addWidget(dllsView);

        verticalLayout_2->addWidget(splitter);

        DllViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DllViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1013, 21));
        menuActions = new QMenu(menuBar);
        menuActions->setObjectName(QStringLiteral("menuActions"));
        DllViewerClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(DllViewerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DllViewerClass->setStatusBar(statusBar);

        menuBar->addAction(menuActions->menuAction());
        menuActions->addAction(actionTerminate_process);
        menuActions->addAction(actionStart_new_process);

        retranslateUi(DllViewerClass);

        QMetaObject::connectSlotsByName(DllViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *DllViewerClass)
    {
        DllViewerClass->setWindowTitle(QApplication::translate("DllViewerClass", "DllViewer", 0));
        actionTerminate_process->setText(QApplication::translate("DllViewerClass", "Terminate process", 0));
#ifndef QT_NO_TOOLTIP
        actionTerminate_process->setToolTip(QApplication::translate("DllViewerClass", "CTRL + T", 0));
#endif // QT_NO_TOOLTIP
        actionStart_new_process->setText(QApplication::translate("DllViewerClass", "Start new process", 0));
        label->setText(QApplication::translate("DllViewerClass", "Type in pid or process name for search:", 0));
        terminateButton->setText(QApplication::translate("DllViewerClass", "Terminate selected process", 0));
        startProcessButton->setText(QApplication::translate("DllViewerClass", "Start process", 0));
        menuActions->setTitle(QApplication::translate("DllViewerClass", "Actions", 0));
    } // retranslateUi

};

namespace Ui {
    class DllViewerClass: public Ui_DllViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLLVIEWER_H
