#include "../include/cstr.h"

int my_strcmp(const char *str1, const char *str2)
{
    int i = 0;
    if (my_strlen(str1) != my_strlen(str2))
        return (1);

    for (; str1[i] == str2[i] && str1[i] != 0 && str2[i] != 0; i++);

    return (str1[i] - str2[i]);
}

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    if (!dest || !src || *src == '\0') {
        return (NULL);
    }
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(const char *str)
{
    char *str_dup = NULL;

    if (!str || *str == '\0') {
        return (str_dup);
    }
    str_dup = malloc(sizeof(char) * my_strlen(str) + 1);
    if (!str_dup) {
        return (NULL);
    }
    str_dup = my_strcpy(str_dup, str);
    return (str_dup);
}

size_t my_strlen(const char *str)
{
    unsigned int i = 0;

    if (!str || *str == '\0') {
        return (0);
    }
    for (i = 0; str[i] != 0; ++i);
    return (i);
}
