#ifndef DRIVERSERVICE_H
#define DRIVERSERVICE_H

#include <QObject>
#include <QNetworkAccessManager>

class DriverService : public QObject
{
    Q_OBJECT
public:
    explicit DriverService(QObject *parent = nullptr);

    void createDriver(const QString &nome,
                      const QString &telefone);

    void listDrivers();

    void deleteDriver(int id);

private:
    QNetworkAccessManager *networkManager;

signals:
    void driverCreated();
    void driverDeleted();
    void driversLoaded(const QJsonArray &drivers);
    void requestError(const QString &error);
};

#endif // DRIVERSERVICE_H
