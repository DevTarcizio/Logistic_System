#ifndef REGISTERDRIVERDIALOG_H
#define REGISTERDRIVERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "../services/driverservice.h"

namespace Ui {
class RegisterDriverDialog;
}

class RegisterDriverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDriverDialog(QWidget *parent = nullptr);
    ~RegisterDriverDialog();

private slots:
    void on_btnSalvar_clicked();

private:
    Ui::RegisterDriverDialog *ui;
    DriverService driverService;
};

#endif // REGISTERDRIVERDIALOG_H
