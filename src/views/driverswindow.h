#ifndef DRIVERSWINDOW_H
#define DRIVERSWINDOW_H

#include <QWidget>

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

private:
    Ui::DriversWindow *ui;
};

#endif // DRIVERSWINDOW_H
