#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <dbmanager.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = new DBManager("/home/ejara/SEMINARIO/flipigas/users.db");
    qDebug()<<"Aplicacion iniciada";
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug()<<"Conexion cerrada";
}


void MainWindow::on_pushButton_Entrar_clicked()
{
    QString username = ui->lineEdit_user->text();
    QString password = ui->lineEdit_pass->text();
    bool administrator = ui->radioButton_A->isChecked();
    //bool worker = ui->radioButton_O->isChecked();
    QString temp_admin;
    (administrator)?temp_admin="administrador":temp_admin="operario";

    //AQUI VA LA BUSQUEDA EN ARCHIVOS DE USUARIOS Y CONTRASENA VALIDOS

    if(db->personExists(username, password, temp_admin))
    {
        QMessageBox::information(this, "Sesion", "Sesion iniciada correctamente.\nBienvenido.");
        hide();
        secDialog = new SecDialog(this,username);
        secDialog->show();
    }
    else
    {
        QMessageBox::warning(this, "Sesion", "Usuario y/o contrasena incorrectos");
    }
}

void MainWindow::on_pushButton_signin_clicked()
{
    sign_in = new signin(this);
    sign_in->setModal(true);
    sign_in->setVisible(true);
}


