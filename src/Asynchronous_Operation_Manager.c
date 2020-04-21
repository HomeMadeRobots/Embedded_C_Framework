#include "Asynchronous_Operation_Manager.h"



/*============================================================================*/
/* Public methods */
/*============================================================================*/
/* Server operations */
void Accept_Operation( const Asynchronous_Operation_Manager* Me )
{
    Me->var_attr->Operation_Accepted = 1;
}
/*----------------------------------------------------------------------------*/
void Refuse_Operation( const Asynchronous_Operation_Manager* Me )
{
    Me->var_attr->Operation_Accepted = 0;
}
/*----------------------------------------------------------------------------*/
void Srv_Notify_Operation_Finished(
    const Asynchronous_Operation_Manager* Me,
    bool status )
{
    if( true==status )
    {
        Me->var_attr->Operation_Finished_OK = true;
    }
    else
    {
        Me->var_attr->Operation_Finished_OK = false;
    }
    
    if( NULL!=Me->Callback )
    {
        Me->Callback( status );
    }
}
/*----------------------------------------------------------------------------*/
/* Client operations */
bool Is_Operation_Accepted( const Asynchronous_Operation_Manager* Me )
{
    return (bool)(Me->var_attr->Operation_Accepted);
}
/*----------------------------------------------------------------------------*/
bool Is_Operation_Finished( const Asynchronous_Operation_Manager* Me )
{
    return (bool)(Me->var_attr->Operation_Finished);
}
/*----------------------------------------------------------------------------*/
bool Get_Finished_Operation_Status( const Asynchronous_Operation_Manager* Me )
{
    return (bool)(Me->var_attr->Operation_Finished_OK);
}