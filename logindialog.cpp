#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

bool LoginDialog::ok()
{
    return _ok;
}
QString LoginDialog::password()
{
    return _password;
}

void LoginDialog::on_pushButton_cancel_clicked()
{
    _ok = false;
    close();
}

void LoginDialog::on_pushButton_ok_clicked()
{
    _password = ui->lineEdit_password->text();
    _ok = true;
    close();
}

void LoginDialog::reset()
{
    _ok = false;
    _password = "";
    ui->lineEdit_password->clear();
}
