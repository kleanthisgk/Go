
// main.c

#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "play.h"
#include "handicap.h"
#include <string.h>

int main (int argc, char *argv[]) {
	int size, i, flag=0, flag2=0, flag3=0, flag4=0, flag5=0, j, c, d, k, h, p, b, g, move=0 ;
	unsigned int s ;
	char **board ,string[25], *str,**strAll, n ;
	float komi=7.5 ,pontoi=0.0 ;
	if ( strcmp(argv[1],"-seed") == 0 && argc == 3 ) {
		s=atoi(argv[2]) ;
	}
	else {
		printf( "Sorry,cannot run without -seed\n" ) ;
		fflush(stdout) ;
		return -5 ;
	}
	do {
		scanf( "%s",string ) ;
		if ( strcmp("boardsize",string) == 0 ) {	// elegxos an to string einai iso me boardsize
			scanf( "%d",&size ) ;
			if ( size > 1 && size < 26 ) {		// elegxos an to size einai swsto
				move=0 ;
				printf( "=\n\n" ) ;
				fflush(stdout) ;
				flag4=1 ;
	        		board=malloc(size*sizeof(char *)) ;		// dunamiki desmeusi mnimis gia to board me megethos size
        			if ( board == NULL ) {
					printf( "Sorry,cannot allocate memory\n" ) ;
					fflush(stdout) ;
                			return -1 ;
	        		}
        			for ( i = 0 ; i < size ; i++ ) {
                			board[i]=malloc(size*sizeof(char)) ;
                			if ( board[i] == NULL ) {
						printf( "Sorry,cannot allocate memory\n" ) ;
						fflush(stdout) ;
                        			return -2 ;
                			}
        			}
				make_board(board,size) ;			// kalese ti make_board gia dimiourgia tou pinaka
			}
			else {
				printf( "? unacceptable size\n\n" ) ;
				fflush(stdout) ;
			}
			flag5=1 ;
			strAll=malloc(sizeof(char *)) ;				// dimiourgia tou pinaka katastasewn
			if ( strAll == NULL ) {
				printf( "Sorry,cannot allocate memory\n" ) ;
				fflush(stdout) ;
				return -1 ;
			}
			*strAll=malloc((size*size+1)*sizeof(char)) ;
			if ( *strAll == NULL ) {
				printf( "Sorry,cannot allocate memory\n" ) ;
				fflush(stdout) ;
				return -1 ;
			}
		}
		else if ( strcmp("showboard",string ) == 0 ) {		// elegxos an to string einai iso me showboard
			printf( "=\n" ) ;
			fflush(stdout) ;
			show_board(board,size) ;			// klisi tis show_board gia tin emfanisi tou pinaka stin othoni
		}
		else if ( strcmp("play",string ) == 0 ) {		// elegxos an to string einai iso me play
			c=play_move(board,size) ;			// klisi tis sunartisis gia tin kinisi
			if ( c == 1 || c == 2 ) {					// an einai epitixis
				str=string_maker(board,size) ;		// ftiakse string gia ti nea katastasi
				if ( find(strAll,str,move) == 0 || c == 2 ) {	// an den einai idia
					move++ ;			// auksise ti kinisi kata 1
					strAll=realloc(strAll,(move)*sizeof(char *)) ;	// desmeuse mnimi gia mia nea kinisi
					if (strAll == NULL ) {
						printf( "Sorry,cannot allocate memory\n" ) ;
						fflush(stdout) ;
						return -1 ;
					}
					strAll[move-1]=malloc(((size*size)+1)*sizeof(char));
					if ( strAll == NULL ) {
						printf( "Sorry,cannot allocate memory\n" ) ;
						fflush(stdout) ;
               					return -1 ;
        				}
					strAll[move-1]=strcpy(strAll[move-1],str) ;	// ekxorisi tis neas katastasis tou pinaka sti lista me tis grammes
				}
				else {
					load(board,strAll,move,size) ;			// alliws fortwse ti proigoumeni katastasi tou pinaka
					c=0 ;
				}
			}
			if ( c == 1 || c == 2 ) {					// an i kinisi einai egkuri
				flag2=1 ;						// an exei paiztei egkuri kinisi i flag2 einai 1
				printf( "= \n\n" ) ;
				fflush(stdout) ;
			}
			else {
				printf( "? illegal move\n\n" ) ;			// alliws einai paranomi
				fflush(stdout) ;
			}
		}
		else if ( strcmp("clear_board",string) == 0 ) {	// elegxos an to string einai iso me clear_board
			printf( "=\n\n" ) ;
			fflush(stdout) ;
			for ( i = 0 ; i < size ; i++ ) {
				for ( j = 0 ; j < size ; j++ ) {
					board[i][j]='.' ;	// katharismos tou pinaka
				}
			}
			for ( i = 0 ; i < move ; i++ ) {
				free(strAll[i]) ;		// apeleutherwsi mnimis
			}
			free(strAll);
			move=0;					// diagrafi metriti kinisewn
			strAll=malloc(sizeof(char *));
                        if ( strAll == NULL ) {
				printf( "Sorry,cannot allocate memory\n" ) ;
				fflush(stdout) ;
                                return -1 ;
                        }
                        *strAll=malloc((size*size+1)*sizeof(char));
                        if ( *strAll == NULL ) {
				printf( "Sorry,cannot allocate memory\n" ) ;
				fflush(stdout) ;
                                return -1 ;
                        }
		}
		else if ( strcmp("genmove",string) == 0 ) {	// elegxos an to string einai iso me genmove
			g=genmove(board,size,string,s,strAll,move,str,c) ;			// klisi tis sunartisis gia kinisi tis mixanis
			str=string_maker(board,size);
			//if ( find(strAll,str,move) == 0 || c == 0 ) {
			move++ ;
			strAll=realloc(strAll,(move)*sizeof(char *));
			if ( strAll == NULL ) {
				printf( "Sorry,cannot allocate memory\n" ) ;
				fflush(stdout) ;
	               		return -1 ;
	       		}
			strAll[move-1]=malloc(((size*size)+1)*sizeof(char));
			if ( strAll == NULL ) {
				printf( "Sorry,cannot allocate memory\n" ) ;
				fflush(stdout) ;
               			return -1 ;
       			}
			strAll[move-1]=strcpy(strAll[move-1],str);
          		/*else {
				load(board,strAll,move,size);
                 		c=0;
               		}*/
			if ( g == 1 ) {
				flag2=1 ;
				printf( "= %s\n\n",string) ;
				fflush(stdout) ;
			}
			else if ( g == 0 ) {
				//load(board,strAll,move,size) ;
				printf( "= pass\n\n" ) ;
				fflush(stdout) ;
			}
		}
		else if ( strcmp("protocol_version",string) == 0 ) {	// elegxos an to string einai iso me protocol_version
			printf( "= 2\n\n" ) ;
			fflush(stdout) ;
		}
		else if ( strcmp("name",string) == 0 ) {		// elegxos an to string einai iso me name
			printf( "= GNU Go\n\n" ) ;
			fflush(stdout) ;
		}
		else if ( strcmp("version",string) == 0 ) {		// elegxos an to string einai iso me version
			printf( "= 1.0\n\n" ) ;
			fflush(stdout) ;
		}
		else if ( strcmp("known_command",string) == 0 ) {	// elegxos an to string einai iso me known_command
			scanf( "%s",string ) ;
			if ( strcmp("set_free_handicap",string) == 0 || strcmp("place_free_handicap",string) == 0 || strcmp("undo",string) == 0 || strcmp("final_score",string) == 0 || strcmp("fixed_handicap",string) == 0 || strcmp("quit",string) == 0 || strcmp("boardsize",string) == 0 || strcmp("showboard",string ) == 0 || strcmp("play",string ) == 0 || strcmp("clear_board",string) == 0 || strcmp("genmove",string) == 0 || strcmp("protocol_version",string) == 0 || strcmp("name",string) == 0 || strcmp("version",string) == 0 || strcmp("known_command",string) == 0 || strcmp("list_commands",string) == 0 || strcmp("komi",string) == 0 ) {
				printf( "= true\n\n" ) ;
				fflush(stdout) ;
			}
			else {
				printf( "= false\n\n" ) ;
				fflush(stdout) ;
			}
		}
		else if ( strcmp("list_commands",string) == 0 ) {	// elegxos an to string einai iso me list_commands
			printf( "= \n\nset_free_handicap\nplace_free_handicap\nfinal_score\nprotocol_version\nname\nversion\nknown_command\nlist_commands\nquit\nboardsize\nclear_board\nkomi\nplay\ngenmove\nfixed_handicap\nundo\n\n" ) ;
			fflush(stdout) ;
		}
		else if ( strcmp("komi",string) == 0 ) {		// elegxos an to string einai iso me komi
			scanf( "%f",&komi ) ;
			printf( "=\n\n" ) ;
			fflush(stdout) ;
		}
		else if ( strcmp("quit",string) == 0 ) {		// elegxos an to string einai iso me quit
			printf( "=\n\n" ) ;
			fflush(stdout) ;
			flag=1 ;
		}
		else if ( strcmp("fixed_handicap",string) == 0 || strcmp("place_free_handicap",string) == 0 ) {	 // elegxos an to string einai iso me fixed_handicap i place_free_handicap
			scanf( "%d",&p ) ;
			if (  flag2 == 0 ) {		// elegxei an exei paixtei kinisi
				if ( strcmp("fixed_handicap",string) == 0 ) {
					h=f_handicap(board,size,&p) ;
				}
				else if ( strcmp("place_free_handicap",string) == 0 ) {
					h=p_handicap(board,size,&p,s) ;
				}
				if ( h == 1 ) {						// an einai epitixes to apotelesma
					flag2=1 ;
					printf( "=" ) ;
					for ( i = 0 ; i < size ; i++ ) {		// ektupwse tis theseis pou xrisimopoiithe to handicap
						for ( j = 0 ; j < size ; j++ ) {
							if ( board[i][j] == 'X' ) {
								if ( j >= 8 ) {
									n='A'+j+1 ;
								}
								else {
									n='A'+j ;
								}
								printf( " %c%d",n,size-i) ;
								fflush(stdout) ;
							}
						}
					}
					printf( "\n\n" ) ;
					fflush(stdout) ;
				}
				else if ( h == 0 ) {					// an einai lathos o arithmos petrwn
					printf( "? invalid number of stones\n\n" ) ;
					fflush(stdout) ;
				}
				else {
					printf( "? handicap not available\n\n" ) ;	// an den einai diathesimo to handicap
					fflush(stdout) ;
				}
			}
			else {
				printf( "? board not empty\n\n" ) ;			// an exei idi paixtei kinisi
				fflush(stdout) ;
			}
		}
		else if ( strcmp("set_free_handicap",string) == 0 ) {			// idia logiki me ta  proigoumena handicap
			if ( flag2 == 0 ) {
				h=s_handicap(board,size) ;
				if ( h == 1 ) {
					flag2=1 ;
					printf( "=\n\n" ) ;
					fflush(stdout) ;
				}
				else if ( h == 0 ) {
					printf( "? invalid number of stones\n\n" ) ;
					fflush(stdout) ;
				}
				else if ( h == 2 ) {
					printf( "? cannot place handicap\n\n" ) ;
				}
			}
			else {
				printf( "? board not empty\n\n" ) ;
                                fflush(stdout) ;
			}
		}
		else if ( strcmp("undo",string) == 0 ) {
			if ( load(board,strAll,move-1,size) == 1 ) {			// fortwsi tis proigoumenis katastasis tous pinaka
				move-- ;
				free(strAll[move]) ;
				printf( "= \n\n" ) ;
				fflush(stdout) ;
			}
			else {
				printf( "? cannot undo\n\n" ) ;
			}
		}
		else if ( strcmp("final_score",string) == 0 ) {
			pontoi=score(board,size,strAll,move) ;
			if ( pontoi > 0 ) {						//an oi 'pontoi' einai thetikoi o nikitis einai o aspros
				printf( "= W+%.1f\n\n",pontoi*2+komi ) ;
				fflush(stdout) ;
			}
			else if ( pontoi < 0 ) {					//an oi 'pontoi' einai arnitikoi o nikitis einai o mauros
				printf( "= B+%.1f\n\n",(-pontoi*2)-komi ) ;
				fflush(stdout) ;
			}
			else {								// alliws isopalia
				printf( "= 0\n\n" ) ;
				fflush(stdout) ;
			}
		}
		else {
			printf( "? unknown command\n\n" ) ;				// an to string pou diavase den isoutai me kamia apo tis entoles tote einai  unknown command
			fflush(stdout) ;
		}
	} while ( !flag ) ;
	if ( flag4 == 1 ) {
		for ( i = 0 ; i < size ; i++ ) {					// apeleutherwsi tis board
			free(board[i]) ;
		}
		free(board) ;
	}
	if ( flag5 == 1 ) {								// apeleutherwsi tis strAll
		for ( i=0 ; i < move-1 ; i++ ) {
			free(strAll[i]) ;
		}
		free(strAll) ;
	}
	return 0 ;
}
