#ifndef FRACTIONWIDGET_H
#define FRACTIONWIDGET_H

#include <QWidget>
#include <QPaintEvent>

class FractionWidget : public QWidget
{
    Q_OBJECT

public:
    FractionWidget(QWidget *parent = 0);
    void setFraction(const int numerator, const int denominator);

public slots:
    void numeratorChanged(const int numerator);
    void denominatorChanged(const int denominator);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_height, m_width;
    int m_numerator, m_denominator;
};

#endif // FRACTIONWIDGET_H
