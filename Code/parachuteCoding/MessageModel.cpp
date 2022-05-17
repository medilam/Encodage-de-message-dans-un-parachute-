/** -*- mode: c++ ; c-basic-offset: 2 -*- ...*/
#include "MessageModel.h"
#include <qmath.h>
#include <QDebug>
MessageModel::MessageModel()
{

}

void MessageModel::setMessage(const QString msg){
    message = msg;
    emit notify();
}
void MessageModel::setShift(const int _shift){
    shift = 64-_shift;
    emit notify();
}

void MessageModel::sendNotificationIfEnabled(){
    if(_notify){
        emit notify();
    }
}
void MessageModel::enableNotification(){
    _notify = true;
}
void MessageModel::disableNotification(){
    _notify = false;
}
const QString MessageModel::getMessage(){
    return message;
}
int MessageModel::getShift(){
    return shift;
}
int MessageModel::getBinaryK(int k){
    int indice_lettre = k/7;
    if (message.length() < indice_lettre) {
        return 0;
    } else {
        QChar c = message.at(indice_lettre);
        int ascii_code = (int)c.toLatin1();
        ascii_code = ascii_code-shift;
        return (ascii_code & (1 << (6-(k%7))))? 1:0;
    }

}
int MessageModel::getCharacterCount() {
    return message.length();
}

