
// find.c

#include <string.h>

int find ( char ** strAll, char *str, int move){
	int i;
	if ( move-2 >= 0 ) {
			if ( strcmp(str,strAll[move-2]) == 0 ) {	// sugkrinei ti twrini katastasi me tis proigoumenes kai an i twrini katastasi tou pinaka exei prouparksei
				return 1;			// epistrefei 1
			}
	}
	return 0;					// alliws 0
}
