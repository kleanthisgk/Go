// load.c

int load (char **board,char **strAll,int move,int size) {
	int i, j;
	if ( move > 0 ) {
		for ( i = 0 ; i < size ; i++ ) {
			for ( j = 0 ; j < size ; j++ ) {
				board[i][j]=strAll[move-1][size*i+j] ;	// fortwnei ti proigoumeni katastasi tou pinaka
			}
		}
		return 1;
	}
	else if ( move == 0 ) {				// an den exoun ginei kiniseis tote epistrefei ton pinaka adeio
		for ( i = 0 ; i < size ; i++ ) {
                        for ( j = 0 ; j < size ; j++ ) {
                                board[i][j]='.';
                        }
                }
		return 1;
	}
	return 0;
}
