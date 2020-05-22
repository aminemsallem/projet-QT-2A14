#include "statss.h"
#include "ui_statss.h"

Statss::Statss(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statss)
{
    ui->setupUi(this);
}

Statss::~Statss()
{
    delete ui;
}
