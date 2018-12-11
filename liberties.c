// liberties.c

#include "play.h"
#include <stdio.h>

int liberties(char **board,int size,int i,int j,char player) {
	int f, k, p ;
	f=freedoms(board,size,i,j,player) ;	// kalese tin freedoms
        for ( k = 0 ; k < size ; k++ ) {
		for ( p = 0 ; p < size ; p++ ) {
                	if ( board[k][p] == 'c' ) {	// allaxe ta markarismena stoixeia
                        	board[k][p]='.' ;	// me to proigoumeno tous periexomeno
                        }
			if ( board[k][p] == 'k' ) {	// allakse ta markarismena se stoixeia idia me tou paikti
				board[k][p]=player ;
			}
                }
        }
	return f ;
}
