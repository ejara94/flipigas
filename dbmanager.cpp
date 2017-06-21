#include <dbmanager.h>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

DBManager::DBManager(const QString &path)
{
       m_db = QSqlDatabase::addDatabase("QSQLITE");
     //  path ="/home/ejara/SEMINARIO/flipigas/users.db";
       m_db.setDatabaseName(path);

       if (!m_db.open())
       {
          qDebug() << "Error: connection with database fail";
       }
       else
       {
          qDebug() << "Database: connection ok";
       }

}

bool DBManager::addPerson(const QString& user,
                          const QString& password,
                          const QString& mail,
                          const QString& type)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO users (user, password, mail, type) VALUES (:user, :password, :mail, :type)");
   query.bindValue(":user", user);
   query.bindValue(":password", password);
   query.bindValue(":mail", mail);
   query.bindValue(":type", type);

   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addPerson error:  "
                 << query.lastError();
   }

   return success;
}

bool DBManager::removePerson(const QString &user)
{
    if (1)
    {
       QSqlQuery query;
       query.prepare("DELETE FROM users WHERE user = :user");
       query.bindValue(":user", user);
       bool success = query.exec();

       if(!success)
       {
           qDebug() << "removePerson error: "
                    << query.lastError();
           return false;
       }
    }return true;
}

bool DBManager::personExists(const QString &user, const QString &pass, const QString &admin)
{
    bool r;
    QSqlQuery query;
    query.prepare("SELECT user, password, type FROM users WHERE user = :user AND password = :password AND type = :type;");
    query.bindValue(":user", user);
    query.bindValue(":password", pass);
    query.bindValue(":type", admin);
    qDebug() << user;
    qDebug() << pass;
    qDebug() << admin;

    if (query.exec())
    {
        qDebug()<<query.nextResult()+"----next result";
       if (query.next())
       {
          r = true;
       }else{

          r = false;
       }
    }
    return r;
}

bool DBManager::addRequest(const int &gal7, const int &gal15, const int &gal45, const QString &hill, const QString &payment,  const QString &hour)
{
    QSqlQuery query;

    query.prepare("INSERT INTO requests (seven_gal, fifteen_gal, fourty_five_gal, hill, payment, hour) "
                  "VALUES (:7_gal, :15_gal, :45_gal, :hill, :payment, :hour);");
    query.bindValue(":7_gal", gal7);
    query.bindValue(":15_gal", gal15);
    query.bindValue(":45_gal", gal45);
    query.bindValue(":hill", hill);
    query.bindValue(":payment", payment);
    query.bindValue(":hour", hour);
    bool success = query.exec();

    if(!success)
    {
        qDebug() << "addRequest error: "
                 << query.lastError();
        return false;
    }
    return true;
}

