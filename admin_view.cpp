#include "admin_view.h"
#include "ui_admin_view.h"

Admin_View::Admin_View(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_View)
{
    ui->setupUi(this);
}

Admin_View::~Admin_View()
{
    delete ui;
}
