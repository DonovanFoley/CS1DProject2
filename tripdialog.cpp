#include "tripdialog.h"
#include "ui_tripdialog.h"

TripDialog::TripDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TripDialog)
{
    ui->setupUi(this);
}

TripDialog::~TripDialog()
{
    delete ui;
}

void TripDialog::getTeams(Map teams)
{
    index = 0;
    _teams = teams;
    ui->label_teamName->setText(_teams(index)->teamName());
    ui->pushButton_previous->setDisabled(true);
    ui->pushButton_next->setText("Next");
}

void TripDialog::on_pushButton_previous_clicked()
{
    index--;
    ui->pushButton_previous->setEnabled(index != 0);
    ui->label_teamName->setText(_teams(index)->teamName());
    ui->pushButton_next->setText("Next");
}


void TripDialog::on_pushButton_next_clicked()
{
    index++;
    if (index == _teams.size() + 1)
    {
        close();
    }
    else if (index == _teams.size())
    {
        ui->pushButton_next->setText("Finish");
        ui->label_teamName->setText("Finished!");
    }
    else
    {
        ui->label_teamName->setText(_teams(index)->teamName());
        ui->pushButton_previous->setEnabled(true);
    }

}

