#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fractionwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FractionWidget *fw = new FractionWidget(ui->widget1);

    fw->setFraction(ui->spinN1->value(),
                    ui->spinD1->value());
    connect(ui->spinN1, SIGNAL(valueChanged(int)),
            fw, SLOT(setNumerator(int)));
    connect(ui->spinD1, SIGNAL(valueChanged(int)),
            fw, SLOT(setDenominator(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinN1_valueChanged(int numerator)
{
    int denominator = ui->spinD1->value();
    if (numerator >= denominator) {
        ui->spinD1->setValue(numerator);
    }
}

void MainWindow::on_spinD1_valueChanged(int denominator)
{
    int numerator = ui->spinN1->value();
    if (numerator >= denominator) {
        ui->spinN1->setValue(denominator);
    }

}
