/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_ok;
    QLineEdit *lineEdit_password;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(400, 150);
        pushButton_cancel = new QPushButton(LoginDialog);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(180, 90, 93, 29));
        pushButton_ok = new QPushButton(LoginDialog);
        pushButton_ok->setObjectName("pushButton_ok");
        pushButton_ok->setGeometry(QRect(290, 90, 93, 29));
        lineEdit_password = new QLineEdit(LoginDialog);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(20, 40, 361, 26));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("LoginDialog", "Cancel", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("LoginDialog", "Ok", nullptr));
    } // retranslateUi
};

namespace Ui {
class LoginDialog : public Ui_LoginDialog
{};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
