#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "oper_bus.h"
#include "oper_cond.h"

int iniciar ( T_bus **cab )
{
    *cab = NULL;
    if ( *cab == NULL )
        return ( TRUE );
    else
        return ( FALSE );
}

int existebus ( T_bus *cab )
{
	if ( cab == NULL )
		return ( FALSE );
	else
        return ( TRUE );
}

T_bus * crearbus ( void )
{
    T_bus *aux;
	aux = NEWB;
	if ( ( aux ) != NULL )
	{
		aux -> ptsig = NULL;
		aux -> ptant = NULL;
		aux -> ptcon = NULL;
		return(aux);
	}
	else
		return(NULL);
}

int longbuses ( T_bus *cab )
{
    int lon;
    T_bus *aux;
    aux = cab;
    lon = 1;
    while ( ( aux -> ptsig ) != cab )
    {
        aux = aux -> ptsig;
        lon ++;
    }
    return ( lon );
}

T_bus * kesimobus  ( T_bus *cab, int pos )
{
    int i;
	for ( i = 1 ; i < pos ; i++ )
		cab = cab -> ptsig;
	return ( cab );
}

void eliminarbuses ( T_bus **cab)
{
	T_bus *tmp;
	tmp = ( *cab ) -> ptant;
	tmp -> ptsig = NULL;
	(*cab) -> ptant = NULL;
    while ( *cab != NULL )
    {
        tmp = *cab;
        (*cab) = (*cab) -> ptsig;
        eliminarcond (&tmp);
        tmp -> ptant = NULL;
        tmp -> ptsig = NULL;
        free ( tmp );
    }
}
