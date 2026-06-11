#include "authservice.h"

AuthService::AuthService(QObject *parent)
    : QObject(parent)
{
}

AuthService& AuthService::instance()
{
    static AuthService instance;
    return instance;
}

void AuthService::setToken(const QString &token)
{
    jwt_token = token;
}

QString AuthService::getToken() const
{
    return jwt_token;
}