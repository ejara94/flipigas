#include "request_form.h"
#include "ui_request_form.h"
#include <QDebug>
#include <QMessageBox>

request_form::request_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::request_form)
{
    ui->setupUi(this);
    //QObject::connect(this, ui->gal7->valueChanged(1);, this, SLOT(set_paragraph));
}

request_form::~request_form()
{
    delete ui;
}

void request_form::on_buttonBox_accepted()
{
    QTime time=QTime::currentTime();
    QString timeString=time.toString();
 /*   db->addRequest(
                    ui->cerroComboBox->currentText(),
                    ui->payComboBox->currentText(),
                    timeString);

 */
    QMessageBox::information(this, "Solicitud", "Solicitud ingresada correctamente.\nBienvenido.");

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
