#include <stdio.h>
#include "board.h"

void show_board(char **board,int size) {
	int i, j ;
	char c ;
	for ( i = -1 ; i <= size ; i++ ) {
		for ( j = -1 ; j <= size ; j ++ ) {
			if ( i == -1 || i == size ) {	// elegxos an vriskomaste sti grammi -1 i sti grammi size opou ektuponontai ta grammata
				if ( size >= 9 ) {	// elegxos an to size einai megalutero tou 9
					if ( j == -1 ) {	// elegxos an vriskomaste sti stili -1 opou ektuponontai oi arithmoi
						if ( size > 9 ) {	// an size > 9
							printf( "   " ) ;	// tote xreiazomaste 3 kena sitn arxi giati o arithmos einai 2psifios
							fflush(stdout) ;
						}
						else {
							printf( "  " ) ;	// alliws xreiazomaste 2 kena
							fflush(stdout) ;
						}
					}
					else {
						if ( 'A'+j != 'I' ) {		// elegxos an to gramma einai I
							c='A'+ j ;	// an den einai tote ektuponetai
							printf( "%c ",c ) ;		// exoume ena keno anamesa sta grammata
							fflush(stdout) ;
						}
					}
				}
				else {						// alliws an size < 9
					if ( j == -1 || j == size ) {		// kai vriskomaste stis stiles pou ektuponontai oi arithmoi
						printf( "  " ) ;		// xreiazomaste 2 kena
						fflush(stdout) ;
					}
					else {					// an eimmaste stis stiles pou ektuponontai ta grammata
						c='A'+ j ;		//ektupwse ta
						printf( "%c ",c) ;			// me kena endiamesa
						fflush(stdout) ;
					}
				}
			}
			else {							// an vriskomaste stis grammes pou ektuponontai ta stoixeia tou pinaka kai oi aritmhoi
				if ( j  == -1 ) {				// an vriskomaste sti stili pou ektuponontai arithmoi
					if ( size > 9 ) {			// an to size einai megalutero tou 9
						printf( "%2d ",size-i ) ;	// tote ektupwse to demseuontas 2 theseis
						fflush(stdout) ;
					}
					else {
						printf( "%d ",size-i ) ;	// alliws desmeuontas mia thesi
						fflush(stdout) ;
					}
				}
				else if ( j == size ) {				// to idio me to an j=-1
					if ( size > 9 ) {
						printf( "%-2d",size-i ) ;
						fflush(stdout) ;
					}
					else {
						printf( "%d",size-i ) ;
						fflush(stdout) ;
					}
				}
				else {
					printf( "%c ",board[i][j] ) ;	// alliws ektupwse ta stoixeia tou pinaka
					fflush(stdout) ;
				}
			}
		}
		printf( "\n" ) ;
		fflush(stdout) ;
	}
	printf( "\n" ) ;
	fflush(stdout) ;
	return ;
}
