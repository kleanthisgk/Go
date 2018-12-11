// s_handicap.c

#include "handicap.h"
#include <stdio.h>

int s_handicap(char **board,int size) {
	int k=0, s, ch, i, j ,flag=0 ;
	char p ;
	ch=getchar() ;					// diavase to keno
	scanf( "%c%d",&p,&s) ;				// diavase to vertex
        ch=getchar() ;					// diavase to keno i tin allagi grammis
	if ( ch == '\n' ) {				// an einai \n epistrepse 0 diladi apotuxis termatismos tis sunartisis
		return 0 ;
	}
	k++ ;
	do {
		if ( p >= 'A' && p <= 'Z' ) {		// an to gramma einai kefalaio
			if ( p < 'I' ) {		// kai mikrotero tou I
				j=p-'A' ;
			}
			else if ( p == 'I' ) {		// an einai I
				return 2 ;		// i sunaritsi epistrefei 2 pou simainei oti de mporei na topothetithei handicap
			}
			else {
				j=p-'A'-1 ;		// ftiakse to katallilo j pou antiproswpeuei ti stili
			}
		}
		else if ( p >= 'a' && p <= 'z' ) {	// i logiki einai idia me ta kefalaia
			if ( p < 'i' ) {
                                j=p-'a' ;
			}
                        else if ( p == 'i' ) {
                                return 2 ;
                        }
                        else {
                                j=p-'a'-1 ;
                        }
                }
		else {					// an den einai oute kefalaio oute pezo
			return 2 ;			// epistrefei 2 i sunartisi
		}
		if ( j < 0 || j >= size ) {		// an i stili einai ektos oriwn
			return 2 ;			// epistrefei 2
		}
		i=size-s ;				// dwse timi sti grammi
		if ( i < 0 || i >=size ) {		// an einai ektos oriwn
			return 2 ;			// epistrefei 2
		}
		else {
			if ( board[i][j] != 'X' ) {	// an to stoixeio den einai idi X
				board[i][j]='X' ;	// kanto X
			}
			else {
				return 2 ;		// alliws epistrepse 2
			}
		}
		if ( flag == 1 ) {			// an to flag einai 1 tote stamata na diavazeis
			break ;
		}
		scanf( "%c%d",&p,&s) ;			// diavase to epomeno vertex
                ch=getchar() ;				// diavase keno i allagi grammis
		k++ ;					// auksise ton metriti
		if ( ch == '\n' ) {			// an o xaraktiras einai \n
			flag=1 ;			// kane to flag 1
		}
	} while (  k > 1  &&  k < size*size-1  ) ;
	if ( k < 2 || k > size*size-1 ) {		// an to plithos twn vertex den einai egkuros
		return 0 ;				// epistrepse 0
	}
	return 1 ;
}
