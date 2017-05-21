#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "oper_bus.h"
#include "oper_cond.h"

/********************************
*     CONSTANTES DEL TURNO      *
********************************/
#define MANANA 7
#define TARDE  8
#define NOCHE  9

/********************************
* CONSTANTES DEL MENU PRINCIPAL *
********************************/

#define BUS   1
#define COND  2
#define SALIR 3

/****************************
* CONSTANTES DEL MENU BUSES *
****************************/

#define AGRE  1
#define CAMB  2
//#define COND  3
#define ELIM  4
#define VOLB  5

/**********************************
* CONSTANTES DEL MENU CONDUCTORES *
**********************************/

#define ROTAR 1
#define TURNO 2
#define CONS  3
#define VOLC  4

/*********************
* CONSTANTES ERRORES *
*********************/

#define VACIO 1

/*************
* PROTOTIPOS *
*************/

int  menu        ( void );
int  menub       ( void );
int  menuc       ( void );
int cambioturno  ( int *turno );
void despedida   ( void );
void errores     ( int er );
T_bus * buscar   ( T_bus *cab );
void llenarinfobus  ( T_bus **cab );
void llenarinfocon  ( T_con **cab );
void agregarbus     ( T_bus **cab );
void imprimircon    ( T_bus *cab );
void recorrelista   ( T_bus *ptcab );
void cambiocond     ( T_bus **cab );
void conductorturno ( T_bus *cab, int turno );
void rotarturno    ( T_bus **cab );
void agregarcon     ( T_con **cab );
void pidecadena     ( char msg [], char des [] );
void muestracadena  ( char msg [], char orig [] );

/*********************
* PROGRAMA PRINCIPAL *
*********************/

int main ( void )
{
    int op1,op2,turno;
    T_bus *cab;
    iniciar ( &cab );
    turno=MANANA;
    do
    {
        op1 = menu ();
        switch ( op1 )
        {
            case BUS  :
                        do
                        {
                            op2 = menub ();
                            switch ( op2 )
                            {
                                case AGRE:  agregarbus ( &cab );
                                    break;
                                case ELIM:  if ( existebus ( cab ) == TRUE )
                                            {
                                                system ("cls");
                                                eliminarbuses ( &cab );
                                                muestracadena ("\n\n\n\n\t\t\tE L I M I N A R   B U S","\n\n\n\t    S E   H A N   E L I M I N A D O   L O S   B U S E S");
                                            }
                                            else
                                                errores ( VACIO );
                                    break;
                                case COND:  if ( existebus ( cab ) == TRUE )
                                                cambiocond ( &cab );
                                            else
                                                errores ( VACIO );
                                    break;
                                case 3:     if ( existebus ( cab ) == TRUE )
                                                conductorturno ( cab, turno );
                                            else
                                                errores ( VACIO );

                            }
                        } while ( op2 != 5 );
                break;

            case COND :
                        do
                        {
                            op2 = menuc ();
                            switch ( op2 )
                            {
                                case CONS:  if ( existebus ( cab ) == TRUE )
                                            {
                                                recorrelista ( cab );
                                            }
                                            else
                                                errores ( VACIO );
                                    break;
                                case ROTAR: if ( existebus ( cab ) == TRUE )
                                            {
                                                rotarturno ( &cab );
                                            }
                                            else
                                                errores ( VACIO );
                                    break;
                                case TURNO: if ( existebus ( cab ) == TRUE )
                                            {
                                                if ( cambioturno   ( &turno ) )
                                                    muestracadena ("\n\n\n\n\n\t\t\tC A M B I O   D E   T U R N O","\n\n\t\tS E   H A   C A M B I A D O   T U R N O");
                                                else
                                                    muestracadena ("\n\n\n\n\n\t\t\tC A M B I O   D E   T U R N O","\n\n\t\tN O   S E   H A   C A M B I A D O   T U R N O");
                                            }

                                        break;
                            }
                        } while ( op2 != 4 );
                break;

            case SALIR: if ( existebus ( cab ) == TRUE )
                            eliminarbuses ( &cab );
                        despedida ();

                break;
        }
    } while ( op1 != SALIR );
    return (0);
}

int menu ( void )
{
    int op;
    system ("cls");
    printf ("\n\n\n\n\n\t\t\tM E N U   P R I N C I P A L:");
    printf ("\n\n\n\n\t\t1.M E N U   B U S");
    printf ("\n\n\t\t2.M E N U   C O N D U C T O R");
    printf ("\n\n\t\t3.S A L I R\n\n\t\t");
    op = getche() - 48;
    return ( op );
}

int menub ( void )
{
    int op;
    system ("cls");
    printf ("\n\n\n\n\n\t\t\tM E N U   B U S:");
    printf ("\n\n\n\n\t\t1.A G R E G A R   B U S");
    printf ("\n\n\t\t2.C A M B I O   D E   C O N D U C T O R");
    printf ("\n\n\t\t3.C O N S U L T A R   C O N D U C T O R");
    printf ("\n\n\t\t4.E L I M I N A R   B U S E S");
    printf ("\n\n\t\t5.V O L V E R   A L   M E N U   P R I N C I P A L\n\n\t\t");
    op = getche() - 48;
    return ( op );
}

int menuc ( void )
{
    int op;
    system ("cls");
    printf ("\n\n\n\n\n\t\t\tM E N U   C O N D U C T O R:");
    printf ("\n\n\n\n\t\t1.R O T A R   C O N D U C T O R E S");
    printf ("\n\n\t\t2.C A M B I A R   T U R N O");
    printf ("\n\n\t\t3.C O N S U L T A R   C O N D U C T O R E S");
    printf ("\n\n\t\t4.V O L V E R   A L   M E N U   P R I N C I P A L\n\n\t\t");
    op = getche() - 48;
    return ( op );
}

void despedida ( void )
{
    system ("cls");
    printf ("\n\n\n\n\n\n     G R A C I A S   P O R   U T I L I Z A R   E S T E   P R O G R A M A ...");
    getch ();
}

void agregarbus ( T_bus **cab )
{
    T_bus *aux;
    if ( existebus ( *cab ) == FALSE )
    {
        ( *cab ) = crearbus ();
        ( *cab ) -> ptsig = *cab;
        ( *cab ) -> ptant = *cab;
	    llenarinfobus ( cab );
 		agregarcon ( &( ( *cab ) -> ptcon ) );
    }
    else
    {
        aux = ( *cab ) -> ptant;
        aux -> ptsig = crearbus ();
        ( aux -> ptsig ) -> ptant = aux;
        aux = aux -> ptsig;
        ( aux ) -> ptsig = *cab;
        ( *cab ) -> ptant = aux;
	    llenarinfobus ( &aux );
 		agregarcon ( &( aux -> ptcon ) );
    }
}

void agregarcon ( T_con **cab )
{
    *cab = crearcond ();
    llenarinfocon ( cab );
    ( *cab ) -> ptsig = crearcond ();
    llenarinfocon ( &( ( *cab ) -> ptsig ) );
    ( ( *cab ) -> ptsig ) -> ptsig = crearcond ();
    llenarinfocon ( &( ( ( *cab ) -> ptsig ) -> ptsig ) );
    ( ( ( *cab ) -> ptsig ) -> ptsig ) -> ptsig = *cab;
}

void llenarinfobus ( T_bus **cab )
{
    system ("cls");
    printf ("\n\n\n\n\n\t\t\tA G R E G A R   B U S");
    printf ("\n\n\t\tD I G I T E   E L   C O D I G O   D E L   B U S:\n\n\t\t");
    scanf  ("%d%*c", &( ( *cab ) -> cod ) );
}

void llenarinfocon ( T_con **cab )
{
    system ("cls");
    printf ("\n\n\n\n\n\t\t\tA G R E G A R   C O N D U C T O R");
    pidecadena ("\n\n\t    D I G I T E   E L   N O M B R E   D E L   C O N D U C T O R:\n\n\t    ", ( *cab ) -> cond );
}

void recorrelista ( T_bus *ptcab )
{
    system ("cls");
    T_bus *aux;
    int lon,i;
    i=1;
    aux = ptcab;
    lon = longbuses ( ptcab );
    while ( i <= lon )
    {
        printf ("\n\n\n\n\n\t\tC O N S U L T A R   C O N D U C T O R");
        printf ("\n\n\t\tC O D I G O   D E L   B U S: %d",aux -> cod);
        imprimircon ( aux );
        i++;
        aux = aux -> ptsig;
    }
}

void imprimircon ( T_bus *cab )
{
    T_con *aux;
    aux = cab -> ptcon ;
    muestracadena ("\n\n\t\tC O N D U C T O R   M A n A N A\n\n\t\t", aux -> cond );
    aux = aux -> ptsig;
    muestracadena ("\n\n\t\tC O N D U C T O R   T A R D E\n\n\t\t", aux -> cond );
    aux = aux -> ptsig;
    muestracadena ("\n\n\t\tC O N D U C T O R   N O C H E\n\n\t\t", aux -> cond );
    system ("cls");
}

void errores ( int er )
{
    system ("cls");
    printf ("\n\n\n\n\n\n\n\t");
    switch ( er )
    {
        case VACIO: printf ("Error. No ha ingresado buses ni conductores");
         break;
    }
    getch ();
}

void pidecadena ( char msg [], char des [] )
{
    int i;
    printf ( "%s", msg );
    gets ( des );
    system ("cls");
    for ( i = 0; i < strlen ( des ); i++ )
                des [i] = toupper ( des[ i ] );
}

void muestracadena ( char msg [], char orig [] )
{
    printf ( "%s", msg );
    puts ( orig );
    getch ();
}

void cambiocond ( T_bus **cab )
{
    system (" cls ");
    T_bus *aux;
    T_con *ult;
    int buses, i;
    buses = longbuses ( *cab );
    if ( buses == 1 )
    {
        muestracadena ("\n\n\n\n\t\tC A M B I O   D E   C O N D U C T O R","\n\n\n\tS O L O   T I E N E   U N   B U S");
    }
    else
    {
        aux = ( ( *cab ) -> ptant ) -> ptant;
        ult = ( ( *cab ) -> ptant ) -> ptcon;
        for ( i = 1 ; i < buses ; i++ )
        {
            ( aux -> ptsig ) -> ptcon = aux -> ptcon;
            aux = aux -> ptant;
        }
        ( *cab ) -> ptcon = ult;
        muestracadena ("\n\n\n\n\t\tC A M B I O   D E   C O N D U C T O R","\n\n\n\tS E   H A N   C A M B I A D O   L O S   C O N D U C T O R E S");
    }
}

void conductorturno ( T_bus *cab, int turno )
{
    system ("cls");
    printf ("\n\n\n\n\n\t\t\tC O N S U L T A R   B U S E S");
    T_bus *aux;
    int buses, i;
    aux = cab;
    buses = longbuses ( cab );
    for ( i = 1; i <= buses; i++ )
    {
        printf ("\n\n\t\tC O D I G O   D E L   B U S: %d\n\n\t\t", aux -> cod);
        if ( turno == MANANA )
        {
            printf ("\n\n\t\tC O N D U C T O R   M A n A N A\n\n\t\t");
            printf ("%s", (aux -> ptcon ) -> cond );
        }
        else if ( turno == TARDE )
        {
            printf ("\n\n\t\tC O N D U C T O R   T A R D E\n\n\t\t");
            printf ("%s", ( (aux -> ptcon ) -> ptsig ) -> cond );
        }
        else if ( turno == NOCHE )
        {
            printf ("\n\n\t\tC O N D U C T O R   N O C H E\n\n\t\t");
            printf ("%s", ( ( (aux -> ptcon ) -> ptsig ) -> ptsig ) -> cond );
        }
        getch ();
        aux = aux -> ptsig;
    }
}

void rotarturno ( T_bus **cab )
{
    T_bus *aux;
    int buses, i;
    aux = *cab;
    buses = longbuses ( *cab );
    for ( i = 1; i <= buses; i++ )
    {
        aux -> ptcon = ( aux -> ptcon ) -> ptsig;
        aux = aux -> ptsig;
    }
    muestracadena ( "\n\n\n\n\t\tR O T A R   C O N D U C T O R E S" , "\n\n\n  S E   H A N   C A M B I A D O   E L   T U R N O   D E   C O N D U C T O R E S" );
}

int cambioturno ( int *turno )
{
    system ("cls");
    if ( *turno == MANANA )
    {
        *turno = TARDE;
        return ( TRUE );
    }
    else if ( *turno == TARDE )
    {
        *turno = NOCHE;
        return ( TRUE );
    }
    else if ( *turno == NOCHE )
    {
        *turno = MANANA;
        return ( TRUE );
    }
    else
        return ( FALSE );
}
