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

private:
    QNetworkAccessManager *networkManager;

signals:
    void driverCreated();
    void requestError(QString error);
};

#endif // DRIVERSERVICE_H
