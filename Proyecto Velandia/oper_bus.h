#ifndef OPER_BUS_H_INCLUDED
#define OPER_BUS_H_INCLUDED

#define TRUE  1
#define FALSE 0
#define NEWB  (T_bus *)malloc(sizeof(T_bus));
struct bus
{
    int              cod;
    struct bus       *ptsig;
    struct bus       *ptant;
    struct conductor *ptcon;
};

typedef struct bus T_bus;

int iniciar        ( T_bus **cab );
int existebus      ( T_bus *ptcab );
T_bus * crearbu    ( void );
void eliminarbuses ( T_bus **cab );
int longbuses      ( T_bus *cab );
T_bus * kesimobus  ( T_bus *cab, int pos );

#endif // OPER_BUS_H_INCLUDED
