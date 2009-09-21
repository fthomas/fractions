#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fractionwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FractionWidget *fw1 = new FractionWidget();
    FractionWidget *fw2 = new FractionWidget(ui->widget2);
    FractionWidget *fw3 = new FractionWidget(ui->widget3);
    FractionWidget *fw4 = new FractionWidget(ui->widget4);
    FractionWidget *fw5 = new FractionWidget(ui->widget5);

    ui->horizontalLayout1->addWidget(fw1);

    fw1->setColors(Qt::white, QColor(0,255,0), QColor(128,255,128));
    fw2->setColors(Qt::white, QColor(255,0,191), QColor(255,128,223));
    fw3->setColors(Qt::white, QColor(43,116,199), QColor(96,148,207));
    fw4->setColors(Qt::white, QColor(255,213,0), QColor(255,255,0));
    fw5->setColors(Qt::white, QColor(255,0,0), QColor(255,128,128));

    fw1->setFraction(ui->spinN1->value(), ui->spinD1->value());
    fw2->setFraction(ui->spinN2->value(), ui->spinD2->value());
    fw3->setFraction(ui->spinN3->value(), ui->spinD3->value());
    fw4->setFraction(ui->spinN4->value(), ui->spinD4->value());
    fw5->setFraction(ui->spinN5->value(), ui->spinD5->value());

    connect(ui->spinN1, SIGNAL(valueChanged(int)), fw1, SLOT(setNumerator(int)));
    connect(ui->spinD1, SIGNAL(valueChanged(int)), fw1, SLOT(setDenominator(int)));

    connect(ui->spinN2, SIGNAL(valueChanged(int)), fw2, SLOT(setNumerator(int)));
    connect(ui->spinD2, SIGNAL(valueChanged(int)), fw2, SLOT(setDenominator(int)));

    connect(ui->spinN3, SIGNAL(valueChanged(int)), fw3, SLOT(setNumerator(int)));
    connect(ui->spinD3, SIGNAL(valueChanged(int)), fw3, SLOT(setDenominator(int)));

    connect(ui->spinN4, SIGNAL(valueChanged(int)), fw4, SLOT(setNumerator(int)));
    connect(ui->spinD4, SIGNAL(valueChanged(int)), fw4, SLOT(setDenominator(int)));

    connect(ui->spinN5, SIGNAL(valueChanged(int)), fw5, SLOT(setNumerator(int)));
    connect(ui->spinD5, SIGNAL(valueChanged(int)), fw5, SLOT(setDenominator(int)));
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

void MainWindow::on_spinN2_valueChanged(int numerator)
{
    int denominator = ui->spinD2->value();
    if (numerator >= denominator) {
        ui->spinD2->setValue(numerator);
    }
}

void MainWindow::on_spinN3_valueChanged(int numerator)
{
    int denominator = ui->spinD3->value();
    if (numerator >= denominator) {
        ui->spinD3->setValue(numerator);
    }
}

void MainWindow::on_spinN4_valueChanged(int numerator)
{
    int denominator = ui->spinD4->value();
    if (numerator >= denominator) {
        ui->spinD4->setValue(numerator);
    }
}

void MainWindow::on_spinN5_valueChanged(int numerator)
{
    int denominator = ui->spinD5->value();
    if (numerator >= denominator) {
        ui->spinD5->setValue(numerator);
    }
}

void MainWindow::on_spinD1_valueChanged(int denominator)
{
    int numerator = ui->spinN1->value();
    if (numerator >= denominator) {
        ui->spinN1->setValue(denominator);
    }

}

void MainWindow::on_spinD2_valueChanged(int denominator)
{
    int numerator = ui->spinN2->value();
    if (numerator >= denominator) {
        ui->spinN2->setValue(denominator);
    }

}

void MainWindow::on_spinD3_valueChanged(int denominator)
{
    int numerator = ui->spinN3->value();
    if (numerator >= denominator) {
        ui->spinN3->setValue(denominator);
    }

}

void MainWindow::on_spinD4_valueChanged(int denominator)
{
    int numerator = ui->spinN4->value();
    if (numerator >= denominator) {
        ui->spinN4->setValue(denominator);
    }

}

void MainWindow::on_spinD5_valueChanged(int denominator)
{
    int numerator = ui->spinN5->value();
    if (numerator >= denominator) {
        ui->spinN5->setValue(denominator);
    }

}
