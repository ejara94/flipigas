#include "vista_pedidos.h"
#include "ui_vista_pedidos.h"
#include <QStandardItemModel>
#include <QMessageBox>

Vista_Pedidos::Vista_Pedidos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vista_Pedidos)
{
    ui->setupUi(this);
    u=0;
}

Vista_Pedidos::~Vista_Pedidos()
{
    delete ui;
}


void Vista_Pedidos::on_Botton_Visualizar_clicked()
{

    u++;

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem("catalitico"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem("15"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem("2"));

}

void Vista_Pedidos::on_Botton_Entregar_clicked()
{
    ui->tableWidget->setRowCount(0);
    QMessageBox::information(this,tr("Operacion Exitosa"),tr("Solicitudes entregadas con exito!"));

}
