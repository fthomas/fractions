#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

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

private:
    Ui::MainWindow *ui;

private slots:
    void on_spinN1_valueChanged(int numerator);
    void on_spinN2_valueChanged(int numerator);
    void on_spinN3_valueChanged(int numerator);
    void on_spinN4_valueChanged(int numerator);
    void on_spinN5_valueChanged(int numerator);
    void on_spinD1_valueChanged(int denominator);
    void on_spinD2_valueChanged(int denominator);
    void on_spinD3_valueChanged(int denominator);
    void on_spinD4_valueChanged(int denominator);
    void on_spinD5_valueChanged(int denominator);
};

#endif // MAINWINDOW_H
