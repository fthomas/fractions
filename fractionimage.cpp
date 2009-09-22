#include <QColor>
#include <QLinearGradient>
#include <QPainter>
#include <QPen>
#include "fractionimage.h"

FractionImage::FractionImage(QWidget *parent)
    : QWidget(parent)
{
    m_numerator = 0;
    m_denominator = 1;
    setColors();
}

void FractionImage::setColors(const QColor &lineColor,
                              const QColor &gradientColor0,
                              const QColor &gradientColor1)
{
    m_lineColor = lineColor;
    m_gradientColor0 = gradientColor0;
    m_gradientColor1 = gradientColor1;
}

void FractionImage::setNumerator(const int numerator)
{
    m_numerator = numerator;
    update();
}

void FractionImage::setDenominator(const int denominator)
{
    m_denominator = denominator;
    update();
}

void FractionImage::setFraction(const int numerator, const int denominator)
{
    m_numerator = numerator;
    m_denominator = denominator;
    update();
}

void FractionImage::paintEvent(QPaintEvent *event)
{
    int width = this->width();
    int height = this->height();

    QLinearGradient grad(0, 0, 0, height);
    grad.setColorAt(0.0, m_gradientColor0);
    grad.setColorAt(1.0, m_gradientColor1);

    QPainter painter(this);
    painter.setBrush(grad);

    float fwidth = float(width)/float(m_denominator);

    if (m_numerator > 0) {
        painter.drawRect(0, 1, m_numerator*fwidth, height-2);
    }

    QPen pen(m_lineColor);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(1, 1, width-2, height-2);

    for (int i = 1; i < m_denominator; i++) {
        painter.drawLine(i*fwidth, 1, i*fwidth, height-2);
    }
}
