#include "../include/cstr.h"

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;
    if (my_strlen(str1) != my_strlen(str2))
        return (1);

    for (; str1[i] == str2[i] && str1[i] != 0 && str2[i] != 0; i++);

    return (str1[i] - str2[i]);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!dest || !src || *src == '\0')
        return (NULL);
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *str)
{
    char *str_dup = NULL;

    if (!str || *str == '\0')
        return (str_dup);
    str_dup = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (!str_dup)
        return (NULL);
    str_dup = my_strcpy(str_dup, str);
    return (str_dup);
}

size_t my_strlen(char const *str)
{
    unsigned int i = 0;

    if (!str || *str == '\0')
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}
