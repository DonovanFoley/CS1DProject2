#ifndef TRIPDIALOG_H
#define TRIPDIALOG_H

#include <QDialog>
#include "map.h"

namespace Ui {
class TripDialog;
}

class TripDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TripDialog(QWidget *parent = nullptr);
    void getTeams(Map teams);
    ~TripDialog();

private slots:
    void on_pushButton_previous_clicked();

    void on_pushButton_next_clicked();

private:
    Map _teams;
    int index;
    Ui::TripDialog *ui;
};

#endif // TRIPDIALOG_H
