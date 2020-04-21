#ifndef ASYNCHRONOUS_OPERATION_MANAGER_H
#define ASYNCHRONOUS_OPERATION_MANAGER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h> /* NULL */

/*============================================================================*/
/* Class */
/*============================================================================*/
typedef struct {
    uint8_t Operation_Accepted:1;
    uint8_t Operation_Finished:1;
    uint8_t Operation_Finished_OK:1;
} Asynchronous_Operation_Manager_Var;

typedef struct {
    Asynchronous_Operation_Manager_Var* var_attr;
    void (*Callback) ( bool op_finished_ok );
} Asynchronous_Operation_Manager;



/*============================================================================*/
/* Public methods */
/*============================================================================*/
/* Server operations */
void Accept_Operation( const Asynchronous_Operation_Manager* Me );
void Refuse_Operation( const Asynchronous_Operation_Manager* Me );
void Srv_Notify_Operation_Finished(
    const Asynchronous_Operation_Manager* Me,
    bool status );
/*----------------------------------------------------------------------------*/
/* Client operations */
bool Is_Operation_Accepted( const Asynchronous_Operation_Manager* Me );
bool Is_Operation_Finished( const Asynchronous_Operation_Manager* Me );
bool Get_Finished_Operation_Status( const Asynchronous_Operation_Manager* Me );


#endif