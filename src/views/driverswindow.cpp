#include "driverswindow.h"
#include "ui_driverswindow.h"
#include "registerdriverdialog.h"

DriversWindow::DriversWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DriversWindow)
{
    ui->setupUi(this);

    connect(
        &driverService,
        &DriverService::driversLoaded,
        this,
        &DriversWindow::onDriversLoaded
        );

    connect(
        &driverService,
        &DriverService::driverDeleted,
        this,
        [this]()
        {
            driverService.listDrivers();
        });

    driverService.listDrivers();
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

void DriversWindow::onDriversLoaded(const QJsonArray &drivers){
    ui->tableMotoristas->clearContents();
    ui->tableMotoristas->setRowCount(drivers.size());

    for (int row = 0; row < drivers.size(); row++) {
        QJsonObject driver = drivers[row].toObject();

        ui->tableMotoristas->setItem(
            row,
            0,
            new QTableWidgetItem(QString::number(driver["id"].toInt()))
        );

        ui->tableMotoristas->setItem(
            row,
            1,
            new QTableWidgetItem(driver["name"].toString())
        );

        ui->tableMotoristas->setItem(
            row,
            2,
            new QTableWidgetItem(driver["telephone_number"].toString())
        );
    }
}
void DriversWindow::on_btnApagarMotorista_clicked()
{
    int row = ui->tableMotoristas->currentRow();

    if(row < 0)
    {
        return;
    }

    int id = ui->tableMotoristas->item(row, 0)->text().toInt();

    driverService.deleteDriver(id);
}

