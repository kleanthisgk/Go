// freedoms.c

#include <stdio.h>
#include "play.h"

int freedoms(char **board,int size,int i,int j,char player) {
	int souls=0;
	if ( i < size-1 ) {			// elegxos gia na min vgoume ekso apo ta oria tou pinaka omoia kai gia tis alles plevres
		if ( board[i+1][j] == '.' ) {	// an to katw stoixeio einai .
			souls++ ;		// au3ise tis eleutheries
			board[i+1][j] ='c' ;	// kai markare to stoixeio
		}
		else if ( board[i+1][j] == player ) {			//an brisketai dipla petra tou paixti
			board[i][j]='k' ;				//markarei to stoixeio etsi wste na min ksanakalestei anadromika me apotelesma na min termatizetai pote
			souls+=freedoms(board,size,i+1,j,player) ;	//anadromiko kalesma se petra tou paikti
		}
	}
        if ( j < size-1 ) {			// an to dexia stoixeio einai '.'
                if ( board[i][j+1] == '.' ) {	// kane to idio
                       	souls++ ;
                        board[i][j+1] ='c' ;
                }
                else if ( board[i][j+1] == player ) {
			board[i][j]='k' ;
			souls+= freedoms(board,size,i,j+1,player) ;
		}
        }
        if ( i > 0 ) {
                if ( board[i-1][j] == '.' ) {	// an to aristera stoixeio einai '.'
                        souls++;		// kane to idio
                        board[i-1][j] ='c' ;
                }
                else if ( board[i-1][j] == player ) {
			board[i][j]='k' ;
			souls+= freedoms(board,size,i-1,j,player) ;
		}
        }
        if ( j > 0 ) {
                if ( board[i][j-1] == '.' ) {	// an to aristera stoxeio einai '.'
                        souls++ ;		// kane to idio
                        board[i][j-1] ='c' ;
                }
                else if ( board[i][j-1] == player ) {
			board[i][j]='k' ;
			souls+=freedoms(board,size,i,j-1,player) ;
		}
	}
	return souls ;
}
