#ifndef DRIVERSWINDOW_H
#define DRIVERSWINDOW_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonObject>

#include "../services/driverservice.h"

namespace Ui {
class DriversWindow;
}

class DriversWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DriversWindow(QWidget *parent = nullptr);
    ~DriversWindow();

private slots:
    void on_btnCriarMotorista_clicked();
    void onDriversLoaded(const QJsonArray &drivers);

private:
    Ui::DriversWindow *ui;

    DriverService driverService;
};

#endif // DRIVERSWINDOW_H
