/********************************************************************************
** Form generated from reading UI file 'SouvenirPurchase.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUVENIRPURCHASE_H
#define UI_SOUVENIRPURCHASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SouvenirPurchase
{
public:
    QTableWidget *souvenirAndPriceTable;
    QTableWidget *summaryTable;
    QPushButton *purchaseBtn;
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
    QLabel *label_teamName;

    void setupUi(QDialog *SouvenirPurchase)
    {
        if (SouvenirPurchase->objectName().isEmpty())
            SouvenirPurchase->setObjectName("SouvenirPurchase");
        SouvenirPurchase->resize(902, 527);
        souvenirAndPriceTable = new QTableWidget(SouvenirPurchase);
        if (souvenirAndPriceTable->columnCount() < 3)
            souvenirAndPriceTable->setColumnCount(3);
        QFont font;
        font.setPointSize(16);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        souvenirAndPriceTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        souvenirAndPriceTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        souvenirAndPriceTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        souvenirAndPriceTable->setObjectName("souvenirAndPriceTable");
        souvenirAndPriceTable->setGeometry(QRect(310, 91, 571, 191));
        QFont font1;
        font1.setPointSize(12);
        souvenirAndPriceTable->setFont(font1);
        souvenirAndPriceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        souvenirAndPriceTable->verticalHeader()->setVisible(false);
        summaryTable = new QTableWidget(SouvenirPurchase);
        if (summaryTable->columnCount() < 2)
            summaryTable->setColumnCount(2);
        QFont font2;
        font2.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        summaryTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        summaryTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        if (summaryTable->rowCount() < 1)
            summaryTable->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        summaryTable->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem6->setFlags(Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        summaryTable->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem7->setFlags(Qt::ItemIsEnabled);
        summaryTable->setItem(0, 1, __qtablewidgetitem7);
        summaryTable->setObjectName("summaryTable");
        summaryTable->setGeometry(QRect(480, 360, 241, 121));
        summaryTable->setFont(font);
        summaryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        summaryTable->verticalHeader()->setVisible(false);
        purchaseBtn = new QPushButton(SouvenirPurchase);
        purchaseBtn->setObjectName("purchaseBtn");
        purchaseBtn->setGeometry(QRect(530, 290, 131, 41));
        purchaseBtn->setFont(font1);
        pushButton_previous = new QPushButton(SouvenirPurchase);
        pushButton_previous->setObjectName("pushButton_previous");
        pushButton_previous->setGeometry(QRect(10, 490, 100, 32));
        pushButton_next = new QPushButton(SouvenirPurchase);
        pushButton_next->setObjectName("pushButton_next");
        pushButton_next->setGeometry(QRect(790, 490, 100, 32));
        groupBox_teamInfo = new QGroupBox(SouvenirPurchase);
        groupBox_teamInfo->setObjectName("groupBox_teamInfo");
        groupBox_teamInfo->setGeometry(QRect(10, 70, 291, 411));
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

        label_teamName = new QLabel(SouvenirPurchase);
        label_teamName->setObjectName("label_teamName");
        label_teamName->setGeometry(QRect(270, 10, 431, 71));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        label_teamName->setFont(font3);
        label_teamName->setAlignment(Qt::AlignCenter);

        retranslateUi(SouvenirPurchase);

        QMetaObject::connectSlotsByName(SouvenirPurchase);
    } // setupUi

    void retranslateUi(QDialog *SouvenirPurchase)
    {
        SouvenirPurchase->setWindowTitle(QCoreApplication::translate("SouvenirPurchase", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = souvenirAndPriceTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SouvenirPurchase", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = souvenirAndPriceTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SouvenirPurchase", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = souvenirAndPriceTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SouvenirPurchase", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = summaryTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SouvenirPurchase", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = summaryTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SouvenirPurchase", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = summaryTable->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SouvenirPurchase", "New Row", nullptr));

        const bool __sortingEnabled = summaryTable->isSortingEnabled();
        summaryTable->setSortingEnabled(false);
        summaryTable->setSortingEnabled(__sortingEnabled);

        purchaseBtn->setText(QCoreApplication::translate("SouvenirPurchase", "Add to Cart", nullptr));
        pushButton_previous->setText(QCoreApplication::translate("SouvenirPurchase", "Previous", nullptr));
        pushButton_next->setText(QCoreApplication::translate("SouvenirPurchase", "Next", nullptr));
        groupBox_teamInfo->setTitle(QCoreApplication::translate("SouvenirPurchase", "Team Info", nullptr));
        label_stadiumName->setText(QCoreApplication::translate("SouvenirPurchase", "TextLabel", nullptr));
        label_seatingCapacity->setText(QCoreApplication::translate("SouvenirPurchase", "TextLabel", nullptr));
        label_location->setText(QCoreApplication::translate("SouvenirPurchase", "TextLabel", nullptr));
        label_playingSurface->setText(QCoreApplication::translate("SouvenirPurchase", "TextLabel", nullptr));
        label_league->setText(QCoreApplication::translate("SouvenirPurchase", "TextLabel", nullptr));
        label_dateOpened->setText(QCoreApplication::translate("SouvenirPurchase", "TextLabel", nullptr));
        label_distanceToField->setText(QCoreApplication::translate("SouvenirPurchase", "TextLabel", nullptr));
        label_typology->setText(QCoreApplication::translate("SouvenirPurchase", "TextLabel", nullptr));
        label_rooftype->setText(QCoreApplication::translate("SouvenirPurchase", "TextLabel", nullptr));
        label_teamName->setText(QCoreApplication::translate("SouvenirPurchase", "Team name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SouvenirPurchase: public Ui_SouvenirPurchase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUVENIRPURCHASE_H
