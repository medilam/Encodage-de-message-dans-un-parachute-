#include "ParachuteView.h"
#include <QPainter>
#include <QtMath>

ParachuteView::ParachuteView(QWidget *parent) : QWidget(parent)
{

}

void ParachuteView::setMessageModel(MessageModel * _messageModel ) {
    messageModel = _messageModel;
}

void ParachuteView::setColor0(const QString _color0) {
    color0 = _color0;
    emit notify();
}

void ParachuteView::setColor1(const QString _color1) {
    color1 = _color1;
    emit notify();
}

void ParachuteView::setNbSector(const int sector) {
    nbSector = sector;
    emit notify();
}

void ParachuteView::setNbTrack(const int track) {
    nbTrack = track;
    emit notify();
}

void ParachuteView::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPoint center = rect().center();
    QColor c1 = QColor(color1);
    QColor c0 = QColor(color0);
    float Rp,Rq,alpha1,alpha2;
    float alphaSector = (2*M_PI)/nbSector;
    float R = qMin(rect().width(), rect().height())/2;
    float widghtTrack = (R*0.9)/nbTrack;
    QPoint point[4];
    for (int k = 0; k<nbSector*nbTrack; k++) {
        alpha1 = (k % nbSector) * alphaSector;
        alpha2 = ((k % nbSector) + 1) * alphaSector;
        Rp = ((int)k/nbSector) * widghtTrack;
        Rq = (((int)k/nbSector)+1) * widghtTrack;
        point[1].setX((Rp * qCos(alpha1)) + center.x());
        point[1].setY((Rp * qSin(alpha1)) + center.y());
        point[0].setX((Rp * qCos(alpha2)) + center.x());
        point[0].setY((Rp * qSin(alpha2)) + center.y());
        point[2].setX((Rq * qCos(alpha1)) + center.x());
        point[2].setY((Rq * qSin(alpha1)) + center.y());
        point[3].setX((Rq * qCos(alpha2)) + center.x());
        point[3].setY((Rq * qSin(alpha2)) + center.y());
        if (k < messageModel->getCharacterCount() * 7) {
            if (messageModel->getBinaryK(k)) {
                painter.setBrush(QBrush(c1));
            } else {
                painter.setBrush(QBrush(c0));
            }
        } else {
            painter.setBrush(QBrush(c0));
        }
        painter.drawPolygon(point,4);
    }
    if (nbTrack*nbSector < messageModel->getCharacterCount() * 7) {
        painter.drawText(center.x()-R,center.y()+R,"The message is not encoded entirely, increase sectors or tracks.");
    }
}
