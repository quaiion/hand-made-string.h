#include "san.h"
#include <stdio.h>
#include <string.h>

int main () {

    FILE* fl = fopen ("fl.txt", "r");
    size_t size = 3;
    char** str;
    *str = (char*) calloc (3, sizeof (char));
    my_getline (str, &size, fl);
    puts (*str);
    fclose (fl);
    return 0;
}