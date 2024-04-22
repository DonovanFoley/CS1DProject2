#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    bool ok();
    QString password();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::LoginDialog *ui;
    bool _ok;
    QString _password;
};

#endif // LOGINDIALOG_H
