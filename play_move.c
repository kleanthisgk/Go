// play_move.c

#include <stdio.h>
#include "play.h"

int play_move(char **board,int size) {
	char s1[10], s2[10], player ;
	int i, j ,f ,k ,p, s ;
	scanf( "%s",s1 ) ;		// diavase to string gia to xrwma
	scanf( "%s",s2 ) ;		// diavase to sting gia ti kinisi
	if ( strcmp(s1,"BLACK") == 0 || strcmp(s1,"B") == 0 || strcmp(s1,"b") == 0 || strcmp(s1,"black") == 0 ) {	// elegxos gia oles tis pithanes egkures lexeis gia black i white
		player='X' ;
	}
	else if ( strcmp(s1,"WHITE") == 0 || strcmp(s1,"W") == 0 || strcmp(s1,"w") == 0 || strcmp(s1,"white") == 0 ) {
		player='O' ;
	}
	else {
		return 0 ;
	}
	if ( strcmp(s2,"pass") == 0 || strcmp(s2,"PASS") == 0 ) {
		return 2 ;
        }
	else if ( s2[0] <= 'z' && s2[0] >= 'a' ) {		// elegxos an to gramma einai pezo
		if ( s2[0] > 'i' ) {			// elegxos an einai aristera tou i
			j=s2[0]-1-'a' ;
		}
		else if ( s2[0] == 'i' ) {		//elegxos an einai i
			return 0 ;
		}
		else {
			j=s2[0]-'a' ;
		}
	}
	else if ( s2[0] <= 'Z' && s2[0] >= 'A' ) {	// elegxos an einai kefalaio
		if ( s2[0] > 'I' ) {
			j=s2[0]-1-'A' ;
		}
		else if ( s2[0] == 'I' ) {
			return 0 ;
		}
		else {
			j=s2[0]-'A' ;
		}
	}
	else {
		return 0 ;
	}
	if ( j < 0 || j >= size ) {		// elegxos an i stili einai entos size
		return 0 ;
	}
	if ( s2[2] == '\0' ) {			// elegxos an o arithmos einai monopisifios
		i=size-(s2[1]-'0') ;		// metatropi tou sting se arithmo an einai monopsifios
	}
	else {
		i=size-((s2[1]-'0')*10+(s2[2]-'0')) ;	// metatropi tou sting se arithmo an einai dipsifios
	}
	if ( i < 0 || i >= size ) {		// elegxos an oi grammi einai entos size
		return 0 ;
	}
	if ( board[i][j] == 'O' || board[i][j] == 'X' ) {	// elegxos an to stixeio einai idi X i O
		return 0 ;
	}
	else {
		board[i][j]=player ;
		f=liberties(board,size,i,j,player) ;	// vres tis eleutheries tou stoixeiou board[i][j]
		if ( f == 0 ) {				// an exei 0 eleutheries
			if ( capture(board,i,j,size,player) == 0 ) {	// kai de kanei capture
				board[i][j]='.';			// kanto pali .
				return 0 ;
			}
		}
		else {
			capture(board,i,j,size,player) ;
		}
	}
	return 1 ;			//gia epitixis kinisi
}
