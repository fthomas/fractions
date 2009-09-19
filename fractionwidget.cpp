#include <QLinearGradient>
#include <QPainter>
#include <QPen>
#include "fractionwidget.h"

FractionWidget::FractionWidget(QWidget *parent)
    : QWidget(parent)
{
    m_height = parent->height();
    m_width = parent->width();
}

void FractionWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen penBorder = QPen(Qt::white);
    penBorder.setWidth(2);

    painter.setPen(penBorder);
        painter.drawRect(1, 1, m_width-2, m_height-2);

    QLinearGradient grad(0,0,0,m_height);
    grad.setColorAt(0, QColor(0,192,0));
    grad.setColorAt(1, QColor(0,255,0));
    painter.setBrush(grad);



    for (unsigned int i = 1; i <= m_denominator; i++) {

        float fwidth = float(m_width)/float(m_denominator);
        int gwidth = fwidth*i;
                if (i <= m_numerator) {
            QRect r = QRect(gwidth-fwidth, 1, fwidth+1, m_height-2);
            painter.drawRect(r);
        }

        painter.drawLine(gwidth, 0, gwidth, m_height);


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
