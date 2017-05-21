#ifndef OPER_COND_H_INCLUDED
#define OPER_COND_H_INCLUDED
#include "oper_bus.h"
#define N     50
#define TRUE  1
#define FALSE 0
#define NEWC  (T_con *)malloc(sizeof(T_con));

struct conductor
{
    char cond[N];
    struct conductor *ptsig;
};

typedef struct conductor T_con;

int existecon            ( T_con *cab );
T_con * crearcond        ( void );
void eliminarcond        ( T_bus **cab );

#endif // OPER_COND_H_INCLUDED
