/********************************************************************************
** Form generated from reading UI file 'tripdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPDIALOG_H
#define UI_TRIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TripDialog
{
public:
    QLabel *label_teamName;
    QPushButton *pushButton_previous;
    QPushButton *pushButton_next;

    void setupUi(QDialog *TripDialog)
    {
        if (TripDialog->objectName().isEmpty())
            TripDialog->setObjectName("TripDialog");
        TripDialog->resize(777, 592);
        label_teamName = new QLabel(TripDialog);
        label_teamName->setObjectName("label_teamName");
        label_teamName->setGeometry(QRect(160, 60, 431, 71));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_teamName->setFont(font);
        label_teamName->setAlignment(Qt::AlignCenter);
        pushButton_previous = new QPushButton(TripDialog);
        pushButton_previous->setObjectName("pushButton_previous");
        pushButton_previous->setEnabled(false);
        pushButton_previous->setGeometry(QRect(30, 540, 93, 29));
        pushButton_next = new QPushButton(TripDialog);
        pushButton_next->setObjectName("pushButton_next");
        pushButton_next->setGeometry(QRect(660, 530, 93, 29));

        retranslateUi(TripDialog);

        QMetaObject::connectSlotsByName(TripDialog);
    } // setupUi

    void retranslateUi(QDialog *TripDialog)
    {
        TripDialog->setWindowTitle(QCoreApplication::translate("TripDialog", "Dialog", nullptr));
        label_teamName->setText(QCoreApplication::translate("TripDialog", "TextLabel", nullptr));
        pushButton_previous->setText(QCoreApplication::translate("TripDialog", "Previous", nullptr));
        pushButton_next->setText(QCoreApplication::translate("TripDialog", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripDialog: public Ui_TripDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPDIALOG_H
