#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H
#include <dbmanager.h>

#include <QDialog>

namespace Ui {
class Admin_View;
}

class Admin_View : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_View(QWidget *parent = 0);
    ~Admin_View();
    DBManager * db;

private:
    Ui::Admin_View *ui;
};

#endif // ADMIN_VIEW_H
