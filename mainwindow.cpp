#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinNumerator_valueChanged(int numerator)
{
    int denominator = ui->spinDenominator->value();
    if (numerator >= denominator)
        ui->spinDenominator->setValue(numerator);
}

void MainWindow::on_spinDenominator_valueChanged(int denominator)
{
    int numerator = ui->spinNumerator->value();
    if (numerator >= denominator)
        ui->spinNumerator->setValue(denominator);

}
