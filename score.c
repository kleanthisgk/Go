// score.c

#include "play.h"

float score (char **board, int size, char **strAll, int move ) {
	int freedoms=0, f=0, neutr=0, i, j, k, p, flag=0, blacks=0, b, w ;
	float pontoi=0.0 ;
	for ( i = 0 ; i < size ; i++ ) {		//elegxos an iparxoun pano apo mia eleftheries oste na min ginei lathos capture
                for ( j = 0 ; j < size ; j++ ) {
                        if ( board[i][j] == '.') {
                        	f++;
                        }
                }
        }
	if ( f == size*size ) return 0.0 ;
	if ( f > 1 ) {							// an uparxoun pano apo mia eleftheria ston pinaka
		for ( i = 0 ; i < size ; i++ ) {
			for ( j = 0 ; j < size ; j++ ) {
				if ( board[i][j] =='X' || board[i][j]=='O' ) { // afairei tis nekres petres apo to board
					if ( liberties(board,size,i,j,board[i][j]) == 1) {
						capture2(board,size,i,j,board[i][j]);
					}
				}
			}
		}
	}
	while ( freedoms == 0 ) {					// elegxos ton kenwn simeiwn tou pinaka kai gemisma me tis kataliles petres
		freedoms = 1 ;
		for ( i = 0 ; i < size ; i++ ) {
			for ( j = 0 ; j < size ; j++ ) {
				if ( board[i][j] == '.' ) {
					w=0 ;
					b=0 ;
					freedoms = 0 ;
					if ( i+1 < size ) {
						if ( board[i+1][j] == 'X' ) {
							b++;
						}
						if ( board[i+1][j] == 'O' ) {
							w++;
						}
					}
					if ( j+1 < size ) {
						if ( board[i][j+1] == 'X' ) {
							b++;
						}
						if ( board[i][j+1] == 'O' ) {
							w++;
						}
					}
					if ( i > 0 ) {
						if ( board[i-1][j] == 'X' ) {
							b++;
						}
						if ( board[i-1][j] == 'O' ) {
							w++;
						}
					}
					if ( j > 0 ) {
						if ( board[i][j-1] == 'X' ) {
							b++;
						}
						if ( board[i][j-1] == 'O' ) {
							w++;
						}
					}
					if ( b > w ) board[i][j] = 'X';
					else if ( w > b ) board[i][j] = 'O';
					else if ( w == b && w != 0 ) {
						neutr++;
						board[i][j] = 'N';		//markarisma ton oudeterwn simeiwn tou pinaka
					}
				}
			}
		}
	}
	for ( i = 0 ; i < size ; i++ ) {
		for ( j = 0 ; j < size ; j++ ) {
			if( board[i][j]=='X') blacks++;				// katametrisi ton mavrwn petrwn
		}
	}
	blacks+=neutr/2;
	pontoi = ((size*size)/2.0)-blacks;
	load(board,strAll,move,size);
	return pontoi;
}
