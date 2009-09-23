#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_actAdd = new QAction(QIcon(":/images/list-add.png"),
                            tr("&Add Fraction Bar"), this);
    m_actRemove = new QAction(QIcon(":/images/list-remove.png"),
                              tr("&Remove Fraction Bar"), this);

    connect(m_actAdd, SIGNAL(triggered()), this, SLOT(addFractionBar()));
    connect(m_actRemove, SIGNAL(triggered()), this, SLOT(removeFractionBar()));

    ui->mainToolBar->addAction(m_actAdd);
    ui->mainToolBar->addAction(m_actRemove);

    m_colors[0][0] = Qt::white;
    m_colors[1][0] = Qt::white;
    m_colors[2][0] = Qt::white;
    m_colors[3][0] = Qt::white;
    m_colors[4][0] = Qt::white;

    m_colors[0][1] = QColor(  0,255,  0); m_colors[0][2] = QColor(128,255,128);
    m_colors[1][1] = QColor(255,  0,191); m_colors[1][2] = QColor(255,128,223);
    m_colors[2][1] = QColor( 43,116,199); m_colors[2][2] = QColor( 96,148,207);
    m_colors[3][1] = QColor(255,213,  0); m_colors[3][2] = QColor(255,255,  0);
    m_colors[4][1] = QColor(255,  0,  0); m_colors[4][2] = QColor(255,128,128);

    addFractionBar();
    addFractionBar();
    addFractionBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addFractionBar()
{
    m_hbox.append(new QHBoxLayout());
    m_finp.append(new FractionInput());
    m_fimg.append(new FractionImage());

    int i = m_hbox.size()-1;

    m_fimg[i]->setColors(m_colors[i%5][0], m_colors[i%5][1], m_colors[i%5][2]);

    connect(m_finp[i], SIGNAL(valuesChanged(int, int)),
            m_fimg[i], SLOT(setFraction(int, int)));

    connect(m_fimg[i], SIGNAL(fractionChanged(int, int)),
            m_finp[i], SLOT(setValues(int, int)));

    m_hbox[i]->addWidget(m_finp[i]);
    m_hbox[i]->addWidget(m_fimg[i]);
    m_hbox[i]->setContentsMargins(4, 4, 4, 4);

    ui->centralLayout->addLayout(m_hbox[i]);
}

void MainWindow::removeFractionBar()
{
    int i = m_hbox.size()-1;
    if (i <= 0) {
        return;
    }

    delete m_fimg[i];
    delete m_finp[i];
    delete m_hbox[i];

    m_hbox.removeLast();
    m_finp.removeLast();
    m_fimg.removeLast();
}
