#include "request_form.h"
#include "ui_request_form.h"
#include <QDebug>

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
   db->addRequest( ui->gal7->value(),
                   ui->gal15->value(),
                   ui->gal45->value(),
                   ui->cerroComboBox->currentText(),
                   ui->payComboBox->currentText(),
                   timeString);

    //mostrar texto en el lineText
    // Ingresarlos a la ... db?
}
