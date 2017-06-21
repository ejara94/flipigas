#include "signin.h"
#include "ui_signin.h"
#include "QWizard"
#include "QCloseEvent"
#include <QMessageBox>
#include <QDebug>
#include <QtSql>



signin::signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
    db = new DBManager("/home/ejara/SEMINARIO/flipigas/users.db");
}

signin::~signin()
{
    delete ui;
}

void signin::on_buttonBox_accepted()
{
    QString temp_admin;

    bool administrator = ui->radioButton_ad->isChecked();
    bool worker = ui->radioButton_op->isChecked();

    if(administrator && !worker)
    {
        temp_admin="administrador";
    }else{
        temp_admin="operario";
    }

    if(ui->lineEdit_pass->text() == ui->lineEdit_rpass->text())
    {
    this->db->addPerson(ui->lineEdit_user->text(),
                        ui->lineEdit_pass->text(),
                        ui->lineEdit_mail->text(),
                        temp_admin
                );
    }else{
        QMessageBox::warning(this, "Error", "Constraseñas no coinciden. Reintentar");
    }
    close();
}

void signin::on_buttonBox_rejected()
{
    close();
}
