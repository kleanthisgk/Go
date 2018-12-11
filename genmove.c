// genmove.c

#include <stdio.h>
#include <time.h>
#include "play.h"

int genmove(char **board,int size,char *str,int s, char **strAll, int move,char *string,int c) {
	int i, j, f , r, t, x, y, k, p, o, plevres, flag=0, m=0, n=0 ,w=0, u=0, z=0 ;
	char s1[10] ;
	char l, player, rival ;
	float v;
	scanf( "%s",s1 ) ;
	srand(s) ;
	if ( strcmp(s1,"BLACK") == 0 || strcmp(s1,"B") == 0 || strcmp(s1,"b") == 0 || strcmp(s1,"black") == 0 ) {
		player='X' ;
		rival='O';
	}
	else if ( strcmp(s1,"WHITE") == 0 || strcmp(s1,"W") == 0 || strcmp(s1,"w") == 0 || strcmp(s1,"white") == 0 ) {
		player='O' ;
		rival='X';
	}
	if ( c == 2 ) {
		if ( ( score(board,size,strAll,move) < 0 && player == 'X' ) || ( score(board,size,strAll,move) > 0 && player == 'O' ) ) {
			return 0 ;
		}
	}
	for ( i = 0 ; i < size ; i++ ) {
                for ( j = 0 ; j < size ; j++ ) {
			if ( board[i][j] == player && liberties(board,size,i,j,board[i][j]) == 1 ) {
				freedoms(board,size,i,j,player) ;
				for ( x = 0 ; x < size ; x++ ) {
                			for ( y = 0 ; y < size ; y++ ) {
						if ( board[x][y] == 'k' ) {
							board[x][y]=player ;
						}
					}
				}
				for ( x = 0 ; x < size ; x++ ) {
                                        for ( y = 0 ; y < size ; y++ ) {
                                                if ( board[x][y] == 'c' ) {
							board[x][y]=player ;
							if ( liberties(board,size,x,y,board[x][y]) <= 1 && capture(board,x,y,size,board[x][y]) == 0 ) {
								board[x][y]='.' ;
								continue ;
							}
							string=string_maker(board,size) ;
							if ( find(strAll,string,move) == 1 ) {
								load(board,strAll,move,size) ;
								continue ;
							}
							else {
								if ( y >= 8 ) {
                							str[0]='A'+y+1 ;
        							}
        							else {
      									str[0]='A'+y ;
        							}
        							if ( ((size-x)/10) > 0 ) {
                							str[1]=(((size-x)/10)+'0');
                							str[2]=(((size-x)%10)+'0');
                							str[3]='\0';
        							}
        							else {
                							str[1]=(size-x+'0') ;
                							str[2]='\0';
        							}
								return 1;
							}
                                        	}
					}
                                }
			}
		}
	}
	for ( i = 0 ; i < size ; i++ ) {
		for ( j = 0 ; j < size ; j++ ) {
			 if ( board[i][j]==rival && liberties(board,size,i,j,board[i][j]) == 1 ) {
				freedoms(board,size,i,j,rival);
				for ( x = 0 ; x < size ; x++ ) {
                                        for ( y = 0 ; y < size ; y++ ) {
                                                if ( board[x][y] == 'k' ) {
							board[x][y]=rival ;
						}
                                        }
                                }
                                for ( x = 0 ; x < size ; x++ ) {
                                        for ( y = 0 ; y < size ; y++ ) {
                                                if ( board[x][y] == 'c' ) {
							board[x][y]=player;
							capture(board, x, y, size , player) ;
							string=string_maker(board,size) ;
							if ( find(strAll,string,move) == 0 ) {
								if ( y >= 8 ) {
 					               			str[0]='A'+y+1 ;
        							}
        							else {
                							str[0]='A'+y ;
        							}
        							if ( ((size-x)/10) > 0 ) {
                							str[1]=(((size-x)/10)+'0');
                							str[2]=(((size-x)%10)+'0');
                							str[3]='\0';
        							}
        							else {
                							str[1]=(size-x+'0') ;
                							str[2]='\0';
        							}
								return 1;
							}
							else {
								load(board,strAll,move,size) ;
								continue ;
							}
						}
                                        }
                                }
			}
		}
	}
	for ( i = 0 ; i < size ; i++ ) {
		for ( j = 0 ; j < size ; j++ ) {
			if ( board[i][j] == '.' ) {
				plevres=0;
				t=0 ;
				o=0 ;
				if ( i < size-1 ) {
					plevres++;
			                if ( board[i+1][j] == player ) {
						t++;
	          			}
					else if (board[i+1][j] == rival ) {
						o++;
					}
        			}
        			if ( j < size-1 ) {
					plevres++;
                			if ( board[i][j+1] == player ) {
						t++;
                			}
					else if (board[i][j+1] == rival ) {
                                                o++;
                                        }
        			}
        			if ( i > 0 ) {
					plevres++;
                			if ( board[i-1][j] == player ) {
						t++;
                			}
					else if (board[i-1][j] == rival ) {
                                                o++;
                                        }
        			}
        			if ( j > 0 ) {
					plevres++;
                			if ( board[i][j-1] == player ) {
						t++;
					}
					else if (board[i][j-1] == rival ) {
                                                o++;
                                        }
        			}
				if ( t != plevres && o != plevres ) {
					flag=1 ;
					break ;
				}
			}
		}
		if ( flag == 1) {
			break ;
		}
	}
	if ( flag == 0 ) {
		return 0 ;
	}
	do {
               	i=rand()%size ;
               	j=rand()%size ;
		if ( board[i][j] == '.' ) {
			board[i][j]=player ;
			f=liberties(board,size,i,j,board[i][j]);
                       	if ( f == 0 ) {
                   	        if ( capture(board,i,j,size,player ) == 0 ) {
                                       	board[i][j]='.' ;
					w++ ;
					if ( w > 50 ) {
						return 0 ;
					}
					else {
						continue ;
					}
                             	}
			}
                       	else {
                              	capture(board,i,j,size,player) ;
				string=string_maker(board,size) ;
			}
			if ( find(strAll,string,move) == 1 ) {
				load(board,strAll,move,size) ;
				z++ ;
				if ( z > 50 ) {
					return 0 ;
				}
				else {
					continue ;
				}
			}
			else {
				if ( j >= 8 ) {
                			str[0]='A'+j+1 ;
        			}
        			else {
                			str[0]='A'+j ;
        			}
        			if ( ((size-i)/10) > 0 ) {
                			str[1]=(((size-i)/10)+'0');
                			str[2]=(((size-i)%10)+'0');
                			str[3]='\0';
        			}
        			else {
                			str[1]=(size-i+'0') ;
                			str[2]='\0';
        			}
				return 1 ;
			}
		}
       	} while ( 1 ) ;
}
