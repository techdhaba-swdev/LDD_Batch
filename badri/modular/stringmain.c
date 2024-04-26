#include "stringmain.h"
int main() {
char *strings[MAX_SIZE] = {NULL};
int nstrings = 0;
Stringread(strings, &nstrings); 
Stringsort(strings, nstrings);
Stringprint(strings, nstrings);
// Free allocated memory 
 for (int i= 0; i <nstrings; i++){ 
 free(strings[i]);
 }
return 0;
}
