#ifndef REGISTERDRIVERDIALOG_H
#define REGISTERDRIVERDIALOG_H

#include <QDialog>

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
};

#endif // REGISTERDRIVERDIALOG_H
