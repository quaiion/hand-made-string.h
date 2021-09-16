#include "san.h"

size_t my_strlen (const char str[]) {
    size_t num = 0;
    while (str[num] != '\0')
        num++;

    return num;
}

char* my_strchr (const char str[], int symcode) {
    int i = -1;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == symcode) return (char*) &str[i];      //      str + i === &str[i]
    
    if (symcode == '\0') return (char*) &str[i];

    return NULL;
}

char* my_strcpy (char strto[],  const char strfrom[]) {
    int i = -1;
    for (i = 0; strfrom[i] != '\0'; i++)
        strto[i] = strfrom[i];
    strto[i] = '\0';

    return strto;
}

char* my_strncpy (char strto[], const char strfrom[], size_t num) {
    int i = -1;
    for (i = 0; strfrom[i] != '\0' && i < num; i++)
        strto[i] = strfrom[i];

    for (; i < num; i++)
        strto[i] = '\0';

    return strto;
}

char* my_strcat (char strto[], const char strfrom[]) {
    int size = my_strlen (strto);
    int i = -1;

    for (i = 0; strfrom[i] != '\0'; i++)
        strto[size + i] = strfrom[i];
    strto[size + i] = '\0';

    return strto;
}

char* my_strncat (char strto[], const char strfrom[], size_t num) {
    int size = my_strlen (strto);
    int i = -1;

    for (i = 0; strfrom[i] != '\0' && i < num; i++)
        strto[size + i] = strfrom[i];
    strto[size + i] = '\0';

    return strto;
}

char* my_fgets (char str[], int num, FILE* file) {      //      Почему int num, а не size_t num?
    char symb = NULL;
    int i = -1;

    for (i = 0; !feof (file) && symb != '\n' && i < num; i++) {
        symb = fgetc (file);
        str[i] = symb;
    }
    str[i] = '\0';

    if (ferror (file) || i == 0) return NULL;

    return str;
}

char* my_strdup (const char initstr[]) {
    char* str = (char*) malloc ((my_strlen(initstr) + 1) * sizeof (char));
    return my_strcpy (str, initstr);
}

int my_getline (char* str[], size_t* size, FILE* file) {     //      char* str[] === char** str
    int symcode = -1;
    int i = -1;
    ssize_t real_buff_size = -1;

    fgetc (file);
    if (feof(file)) return -1;

    rewind (file);
    for (real_buff_size = 0; symcode != '\n'; real_buff_size++) {
        symcode = fgetc (file);
        if (feof(file)) break;
    }
    real_buff_size++;

    symcode = -1;
    rewind (file);

    if (*str == NULL) {
        char* str0 = NULL;
        str0 = (char*) malloc ((real_buff_size) * sizeof (char));
        if (str0 == NULL) return -1;
        *str = str0;

        *size = real_buff_size;

        for (i = 0; i < real_buff_size - 1; i++) {
            symcode = fgetc (file);
            (*str)[i] = symcode;
        }
        (*str)[i] = '\0';

        if (ferror (file)) return -1;

        return real_buff_size - 1;
    }

    if (real_buff_size > *size) {
        char* str0;
        str0 = (char*) realloc (*str, real_buff_size * sizeof (char));
        if (str0 == NULL) return -1;
        *str = str0;

        *size = real_buff_size;

        for (i = 0; i < real_buff_size - 1; i++) {
            symcode = fgetc (file);
            (*str)[i] = symcode;
        }
        (*str)[i] = '\0';

        if (ferror (file)) return -1;

        return real_buff_size - 1;
    }

    for (i = 0; i < real_buff_size - 1; i++) {
        symcode = fgetc (file);
        (*str)[i] = symcode;
    }
    (*str)[i] = '\0';

    if (ferror (file)) return -1;

    return real_buff_size - 1;
}