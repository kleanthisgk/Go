// play.h

int play_move(char **, int) ;
int liberties(char **, int , int , int, char) ;
int freedoms(char **, int , int , int, char) ;
int capture(char **, int, int, int,char);
void capture2(char **, int, int, int,char);
int genmove(char **, int,char *,int,char **,int,char *,int) ;
int load(char **, char **, int, int) ;
char *string_maker(char **,int) ;
int find(char **, char *, int) ;
float score(char **, int, char **, int) ;
