#include "BinaryViewWidget.h"
#include <QPainter>

BinaryViewWidget::BinaryViewWidget(QWidget *parent) : QWidget(parent)
{

}

void BinaryViewWidget::setMessageModel(MessageModel * _messageModel) {
    messageModel = _messageModel;


}

void BinaryViewWidget::setColor0(const QString _color0) {
    color0 = _color0;
    emit notify();
}

void BinaryViewWidget::setColor1(const QString _color1) {
    color1 = _color1;
    emit notify();
}

void BinaryViewWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    int x = 10;
    int y = 10;
    QString coul1 = color1.toLower();
    QString coul0 = color0.toLower();
    QColor c1 = QColor(coul1);
    QColor c0 = QColor(coul0);
    for (int i = 0; i<messageModel->getCharacterCount(); i++) {
        for (int j = 0; j < 7; j++) {
             if (messageModel->getBinaryK(((i)*7)+j)) {
                painter.setBrush(QBrush(c1));
             } else {
                painter.setBrush(QBrush(c0));
             }
             painter.drawEllipse(x,y+j*15,10,10);
         }
         x += 15;
         if (x >= rect().width() - 10) {
             x= 10;
             y += 120;
         }
         if (y + 6*15 >= rect().height() - 10) {
             painter.drawText(10,y-7,"There is no space to draw all the message please enlarge the window or buy a big screen.");
         }
    }

}
