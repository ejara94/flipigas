#include "request_form.h"
#include "ui_request_form.h"
#include <QDebug>
#include <QMessageBox>

request_form::request_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::request_form)
{
    ui->setupUi(this);
}

request_form::~request_form()
{
    delete ui;
}

void request_form::on_buttonBox_accepted()
{
    QTime time=QTime::currentTime();
    QString timeString=time.toString();
    bool succes = db->addRequest( ui->cerroComboBox->currentText(),
                                  ui->payComboBox->currentText(),
                                  timeString);
    if(succes)
    {
        QMessageBox::information(this, "Solicitud", "Solicitud ingresada correctamente.");
    }else{
        QMessageBox::warning(this, "Solicitud", "Error en el ingreso de la solicitud.");
    }


    //mostrar texto en el lineText
   // if(values de las otras weasChanged)
            //recalcula el texto
            //setText
            //blocksignals
}

void request_form::on_commandLinkButton_clicked()
{
    db->addGalon(ui->comboBox_kg->currentText(), ui->spinBox_quantity->value(), ui->comboBox_catalitic->currentText());
}

void request_form::on_buttonBox_rejected()
{
    db->removeGalon();
}

QString request_form::on_cerroComboBox_currentTextChanged(const QString &arg1)
{
    qDebug()<<arg1;
    return arg1;
}

QString request_form::on_payComboBox_currentTextChanged(const QString &arg1)
{
    qDebug()<<arg1;
    return arg1;
}
