#include "string_util.h"

void ReadStrings(char **strings, int *nstrings, int maxstrings, FILE *fp)
{
    char string[MAX_STRINGS_LENGTH];
    *nstrings = 0;
    while (fgets(string, MAX_STRINGS_LENGTH, fp))
    {
        strings[(*nstrings)++] = strdup(string);
        if (*nstrings >= maxstrings)
            break;
    }
}

void WriteStrings(char **strings, int nstrings, FILE *fp)
{
    int i;
    for (i = 0; i < nstrings; i++)
        fprintf(fp, "%s", strings[i]);
}

int CompareStrings(char *string1, char *string2)
{
    char *p1 = string1;
    char *p2 = string2;
    while (*p1 && *p2)
    {
        if (*p1 < *p2)
            return -1;
        else if (*p1 > *p2)
            return 1;
        p1++;
        p2++;
    }
    return 0;
}

void SortStrings(char **strings, int nstrings)
{
    int i, j;
    for (i = 0; i < nstrings; i++)
    {
        for (j = i + 1; j < nstrings; j++)
        {
            if (CompareStrings(strings[i], strings[j]) > 0)
            {
                char *swap = strings[i];
                strings[i] = strings[j];
                strings[j] = swap;
            }
        }
    }
}
