#include <QColor>
#include <QLinearGradient>
#include <QPainter>
#include <QPen>
#include "fractionwidget.h"

FractionWidget::FractionWidget(QWidget *parent)
    : QWidget(parent)
{
    m_numerator = 0;
    m_denominator = 1;
    setColors();
}

void FractionWidget::setFraction(const int numerator, const int denominator)
{
    m_numerator = numerator;
    m_denominator = denominator;
    update();
}

void FractionWidget::setColors(const QColor &lineColor,
                               const QColor &gradientColor0,
                               const QColor &gradientColor1)
{
    m_lineColor = lineColor;
    m_gradientColor0 = gradientColor0;
    m_gradientColor1 = gradientColor1;
}

void FractionWidget::paintEvent(QPaintEvent *event)
{
    int width = this->width();
    int height = this->height();
//    int width = parentWidget()->width();
//    int height = parentWidget()->height();

    //    resize(width, height);

    QLinearGradient grad(0, 0, 0, height);
    grad.setColorAt(0.0, m_gradientColor0);
    grad.setColorAt(1.0, m_gradientColor1);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(grad);

    float fwidth = float(width)/float(m_denominator);

    for (int i = 1; i <= m_numerator; i++) {
        painter.drawRect((i-1)*fwidth-1, 1, fwidth+1, height-2);
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

void FractionWidget::setNumerator(int numerator)
{
    m_numerator = numerator;
    update();
}

void FractionWidget::setDenominator(int denominator)
{
    m_denominator = denominator;
    update();
}
