#ifndef STATSS_H
#define STATSS_H

#include <QWidget>

namespace Ui {
class Statss;
}

class Statss : public QWidget
{
    Q_OBJECT

public:
    explicit Statss(QWidget *parent = 0);
    ~Statss();

private:
    Ui::Statss *ui;
};

#endif // STATSS_H
