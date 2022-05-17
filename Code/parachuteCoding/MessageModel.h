/** -*- mode: c++ ; c-basic-offset: 2 -*-
 * @file   MessageModel.h
 * @author Houcem Jouili et Lamhamdi Mehdi
 *
 * @brief  Message model declaration.
 */
#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include <QWidget>
#include <QString>
#include <QChar>
class MessageModel : public QWidget
{
    Q_OBJECT
public:
    MessageModel();
    const QString getMessage();
    int getShift();
    void sendNotificationIfEnabled();
    int getBinaryK(int k); // returns the binary with index k (decalage = 64)
    int getCharacterCount(); // retruns the number of characters in the string message
public slots :
    void setShift(const int shift);
    void setMessage(const QString msg);
    void enableNotification();
    void disableNotification();
private :
    int shift = 64;
    QString message;
    bool _notify = true;
signals :
   void notify();
};




#endif // MESSAGEMODEL_H
