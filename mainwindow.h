#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QtGui/QMainWindow>
#include "fractioninput.h"
#include "fractionimage.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addFractionBar();
    void removeFractionBar();

private:
    Ui::MainWindow *ui;
    QAction *m_actAdd,
            *m_actRemove;
    QColor m_colors[6][3];
    QList<QHBoxLayout*> m_hbox;
    QList<FractionInput*> m_finp;
    QList<FractionImage*> m_fimg;
};

#endif // MAINWINDOW_H
