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
}

void FractionWidget::setFraction(const int numerator, const int denominator)
{
    m_numerator = numerator;
    m_denominator = denominator;
    update();
}

void FractionWidget::paintEvent(QPaintEvent *event)
{
 // this->
    int width = this->parentWidget()->width();
    int height = this->parentWidget()->height();
    this->resize(width, height);

    QLinearGradient grad(0, 0, 0, height);
    grad.setColorAt(0, QColor(0,192,0));
    grad.setColorAt(1, QColor(0,255,0));

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(grad);

    float fwidth = float(width)/float(m_denominator);

    for (int i = 1; i <= m_numerator; i++) {
        painter.drawRect((i-1)*fwidth-1, 1, fwidth+1, height-2);
    }

    QPen pen = QPen(Qt::white);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(1, 1, width-4, height-2);

    for (int i = 1; i < m_denominator; i++) {
        painter.drawLine(i*fwidth, 1, i*fwidth, height-2);
    }
}

void FractionWidget::numeratorChanged(int numerator)
{
    m_numerator = numerator;
    update();
}

void FractionWidget::denominatorChanged(int denominator)
{
    m_denominator = denominator;
    update();
}