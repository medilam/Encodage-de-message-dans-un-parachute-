/** -*- mode: c++ ; c-basic-offset: 2 -*-
 * @file   BinaryViewWidget.h
 * @author Houcem Jouili et Lamhamdi Mehdi
 *
 * @brief  Binary view declaration.
 */
#ifndef BINARYVIEWWIDGET_H
#define BINARYVIEWWIDGET_H

#include <QWidget>
#include "MessageModel.h"

class BinaryViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BinaryViewWidget(QWidget *parent = nullptr);
    void setMessageModel(MessageModel *);

protected:
    void paintEvent(QPaintEvent *) override;

signals:
    void notify();
public slots:
    void setColor0(const QString);
    void setColor1(const QString);
private:
    MessageModel * messageModel;
    QString color0 = "White";
    QString color1 = "Red";
};

#endif // BINARYVIEWWIDGET_H
