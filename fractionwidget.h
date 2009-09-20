#ifndef FRACTIONWIDGET_H
#define FRACTIONWIDGET_H

#include <QWidget>
#include <QColor>
#include <QPaintEvent>
#include <QResizeEvent>

class FractionWidget : public QWidget
{
    Q_OBJECT

public:
    FractionWidget(QWidget *parent = 0);
    void setFraction(const int numerator, const int denominator);
    void setColors(const QColor &lineColor = Qt::white,
                   const QColor &gradientColor0 = QColor(0,192,0),
                   const QColor &gradientColor1 = QColor(0,255,0));

public slots:
    void setNumerator(const int numerator);
    void setDenominator(const int denominator);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_numerator,
        m_denominator;
    QColor m_lineColor,
           m_gradientColor0,
           m_gradientColor1;
};

#endif // FRACTIONWIDGET_H
