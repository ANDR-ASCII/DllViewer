/********************************************************************************
** Form generated from reading UI file 'generalnotification.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALNOTIFICATION_H
#define UI_GENERALNOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralNotification
{
public:

    void setupUi(QWidget *GeneralNotification)
    {
        if (GeneralNotification->objectName().isEmpty())
            GeneralNotification->setObjectName(QStringLiteral("GeneralNotification"));
        GeneralNotification->resize(362, 164);

        retranslateUi(GeneralNotification);

        QMetaObject::connectSlotsByName(GeneralNotification);
    } // setupUi

    void retranslateUi(QWidget *GeneralNotification)
    {
        GeneralNotification->setWindowTitle(QApplication::translate("GeneralNotification", "GeneralNotification", 0));
    } // retranslateUi

};

namespace Ui {
    class GeneralNotification: public Ui_GeneralNotification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALNOTIFICATION_H
