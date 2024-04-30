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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TripDialog
{
public:
    QLabel *label_teamName;
    QPushButton *pushButton_previous;
    QPushButton *pushButton_next;
    QGroupBox *groupBox_teamInfo;
    QVBoxLayout *verticalLayout;
    QLabel *label_stadiumName;
    QLabel *label_seatingCapacity;
    QLabel *label_location;
    QLabel *label_playingSurface;
    QLabel *label_league;
    QLabel *label_dateOpened;
    QLabel *label_distanceToField;
    QLabel *label_typology;
    QLabel *label_rooftype;

    void setupUi(QDialog *TripDialog)
    {
        if (TripDialog->objectName().isEmpty())
            TripDialog->setObjectName("TripDialog");
        TripDialog->resize(777, 592);
        label_teamName = new QLabel(TripDialog);
        label_teamName->setObjectName("label_teamName");
        label_teamName->setGeometry(QRect(190, 10, 431, 71));
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
        pushButton_next->setGeometry(QRect(650, 540, 93, 29));
        groupBox_teamInfo = new QGroupBox(TripDialog);
        groupBox_teamInfo->setObjectName("groupBox_teamInfo");
        groupBox_teamInfo->setGeometry(QRect(30, 110, 291, 411));
        verticalLayout = new QVBoxLayout(groupBox_teamInfo);
        verticalLayout->setObjectName("verticalLayout");
        label_stadiumName = new QLabel(groupBox_teamInfo);
        label_stadiumName->setObjectName("label_stadiumName");

        verticalLayout->addWidget(label_stadiumName);

        label_seatingCapacity = new QLabel(groupBox_teamInfo);
        label_seatingCapacity->setObjectName("label_seatingCapacity");

        verticalLayout->addWidget(label_seatingCapacity);

        label_location = new QLabel(groupBox_teamInfo);
        label_location->setObjectName("label_location");

        verticalLayout->addWidget(label_location);

        label_playingSurface = new QLabel(groupBox_teamInfo);
        label_playingSurface->setObjectName("label_playingSurface");

        verticalLayout->addWidget(label_playingSurface);

        label_league = new QLabel(groupBox_teamInfo);
        label_league->setObjectName("label_league");

        verticalLayout->addWidget(label_league);

        label_dateOpened = new QLabel(groupBox_teamInfo);
        label_dateOpened->setObjectName("label_dateOpened");

        verticalLayout->addWidget(label_dateOpened);

        label_distanceToField = new QLabel(groupBox_teamInfo);
        label_distanceToField->setObjectName("label_distanceToField");

        verticalLayout->addWidget(label_distanceToField);

        label_typology = new QLabel(groupBox_teamInfo);
        label_typology->setObjectName("label_typology");

        verticalLayout->addWidget(label_typology);

        label_rooftype = new QLabel(groupBox_teamInfo);
        label_rooftype->setObjectName("label_rooftype");

        verticalLayout->addWidget(label_rooftype);


        retranslateUi(TripDialog);

        QMetaObject::connectSlotsByName(TripDialog);
    } // setupUi

    void retranslateUi(QDialog *TripDialog)
    {
        TripDialog->setWindowTitle(QCoreApplication::translate("TripDialog", "Dialog", nullptr));
        label_teamName->setText(QCoreApplication::translate("TripDialog", "Team name", nullptr));
        pushButton_previous->setText(QCoreApplication::translate("TripDialog", "Previous", nullptr));
        pushButton_next->setText(QCoreApplication::translate("TripDialog", "Next", nullptr));
        groupBox_teamInfo->setTitle(QCoreApplication::translate("TripDialog", "Team Info", nullptr));
        label_stadiumName->setText(QCoreApplication::translate("TripDialog", "TextLabel", nullptr));
        label_seatingCapacity->setText(QCoreApplication::translate("TripDialog", "TextLabel", nullptr));
        label_location->setText(QCoreApplication::translate("TripDialog", "TextLabel", nullptr));
        label_playingSurface->setText(QCoreApplication::translate("TripDialog", "TextLabel", nullptr));
        label_league->setText(QCoreApplication::translate("TripDialog", "TextLabel", nullptr));
        label_dateOpened->setText(QCoreApplication::translate("TripDialog", "TextLabel", nullptr));
        label_distanceToField->setText(QCoreApplication::translate("TripDialog", "TextLabel", nullptr));
        label_typology->setText(QCoreApplication::translate("TripDialog", "TextLabel", nullptr));
        label_rooftype->setText(QCoreApplication::translate("TripDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripDialog: public Ui_TripDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPDIALOG_H
