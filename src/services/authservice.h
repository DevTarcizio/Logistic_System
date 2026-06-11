#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <QObject>
#include <QString>

class AuthService : public QObject
{
    Q_OBJECT

public:
    static AuthService& instance();

    void setToken(const QString &token);
    QString getToken() const;

private:
    explicit AuthService(QObject *parent = nullptr);
    QString jwt_token;
};

#endif // AUTHSERVICE_H
