#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DBManager
{

public:
    DBManager(const QString& path);
    bool addPerson(const QString& user,
                   const QString& password,
                   const QString& mail,
                   const QString& type);
    bool removePerson(const QString& user);
    bool personExists(const QString &user, const QString &pass, const QString &admin);

    bool addRequest(const QString& hill,
                    const QString& payment,
                    const QString& hour);
    bool addGalon(const QString& type,
                  const int quantity,
                  const QString& catalitic);
    int calculateRequests();
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
