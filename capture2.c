// capture2.c

#include "play.h"

void capture2(char **board,int size ,int i,int j ,char player) {
	board[i][j]='.';	// to board[i][j] egine capture ara kanto '.'
	if ( i < size-1 ) {				//elegxos gia na min bgoume ekso apo ton pinaka omoioi elegxoi kai gia tis alles plevres tou pinaka
                if ( board[i+1][j] == player ) {	// kalese ti capture2 anadromika gia to katw stoixeio
                        capture2(board,size,i+1,j,player) ;
                }
        }
	if ( j < size-1 ) {				//kalese ti capture2 anadromika gia to deksia stoixeio
                if ( board[i][j+1] == player ) {
                        capture2(board,size,i,j+1,player) ;
                }
        }
	if ( i > 0 ) {
                if ( board[i-1][j] == player ) {	// kalese ti capture2 anadromika gia panw stoixeio
                        capture2(board,size,i-1,j,player) ;
                }
        }
	if ( j > 0 ) {
                if ( board[i][j-1] == player ) {	// kalese ti capture2 anadromika gia to aristera stoixeio
                        capture2(board,size,i,j-1,player) ;
                }
        }
	return ;
}
