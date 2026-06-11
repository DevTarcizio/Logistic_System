#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "driverswindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setToken(const QString &token)
{
    jwtToken = token;
}

void MainWindow::on_btnMotoristas_clicked()
{
    DriversWindow *driverWindow = new DriversWindow(this);
    driverWindow->show();
}

