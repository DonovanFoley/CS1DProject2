/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QListWidget *listWidget_teamList;
    QComboBox *comboBox_exclude;
    QComboBox *comboBox_sort;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_souvenirInfo;
    QTableWidget *tableWidget_teamInfo;
    QPushButton *pushButton_add;
    QPushButton *pushButton_delete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(762, 660);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 20, 311, 541));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        listWidget_teamList = new QListWidget(groupBox);
        listWidget_teamList->setObjectName("listWidget_teamList");

        gridLayout->addWidget(listWidget_teamList, 1, 0, 1, 2);

        comboBox_exclude = new QComboBox(groupBox);
        comboBox_exclude->addItem(QString());
        comboBox_exclude->addItem(QString());
        comboBox_exclude->addItem(QString());
        comboBox_exclude->addItem(QString());
        comboBox_exclude->addItem(QString());
        comboBox_exclude->addItem(QString());
        comboBox_exclude->setObjectName("comboBox_exclude");

        gridLayout->addWidget(comboBox_exclude, 0, 1, 1, 1);

        comboBox_sort = new QComboBox(groupBox);
        comboBox_sort->addItem(QString());
        comboBox_sort->addItem(QString());
        comboBox_sort->addItem(QString());
        comboBox_sort->addItem(QString());
        comboBox_sort->addItem(QString());
        comboBox_sort->setObjectName("comboBox_sort");

        gridLayout->addWidget(comboBox_sort, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(340, 20, 401, 541));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName("gridLayout_3");
        tableWidget_souvenirInfo = new QTableWidget(groupBox_2);
        if (tableWidget_souvenirInfo->columnCount() < 2)
            tableWidget_souvenirInfo->setColumnCount(2);
        QFont font;
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget_souvenirInfo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget_souvenirInfo->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_souvenirInfo->setObjectName("tableWidget_souvenirInfo");
        tableWidget_souvenirInfo->setEnabled(true);
        tableWidget_souvenirInfo->setMinimumSize(QSize(0, 0));
        tableWidget_souvenirInfo->setInputMethodHints(Qt::ImhNone);
        tableWidget_souvenirInfo->setFrameShape(QFrame::Box);
        tableWidget_souvenirInfo->setFrameShadow(QFrame::Sunken);
        tableWidget_souvenirInfo->setLineWidth(1);
        tableWidget_souvenirInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_souvenirInfo->setTabKeyNavigation(true);
        tableWidget_souvenirInfo->setAlternatingRowColors(false);
        tableWidget_souvenirInfo->setRowCount(0);
        tableWidget_souvenirInfo->horizontalHeader()->setVisible(true);
        tableWidget_souvenirInfo->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_souvenirInfo->horizontalHeader()->setDefaultSectionSize(180);
        tableWidget_souvenirInfo->horizontalHeader()->setHighlightSections(true);
        tableWidget_souvenirInfo->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_souvenirInfo->verticalHeader()->setVisible(false);
        tableWidget_souvenirInfo->verticalHeader()->setMinimumSectionSize(10);
        tableWidget_souvenirInfo->verticalHeader()->setHighlightSections(true);
        tableWidget_souvenirInfo->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_souvenirInfo->verticalHeader()->setStretchLastSection(false);

        gridLayout_3->addWidget(tableWidget_souvenirInfo, 1, 0, 1, 2);

        tableWidget_teamInfo = new QTableWidget(groupBox_2);
        if (tableWidget_teamInfo->columnCount() < 1)
            tableWidget_teamInfo->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_teamInfo->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        if (tableWidget_teamInfo->rowCount() < 10)
            tableWidget_teamInfo->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget_teamInfo->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget_teamInfo->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget_teamInfo->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget_teamInfo->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tableWidget_teamInfo->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        tableWidget_teamInfo->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        tableWidget_teamInfo->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        tableWidget_teamInfo->setVerticalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        tableWidget_teamInfo->setVerticalHeaderItem(8, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        tableWidget_teamInfo->setVerticalHeaderItem(9, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_teamInfo->setItem(0, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_teamInfo->setItem(1, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_teamInfo->setItem(2, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_teamInfo->setItem(3, 0, __qtablewidgetitem16);
        tableWidget_teamInfo->setObjectName("tableWidget_teamInfo");
        tableWidget_teamInfo->setEnabled(true);
        tableWidget_teamInfo->setMinimumSize(QSize(0, 304));
        tableWidget_teamInfo->setInputMethodHints(Qt::ImhNone);
        tableWidget_teamInfo->setFrameShape(QFrame::Box);
        tableWidget_teamInfo->setFrameShadow(QFrame::Sunken);
        tableWidget_teamInfo->setLineWidth(1);
        tableWidget_teamInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_teamInfo->setTabKeyNavigation(true);
        tableWidget_teamInfo->setAlternatingRowColors(false);
        tableWidget_teamInfo->horizontalHeader()->setVisible(false);
        tableWidget_teamInfo->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_teamInfo->horizontalHeader()->setDefaultSectionSize(280);
        tableWidget_teamInfo->verticalHeader()->setMinimumSectionSize(20);

        gridLayout_3->addWidget(tableWidget_teamInfo, 0, 0, 1, 2);

        pushButton_add = new QPushButton(groupBox_2);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setEnabled(false);

        gridLayout_3->addWidget(pushButton_add, 2, 0, 1, 1);

        pushButton_delete = new QPushButton(groupBox_2);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setEnabled(false);

        gridLayout_3->addWidget(pushButton_delete, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 762, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Team Names", nullptr));
        comboBox_exclude->setItemText(0, QCoreApplication::translate("MainWindow", "All", nullptr));
        comboBox_exclude->setItemText(1, QCoreApplication::translate("MainWindow", "American League", nullptr));
        comboBox_exclude->setItemText(2, QCoreApplication::translate("MainWindow", "National League", nullptr));
        comboBox_exclude->setItemText(3, QCoreApplication::translate("MainWindow", "Open Roof", nullptr));
        comboBox_exclude->setItemText(4, QCoreApplication::translate("MainWindow", "Greatest Distance", nullptr));
        comboBox_exclude->setItemText(5, QCoreApplication::translate("MainWindow", "Smallest Distance", nullptr));

        comboBox_sort->setItemText(0, QCoreApplication::translate("MainWindow", "Team Name", nullptr));
        comboBox_sort->setItemText(1, QCoreApplication::translate("MainWindow", "Stadium Name", nullptr));
        comboBox_sort->setItemText(2, QCoreApplication::translate("MainWindow", "Park Typology", nullptr));
        comboBox_sort->setItemText(3, QCoreApplication::translate("MainWindow", "Date Opened", nullptr));
        comboBox_sort->setItemText(4, QCoreApplication::translate("MainWindow", "Seating Capacity", nullptr));

        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Team Info", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_souvenirInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Souvenir", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_souvenirInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_teamInfo->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Team Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_teamInfo->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Stadium Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_teamInfo->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Seating Capacity", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_teamInfo->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_teamInfo->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Playing Surface", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_teamInfo->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "League", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_teamInfo->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Date Opened", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_teamInfo->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Distance To Field", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_teamInfo->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Typology", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_teamInfo->verticalHeaderItem(9);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Roof Type", nullptr));

        const bool __sortingEnabled = tableWidget_teamInfo->isSortingEnabled();
        tableWidget_teamInfo->setSortingEnabled(false);
        tableWidget_teamInfo->setSortingEnabled(__sortingEnabled);

        pushButton_add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
