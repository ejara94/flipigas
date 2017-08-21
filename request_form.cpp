#include "request_form.h"
#include "ui_request_form.h"
#include <QDebug>
#include <QMessageBox>
#include <QTextBlock>

request_form::request_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::request_form)
{
    ui->setupUi(this);
    this->setRequestNumber();
}

request_form::~request_form()
{
    delete ui;
}

QString request_form::setCerroinText(const QString &string)
{
    QTextCursor * cursor=new QTextCursor(ui->previewText->document()->findBlockByLineNumber(4));
    cursor->beginEditBlock();
    cursor->setKeepPositionOnInsert(true);
    cursor->select(cursor->BlockUnderCursor);
    cursor->removeSelectedText();
    cursor->insertText("Cerro de Destino:	"+string+"\n");
    cursor->endEditBlock();


    return string;
}

QString request_form::setPaymentinText(const QString &string)
{
    QTextCursor * cursor=new QTextCursor(ui->previewText->document()->findBlockByLineNumber(6));
    cursor->beginEditBlock();
    cursor->setKeepPositionOnInsert(true);
    cursor->select(cursor->BlockUnderCursor);
    cursor->removeSelectedText();
    cursor->insertText("Medio de Pago:	"+string+"\n");
    cursor->endEditBlock();
    return string;
}

QString request_form::setDetail(const QString &gal, const QString &quantity, const QString &catalitic)
{
    QTextCursor * cursor=new QTextCursor(ui->previewText->document()->findBlockByLineNumber(9));
    cursor->beginEditBlock();
    cursor->setKeepPositionOnInsert(true);
//    cursor->select(cursor->BlockUnderCursor);
//    cursor->removeSelectedText();
    QString s = "\n>"+quantity+" Gal_"+gal+"_"+catalitic;
    cursor->insertText(s);
    cursor->endEditBlock();
    return s;
}

QString request_form::setStimatedTime(const int &t)
{
    QString t_aux = QString::number(t);
    int lines = (db->calculateGalons())+10;

    QTextCursor * cursor=new QTextCursor(ui->previewText->document()->findBlockByLineNumber(lines));
    cursor->beginEditBlock();
    cursor->setKeepPositionOnInsert(true);
    cursor->select(cursor->BlockUnderCursor);
    cursor->removeSelectedText();
    QString s = "Tiempo Estimado de Entrega:   "+t_aux+"\n";
    cursor->insertText(s);
    cursor->endEditBlock();
    return s;
}

QString request_form::setTotal()
{
    int total = 0; //db->CalculateTotal()
    QString t_aux = QString::number(total);
    int lines = (db->calculateGalons())+12;

    QTextCursor * cursor=new QTextCursor(ui->previewText->document()->findBlockByLineNumber(lines));
    cursor->beginEditBlock();
    cursor->setKeepPositionOnInsert(true);
    cursor->select(cursor->BlockUnderCursor);
    cursor->removeSelectedText();
    QString s = "TOTAL:   "+t_aux+"\n";
    cursor->insertText(s);
    cursor->endEditBlock();
    return s;
}

QString request_form::setRequestNumber()
{
    QTextCursor * cursor=new QTextCursor(ui->previewText->document()->findBlockByLineNumber(2));
    cursor->beginEditBlock();
    cursor->setKeepPositionOnInsert(true);
    cursor->select(cursor->BlockUnderCursor);
    cursor->removeSelectedText();
    cursor->insertText("BOLETA N°:	    "+QString::number(db->calculateRequests())+"\n");
    cursor->endEditBlock();
    return "holi";
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

}

void request_form::on_commandLinkButton_clicked()
{
    db->addGalon(ui->comboBox_kg->currentText(), ui->spinBox_quantity->value(), ui->comboBox_catalitic->currentText());
    setDetail(ui->comboBox_kg->currentText(), ui->spinBox_quantity->text(),ui->comboBox_catalitic->currentText());
    setTotal();

    // in ui->previewText->document()->setPlainText( &text);
    //setDetail(ui->comboBox_kg->currentText(), ui->spinBox_quantity->value(), ui->comboBox_catalitic->currentText());

    //Ingresar detalle
}

void request_form::on_buttonBox_rejected()
{
    db->removeGalon();
}

void request_form::on_cerroComboBox_currentTextChanged(const QString &arg1)
{
    setCerroinText(arg1);
    setStimatedTime(0);
}

void request_form::on_payComboBox_currentTextChanged(const QString &arg1)
{
    setPaymentinText(arg1);
}
