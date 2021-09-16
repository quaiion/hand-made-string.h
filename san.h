#ifndef SAN
#define SAN

#include <stdio.h>
#include <stdlib.h>

size_t my_strlen (const char str[]);

char* my_strchr (const char str[], int symcode);

char* my_strcpy (char strto[], const char strfrom[]);

char* my_strncpy (char strto[], const char strfrom[], size_t num);

char* my_strcat (char strto[], const char strfrom[]);

char* my_strncat (char strto[], const char strfrom[], size_t num);

char* my_fgets (char str[], int num, FILE* file);

char* my_strdup (const char initstr[]);

int my_getline (char** str, size_t* size, FILE* file);

#endif