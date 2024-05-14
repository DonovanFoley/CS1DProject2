#include "tripdialog.h"
#include "iostream"
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

void TripDialog::getTeams(QVector<Team> teams)
{
    index = 0;
    _teams = teams;
    displayTeamInfo();
    ui->groupBox_teamInfo->show();
    ui->pushButton_previous->setDisabled(true);
    ui->pushButton_next->setText("Next");
}

void TripDialog::on_pushButton_previous_clicked()
{
    index--;
    ui->pushButton_previous->setEnabled(index != 0);
    ui->pushButton_next->setText("Next");
    ui->groupBox_teamInfo->show();
    displayTeamInfo();
}

void TripDialog::on_pushButton_next_clicked()
{
    index++;
    //If the user clicks the "finish" button
    if (index == _teams.size() + 1) {
        close();
    }
    //If the user clicks "next" on the last team (display end screen)
    else if (index == _teams.size()) {
        ui->groupBox_teamInfo->hide();
        ui->pushButton_next->setText("Finish");
        ui->label_teamName->setText("Finished!");
    } else {
        displayTeamInfo();
    }
    ui->pushButton_previous->setEnabled(true);
}

void TripDialog::displayTeamInfo()
{
    ui->label_teamName->setText(_teams[index].teamName());
    ui->label_stadiumName->setText("Stadium Name: " + _teams[index].stadiumName());
    ui->label_seatingCapacity->setText("Seating Capacity: "
                                       + QString::number(_teams[index].seatingCapacity()));
    ui->label_location->setText("Location: " + _teams[index].location());
    ui->label_playingSurface->setText("Playing Surface: " + _teams[index].playingSurface());
    ui->label_league->setText("League: " + _teams[index].league());
    ui->label_dateOpened->setText("Date Opened: " + QString::number(_teams[index].dateOpened()));
    ui->label_distanceToField->setText("Distance To Field: "
                                       + QString::number(_teams[index].distanceToField()));
    ui->label_typology->setText("Typology: " + _teams[index].typology());
    ui->label_rooftype->setText("Rooftype: " + _teams[index].rooftype());
}
