#include "driverservice.h"
#include "authservice.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>


DriverService::DriverService(QObject *parent)
    : QObject{parent}
{
    networkManager = new QNetworkAccessManager(this);
}

void DriverService::createDriver(const QString &nome,
                                 const QString &telefone)
{
    QUrl url("http://127.0.0.1:8000/drivers/register_driver");
    QNetworkRequest request(url);

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
        );

    request.setRawHeader(
        "Authorization",
        QString("Bearer %1")
            .arg(AuthService::instance().getToken())
            .toUtf8()
        );

    QJsonObject json;
    json["name"] = nome;
    json["telephone_number"] = telefone;

    QJsonDocument doc(json);

    QNetworkReply *reply = networkManager->post(
        request,
        doc.toJson()
        );

    connect(reply, &QNetworkReply::finished, this, [this, reply]()
    {
        int status = reply->attribute(
            QNetworkRequest::HttpStatusCodeAttribute
                              ).toInt();

        if (status == 200 || status == 201)
        {
            emit driverCreated();
        }
        else
        {
            emit requestError(reply->errorString());
        }

        reply->deleteLater();
    });
}

void DriverService::listDrivers() {
    QUrl url("http://127.0.0.1:8000/drivers/list");
    QNetworkRequest request(url);

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
        );

    request.setRawHeader(
        "Authorization",
        QString("Bearer %1")
            .arg(AuthService::instance().getToken())
            .toUtf8()
        );

    QNetworkReply *reply = networkManager->get(request);
    qDebug() << "Resposta recebida da API";

    connect(reply, &QNetworkReply::finished, this,
            [this, reply]()
            {
        if(reply->error() != QNetworkReply::NoError){
            emit requestError(reply->errorString());
            reply->deleteLater();
            return;
        }

        QByteArray response = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response);

        if(doc.isObject()){
            QJsonObject obj = doc.object();
            QJsonArray drivers = obj["drivers"].toArray();

            qDebug() << "Emitindo lista de motoristas";
            emit driversLoaded(drivers);
        } else {
            emit requestError("Resposta inválida da API");
        }

        reply->deleteLater();
    });
}