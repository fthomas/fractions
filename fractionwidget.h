#ifndef FRACTIONWIDGET_H
#define FRACTIONWIDGET_H

#include <QWidget>
#include <QPaintEvent>

class FractionWidget : public QWidget
{
    Q_OBJECT

public:
    FractionWidget(QWidget *parent = 0);

public slots:
    void numeratorChanged(int numerator);
    void denominatorChanged(int denominator);

protected:
    void paintEvent(QPaintEvent *event);

private:
    unsigned int m_height, m_width;
    unsigned int m_numerator, m_denominator;
};

#endif // FRACTIONWIDGET_H
