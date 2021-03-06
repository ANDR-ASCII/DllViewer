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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *searchLineEdit;
    QSplitter *splitter;
    QTreeView *processView;
    QTreeView *dllsView;
    QHBoxLayout *horizontalLayout;
    QLabel *adviceLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *terminateButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DllViewerClass)
    {
        if (DllViewerClass->objectName().isEmpty())
            DllViewerClass->setObjectName(QStringLiteral("DllViewerClass"));
        DllViewerClass->resize(1013, 676);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../visual-studio-2015-projects/ModuleViewer/ModuleViewer/icons/dll-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        DllViewerClass->setWindowIcon(icon);
        DllViewerClass->setStyleSheet(QLatin1String("font: 10pt \"Courier New\";\n"
""));
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
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        searchLineEdit = new QLineEdit(centralWidget);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));

        horizontalLayout_2->addWidget(searchLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        processView = new QTreeView(splitter);
        processView->setObjectName(QStringLiteral("processView"));
        processView->setStyleSheet(QStringLiteral(""));
        processView->setAnimated(true);
        splitter->addWidget(processView);
        dllsView = new QTreeView(splitter);
        dllsView->setObjectName(QStringLiteral("dllsView"));
        splitter->addWidget(dllsView);

        verticalLayout->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        adviceLabel = new QLabel(centralWidget);
        adviceLabel->setObjectName(QStringLiteral("adviceLabel"));

        horizontalLayout->addWidget(adviceLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        terminateButton = new QPushButton(centralWidget);
        terminateButton->setObjectName(QStringLiteral("terminateButton"));

        horizontalLayout->addWidget(terminateButton);


        verticalLayout->addLayout(horizontalLayout);

        DllViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DllViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1013, 22));
        DllViewerClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(DllViewerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DllViewerClass->setStatusBar(statusBar);

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
        adviceLabel->setText(QString());
        terminateButton->setText(QApplication::translate("DllViewerClass", "Terminate selected process", 0));
    } // retranslateUi

};

namespace Ui {
    class DllViewerClass: public Ui_DllViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLLVIEWER_H
