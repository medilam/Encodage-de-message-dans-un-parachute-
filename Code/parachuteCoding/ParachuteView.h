/** -*- mode: c++ ; c-basic-offset: 2 -*-
 * @file   ParachuteView.h
 * @author Houcem Jouili et Lamhamdi Mehdi
 *
 * @brief  Parachute view declaration.
 */
#ifndef PARACHUTEVIEW_H
#define PARACHUTEVIEW_H

#include <QWidget>
#include "MessageModel.h"

class ParachuteView : public QWidget
{
    Q_OBJECT
public:
    explicit ParachuteView(QWidget *parent = nullptr);
    void setMessageModel(MessageModel *);
protected:
    void paintEvent(QPaintEvent *) override;
signals:
    void notify();
public slots:
    void setColor0(const QString);
    void setColor1(const QString);
    void setNbTrack(const int);
    void setNbSector(const int);
private:
    MessageModel * messageModel;
    QString color0 = "White";
    QString color1 = "Red";
    int nbTrack = 5;
    int nbSector = 21;
};

#endif // PARACHUTEVIEW_H
