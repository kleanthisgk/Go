// p_handicap.c

#include "handicap.h"
#include <stdlib.h>

int p_handicap(char **board,int size,int *s,int t) {
	int i, j ,k=1;
	srand(t) ;
	if ( *s > 1 && *s < size*size-1 ) {	// an to plithos twn petrwn einai egkuro
		do {
			i=rand()%size ;		// vres ena tuxaio i
			j=rand()%size ;		// vres ena tuxaio j
			if ( board[i][j] == 'X' ) {	// elegxe an einai einai idi X
				continue ;		// an einai ksanaprospathise na vreis alla
			}
			board[i][j]='X' ;		// alliws kanto X
			k++ ;
		} while ( k <= *s ) ;
	}
	else {
		return 0 ;
	}
	return 1 ;
}
