// string_maker.c

#include "play.h"
#include <stdlib.h>

char *string_maker (char **board,int size) {
	char *str ;
	int i,j ;
	str=malloc(((size*size)+1)*sizeof(char));
	for ( i = 0 ; i < size ; i++ ) {
		for ( j = 0 ; j < size ; j++ ) {
			str[i*size+j]=board[i][j] ;	// dimiourgise ena string gia kathe katastasi tou pinaka
		}
	}
	str[size*size+1]='\0';
	return str;
}

