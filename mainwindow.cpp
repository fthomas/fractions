#include <QList>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fractioninput.h"
#include "fractionimage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<FractionInput*> finp;
    QList<FractionImage*> fimg;

    for (int i = 0; i <= 4; i++) {
        finp << new FractionInput();
        fimg << new FractionImage();
        connect(finp[i], SIGNAL(valueChanged(int, int)),
                fimg[i], SLOT(setFraction(int, int)));
        QHBoxLayout* layout = findChild<QHBoxLayout*>(
                QString("horizontalLayout_%1").arg(i) );
        layout->addWidget(finp[i]);
        layout->addWidget(fimg[i]);
    }

    fimg[0]->setColors(Qt::white, QColor(  0,255,  0), QColor(128,255,128));
    fimg[1]->setColors(Qt::white, QColor(255,  0,191), QColor(255,128,223));
    fimg[2]->setColors(Qt::white, QColor( 43,116,199), QColor( 96,148,207));
    fimg[3]->setColors(Qt::white, QColor(255,213,  0), QColor(255,255,  0));
    fimg[4]->setColors(Qt::white, QColor(255,  0,  0), QColor(255,128,128));
}

MainWindow::~MainWindow()
{
    delete ui;
}
