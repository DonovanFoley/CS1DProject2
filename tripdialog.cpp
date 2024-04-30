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
