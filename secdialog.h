#ifndef SECDIALOG_H
#define SECDIALOG_H
#include "request_form.h"
#include <QDebug>
#include "admin_view.h"

#include <QDialog>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = 0, const QString username=0);
    QString sesion;
    ~SecDialog();



private slots:
    void on_goto_request_clicked();

    void on_goto_tracking_clicked();

    void on_goto_sells_clicked();

    void on_goto_inventory_clicked();

private:
    Ui::SecDialog *ui;
    request_form * req;
    Admin_View * admin;
    //definir aqui las demas ventanas
};

#endif // SECDIALOG_H
