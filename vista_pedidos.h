#ifndef VISTA_PEDIDOS_H
#define VISTA_PEDIDOS_H
#include <dbmanager.h>


#include <QDialog>

namespace Ui {
class Vista_Pedidos;
}

class Vista_Pedidos : public QDialog
{
    Q_OBJECT

public:
    explicit Vista_Pedidos(QWidget *parent = 0);
    ~Vista_Pedidos();
    DBManager * db;


private slots:

    void on_Botton_Visualizar_clicked();

    void on_Botton_Entregar_clicked();

private:
    Ui::Vista_Pedidos *ui;
    int u;

};

#endif // VISTA_PEDIDOS_H
