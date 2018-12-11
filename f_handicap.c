// f_handicap.c

#include "handicap.h"

int f_handicap(char **board,int size,int *s) {
	if ( size < 7 ) {	// den orizetai handicap se boardsize < 7
		return 2 ;
	}
	else if ( size >= 7 && size < 13 ) {	// gia auta ta boardsize ta handicap stones apexoun 3 apo tis gwnies
		if ( size%2 == 0 || size == 7 ) {	// to size einai artio i iso me 7 tote to max handicap einai 4
			if ( *s == 2 ) {		// topothetisi twn handicap stones sumfwna me to gtp
				board[size-3][2]='X' ;
				board[2][size-3]='X' ;
			}
			else if ( *s == 3 ) {
				board[size-3][2]='X' ;
				board[2][size-3]='X' ;
				board[2][2]='X' ;
			}
			else if ( *s == 4 ) {
				board[size-3][2]='X' ;
				board[2][size-3]='X' ;
				board[size-3][size-3]='X';
				board[2][2]='X' ;
			}
			else {
                                return 0 ;
			}
		}
		else {
			if ( *s == 2 ) {			// topothetisi twn handicap stones sumfwna me to gtp
				board[size-3][2]='X' ;
                                board[2][size-3]='X' ;
			}
			else if ( *s == 3 ) {
                                board[size-3][2]='X' ;
                                board[2][size-3]='X' ;
                                board[2][2]='X' ;
                        }
                        else if ( *s == 4 ) {
                                board[size-3][2]='X' ;
                                board[2][size-3]='X' ;
                                board[size-3][size-3]='X';
                                board[2][2]='X' ;
                        }
			else if ( *s == 5 ) {
				board[size-3][2]='X' ;
                                board[2][size-3]='X' ;
                                board[size-3][size-3]='X';
                                board[2][2]='X' ;
				board[size/2][size/2]='X' ;
			}
			else if ( *s == 6 ) {
				board[size-3][2]='X' ;
                                board[2][size-3]='X' ;
                                board[size-3][size-3]='X';
                                board[2][2]='X' ;
				board[size/2][2]='X' ;
				board[size/2][size-3]='X' ;
			}
			else if ( *s == 7 ) {
				board[size-3][2]='X' ;
                                board[2][size-3]='X' ;
                                board[size-3][size-3]='X';
                                board[2][2]='X' ;
                                board[size/2][2]='X' ;
                                board[size/2][size-3]='X' ;
				board[size/2][size/2]='X' ;
			}
			else if ( *s == 8 ) {
				board[size-3][2]='X' ;
                                board[2][size-3]='X' ;
                                board[size-3][size-3]='X';
                                board[2][2]='X' ;
                                board[size/2][2]='X' ;
                                board[size/2][size-3]='X' ;
				board[2][size/2]='X' ;
				board[size-3][size/2]='X' ;
			}
			else if ( *s == 9 ) {
				board[size-3][2]='X' ;
                                board[2][size-3]='X' ;
                                board[size-3][size-3]='X';
                                board[2][2]='X' ;
                                board[size/2][2]='X' ;
                                board[size/2][size-3]='X' ;
                                board[2][size/2]='X' ;
                                board[size-3][size/2]='X' ;
				board[size/2][size/2]='X' ;
			}
			else {
				return 0 ;
			}
		}
	}
	else if ( size >= 13 && size <= 25 ) {	// an to boardsize einai anamesa se autous tous arithmous ta handicap stones apexoun 4 apo tis gwnies
		if ( size%2 == 0 ) {		// an o aritmhos einai artios o to max handicap einai 4
			if ( *s == 2 ) {			// topothetisi twn handicap stones sumfwna me to gtp
                                board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                        }
                        else if ( *s == 3 ) {
                                board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                                board[3][3]='X' ;
                        }
                        else if ( *s == 4 ) {
                                board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                                board[size-4][size-4]='X';
                                board[3][3]='X' ;
                        }
			else {
                                return 0 ;
                        }
                }
		else {
			if ( *s == 2 ) {
                                board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                        }
                        else if ( *s == 3 ) {
                                board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                                board[3][3]='X' ;
                        }
                        else if ( *s == 4 ) {
                                board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                                board[size-4][size-4]='X';
                                board[3][3]='X' ;
                        }
                        else if ( *s == 5 ) {
                                board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                                board[size-4][size-4]='X';
                                board[3][3]='X' ;
                                board[size/2][size/2]='X' ;
                        }
                        else if ( *s == 6 ) {
                                board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                                board[size-4][size-4]='X';
                                board[3][3]='X' ;
                                board[size/2][3]='X' ;
                                board[size/2][size-4]='X' ;
                        }
			else if ( *s == 7 ) {
				board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                                board[size-4][size-4]='X';
                                board[3][3]='X' ;
                                board[size/2][3]='X' ;
                                board[size/2][size-4]='X' ;
				board[size/2][size/2]='X' ;
			}
			else if ( *s == 8 ) {
				board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                                board[size-4][size-4]='X';
                                board[3][3]='X' ;
                                board[size/2][3]='X' ;
                                board[size/2][size-4]='X' ;
				board[3][size/2]='X' ;
				board[size-4][size/2]='X' ;
			}
			else if ( *s == 9 ) {
				board[size-4][3]='X' ;
                                board[3][size-4]='X' ;
                                board[size-4][size-4]='X';
                                board[3][3]='X' ;
                                board[size/2][3]='X' ;
                                board[size/2][size-4]='X' ;
                                board[3][size/2]='X' ;
                                board[size-4][size/2]='X' ;
				board[size/2][size/2]='X' ;
			}
			else {
				return 0 ;
			}
		}
	}
	return 1 ;
}
