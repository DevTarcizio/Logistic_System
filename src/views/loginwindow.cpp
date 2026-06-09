#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_btnLogin_clicked()
{
    QUrl url("http://127.0.0.1:8000/users/login");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("username", ui->txtUser->text());
    params.addQueryItem("password", ui->txtPassword->text());

    QNetworkReply *reply = manager->post(request, params.query().toUtf8());

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(response);
            QJsonObject obj = doc.object();
            jwtToken = obj["access_token"].toString();

            qDebug() << "Login Realizado com Sucesso!";

            MainWindow *mainWindow = new MainWindow();
            mainWindow->show();
            this->close();
        } else {
            qDebug() << "Erro login: " << reply->errorString();
        }

        reply->deleteLater();
    });
}

