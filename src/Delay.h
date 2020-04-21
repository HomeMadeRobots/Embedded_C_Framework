#ifndef DELAY_H
#define DELAY_H


#ifdef ARDUINO
    #include "Arduino.h"
    #define Wait_Microsecond( us ) delayMicroseconds( us )
#else
    #error "merde !"
#endif

#endif