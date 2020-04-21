#include "Timestamp.h"

#if defined( ARDUINO )
    #include "Arduino.h"
#else
    #error "Timestamp not implemented."
#endif



uint32_t Get_Timestamp_Millisecond( void )
{
    #if defined( ARDUINO )
        return (uint32_t)millis();
    #else
        #error "Get_Timestamp_Millisecond() not implemented."
    #endif
}

uint32_t Get_Timestamp_Microsecond( void )
{
    #if defined( ARDUINO )
        return (uint32_t)micros();
    #else
        #error "Get_Timestamp_Microsecond() not implemented."
    #endif
}