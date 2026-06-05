#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_btnLogin_clicked()
{
    QString user = ui->txtUser->text();
    QString password = ui->txtPassword->text();

    if(user == "admin" && password == "1234")
    {
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(
            this,
            "Erro",
            "Usuário ou Senha inválidos"
            );
    }
}

