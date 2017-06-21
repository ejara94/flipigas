#include <dbmanager.h>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

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

bool DBManager::addRequest(const QString &hill, const QString &payment,  const QString &hour)
{
    QSqlQuery query;

    query.prepare("INSERT INTO requests (hour, hill, payment) "
                  "VALUES (:hour, :hill, :payment);");
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

bool DBManager::addGalon(const QString &type, const int quantity, const QString &catalitic)
{
    //preguntarle a la bd por el pedido actual
    QSqlQuery query;
    int aux_id_pedido = calculateRequests() + 1;
    query.prepare("INSERT INTO galons (id_request, type, quantity, catalitic) "
                  "VALUES (:id_request, :type, :quantity, :catalitic);");
    query.bindValue(":id_request",aux_id_pedido);
    query.bindValue(":type", type);
    query.bindValue(":quantity", quantity);
    query.bindValue(":catalitic", catalitic);
    bool success = query.exec();
    if(!success)
        {
            qDebug()<<"addGalon error: "
                    << query.lastError();
            return false;
        }
    return true;

}

int DBManager::calculateRequests(){

    QSqlQuery query;
    query.prepare("SELECT last_insert_rowid() FROM requests;");
    int aux_id=0;
    if(query.exec())
    {

        while(query.next())
        {
            aux_id++;
        }
    }
    return aux_id;
}


