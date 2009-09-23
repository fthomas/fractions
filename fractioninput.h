#ifndef FRACTIONINPUT_H
#define FRACTIONINPUT_H

#include <QWidget>
#include <ui_fractioninput.h>

class FractionInput : public QWidget,
                      public Ui::FractionInput
{
    Q_OBJECT

public:
    FractionInput(QWidget *parent = 0);

signals:
    void valuesChanged(int numerator, int denominator);

public slots:
    void setValues(const int numerator, const int denominator);

private slots:
    void on_spinNumerator_valueChanged(const int numerator);
    void on_spinDenominator_valueChanged(const int denominator);
};

#endif // FRACTIONINPUT_H
