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

    bool addRequest(const int& gal7,
                    const int& gal15,
                    const int& gal45,
                    const QString& hill,
                    const QString& payment,
                    const QString& hour);
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
