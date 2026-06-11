#include "driverswindow.h"
#include "ui_driverswindow.h"
#include "registerdriverdialog.h"

DriversWindow::DriversWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DriversWindow)
{
    ui->setupUi(this);
}

DriversWindow::~DriversWindow()
{
    delete ui;
}

void DriversWindow::on_btnCriarMotorista_clicked()
{
    RegisterDriverDialog dialog(this);
    dialog.exec();
}

