#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fractionwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FractionWidget *fw = new FractionWidget(ui->widget);

    fw->setFraction(ui->spinNumerator->value(),
                    ui->spinDenominator->value());
    connect(ui->spinNumerator, SIGNAL(valueChanged(int)),
            fw, SLOT(numeratorChanged(int)));
    connect(ui->spinDenominator, SIGNAL(valueChanged(int)),
            fw, SLOT(denominatorChanged(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinNumerator_valueChanged(int numerator)
{
    int denominator = ui->spinDenominator->value();
    if (numerator >= denominator) {
        ui->spinDenominator->setValue(numerator);
    }
}

void MainWindow::on_spinDenominator_valueChanged(int denominator)
{
    int numerator = ui->spinNumerator->value();
    if (numerator >= denominator) {
        ui->spinNumerator->setValue(denominator);
    }

}
