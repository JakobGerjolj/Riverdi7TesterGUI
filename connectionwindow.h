#ifndef CONNECTIONWINDOW_H
#define CONNECTIONWINDOW_H

#include <QDialog>

namespace Ui {
class Connectionwindow;
}

class Connectionwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Connectionwindow(QWidget *parent = nullptr);
    ~Connectionwindow();

private:
    Ui::Connectionwindow *ui;
};

#endif // CONNECTIONWINDOW_H
