#define MAX_STRINGS 128
#define MAX_STRING_LENGTH 256



void ReadStrings(char **strings, int *nstrings, int maxstrings, FILE *fp);
void WriteStrings(char **strings, int nstrings, FILE *fp);
int CompareStrings(const char *string1, const char *string2);
void SortStrings(char **strings, int nstrings);


