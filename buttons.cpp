#include <QtGlobal>

#ifdef Q_OS_LINUX

#include "trinity.h"
#include "buttons.h"
#include "wiringPi.h"

#ifdef __DEBUG__
#include <QDebug>
#endif

//------------------------------------------------------------------------------
// buttons_isr0
//------------------------------------------------------------------------------
void buttons_isr0(void *userData) {
    Trinity *trp = (Trinity *)userData;
    #ifdef __DEBUG__
        qDebug() << "gpio: button 1 set " + QString::number(BUTTONS_A_READ);
    #endif

    if(BUTTONS_A_READ == LOW) trp->switchPushed(0);
    else trp->switchReleased(0);
}
//------------------------------------------------------------------------------
// buttons_isr1
//------------------------------------------------------------------------------
void buttons_isr1(void *userData) {
    Trinity *trp = (Trinity *)userData;

    #ifdef __DEBUG__
        qDebug() << "gpio: button 2 set " + QString::number(BUTTONS_B_READ);
    #endif
    if(BUTTONS_B_READ == LOW) trp->switchPushed(1);
    else trp->switchReleased(1);
}
//------------------------------------------------------------------------------
// buttons_isr2
//------------------------------------------------------------------------------
void buttons_isr2(void *userData) {
    Trinity *trp = (Trinity *)userData;
    #ifdef __DEBUG__
        qDebug() << "gpio: button 3 set " + QString::number(BUTTONS_C_READ);
    #endif
    if(BUTTONS_C_READ == LOW) trp->switchPushed(2);
    else trp->switchReleased(2);
}
//------------------------------------------------------------------------------
#endif
