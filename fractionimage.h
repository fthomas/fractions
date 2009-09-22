#ifndef FRACTIONIMAGE_H
#define FRACTIONIMAGE_H

#include <QColor>
#include <QPaintEvent>
#include <QWidget>

class FractionImage : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int numerator READ numerator WRITE setNumerator)
    Q_PROPERTY(int denominator READ denominator WRITE setDenominator)

public:
    FractionImage(QWidget *parent = 0);

    int numerator() const { return m_numerator; }
    int denominator() const { return m_denominator; }
    void setColors(const QColor &lineColor = Qt::white,
                   const QColor &gradientColor0 = QColor(0,255,0),
                   const QColor &gradientColor1 = QColor(0,255,0));

public slots:
    void setNumerator(const int numerator);
    void setDenominator(const int denominator);
    void setFraction(const int numerator, const int denominator);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_numerator,
        m_denominator;
    QColor m_lineColor,
           m_gradientColor0,
           m_gradientColor1;
};

#endif // FRACTIONIMAGE_H
