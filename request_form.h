#ifndef REQUEST_FORM_H
#define REQUEST_FORM_H
#include <dbmanager.h>
#include <QTime>

#include <QDialog>

namespace Ui {
class request_form;
}

class request_form : public QDialog
{
    Q_OBJECT

public:
    explicit request_form(QWidget *parent = 0);
    ~request_form();
    DBManager * db;
//    QString ;

public slots:
    QString on_cerroComboBox_currentTextChanged(const QString &arg1);
private slots:
    void on_buttonBox_accepted();

    void on_commandLinkButton_clicked();

    void on_buttonBox_rejected();

    QString on_payComboBox_currentTextChanged(const QString &arg1);

private:
    Ui::request_form *ui;
};

#endif // REQUEST_FORM_H
