#include "fractioninput.h"

FractionInput::FractionInput(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
}

void FractionInput::on_spinNumerator_valueChanged(const int numerator)
{
    int denominator = spinDenominator->value();
    if (numerator > denominator) {
        denominator = numerator;
        spinDenominator->setValue(denominator);
    }
    emit valueChanged(numerator, denominator);
}

void FractionInput::on_spinDenominator_valueChanged(const int denominator)
{
    int numerator = spinNumerator->value();
    if (numerator > denominator) {
        numerator = denominator;
        spinNumerator->setValue(numerator);
    }
    emit valueChanged(numerator, denominator);
}
