#ifndef REQUEST_FORM_H
#define REQUEST_FORM_H

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

private slots:
    void on_buttonBox_accepted();

private:
    Ui::request_form *ui;
};

#endif // REQUEST_FORM_H
