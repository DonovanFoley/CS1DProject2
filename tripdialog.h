#ifndef TRIPDIALOG_H
#define TRIPDIALOG_H

#include <QDialog>

namespace Ui {
class TripDialog;
}

class TripDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TripDialog(QWidget *parent = nullptr);
    ~TripDialog();

private:
    Ui::TripDialog *ui;
};

#endif // TRIPDIALOG_H
