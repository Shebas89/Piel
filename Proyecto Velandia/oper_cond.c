#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "oper_cond.h"
#include "oper_bus.h"

int existecon ( T_con *cab )
{
    if ( cab != NULL )
        return ( TRUE );
    else
        return ( FALSE );
}

void eliminarcond ( T_bus **cab )
{
	T_con *con1,*con2,*con3;
	con1 =(*cab)-> ptcon;
	(*cab)->ptcon=NULL;
	con2 = con1-> ptsig;
	con3 = con2 -> ptsig;
	con1 -> ptsig = NULL;
	con2 -> ptsig = NULL;
	con3 -> ptsig = NULL;
    free ( con1 );
    free ( con2 );
    free ( con3 );
}

T_con * crearcond ( void )
{
    T_con *cab;
	cab = NEWC;
	if( cab != NULL )
	{
		cab -> ptsig = NULL;
		return ( cab );
	}
	else
		return ( NULL );
}
