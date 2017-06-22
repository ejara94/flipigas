#include "table_request.h"
#include "ui_table_request.h"

Table_Request::Table_Request(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table_Request)
{
    ui->setupUi(this);
}

Table_Request::~Table_Request()
{
    delete ui;
}
