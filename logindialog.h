#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

/**
 * @brief The LoginDialog class provides a dialog interface for user authentication.
 *
 * This class manages user inputs for login credentials, providing methods to retrieve
 * the entered password and the status of the dialog (OK or Cancel).
 */
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a LoginDialog with an optional parent widget.
     *
     * @param parent The parent widget of this dialog, default is nullptr.
     */
    explicit LoginDialog(QWidget *parent = nullptr);

    /**
     * @brief Destroys the LoginDialog.
     */
    ~LoginDialog();

    /**
     * @brief Returns the status of the dialog whether the OK button was clicked.
     *
     * @return True if the OK button was clicked, false otherwise.
     */
    bool ok();

    /**
     * @brief Retrieves the password entered by the user.
     *
     * @return The entered password as a QString.
     */
    QString password();

    /**
     * @brief Resets the dialog inputs and status.
     *
     * This function clears the password field and sets the status to not OK.
     */
    void reset();

private slots:
    /**
     * @brief Slot connected to the Cancel button click event.
     *
     * Handles the logic when the Cancel button is clicked, closing the dialog without authentication.
     */
    void on_pushButton_cancel_clicked();

    /**
     * @brief Slot connected to the OK button click event.
     *
     * Handles the logic when the OK button is clicked, authenticating the user and closing the dialog.
     */
    void on_pushButton_ok_clicked();

private:
    Ui::LoginDialog *ui; ///< Pointer to the user interface for the LoginDialog.
    bool _ok; ///< Flag indicating whether the OK button was clicked.
    QString _password; ///< Stores the password entered by the user.
};

#endif // LOGINDIALOG_H
