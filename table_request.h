#ifndef TABLE_REQUEST_H
#define TABLE_REQUEST_H

#include <QDialog>

namespace Ui {
class Table_Request;
}

class Table_Request : public QDialog
{
    Q_OBJECT

public:
    explicit Table_Request(QWidget *parent = 0);
    ~Table_Request();

private:
    Ui::Table_Request *ui;
};

#endif // TABLE_REQUEST_H