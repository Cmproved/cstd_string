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
    if (!dest || !src || *src == '\0') {
        return (NULL);
    }

    int len = my_strlen(src);

    for (int i = 0; src[i] != '\0' && i < len; i++) {
        dest[i] = src[i];
    }

    dest[len] = '\0';
    return (dest);
}

char *my_strdup(const char *str)
{
    if (!str || *str == '\0') {
        return (NULL);
    }

    const int len = my_strlen(str);
    char *str_dup = malloc(sizeof(char) * (len + 1));

    if (!str_dup) {
        return (NULL);
    }

    str_dup = my_strcpy(str_dup, str);
    return (str_dup);
}

size_t my_strlen(const char *str)
{
    unsigned int i = 0;

    if (str == NULL || str[0] == 0) {
        return (0);
    }

    for (i = 0; str[i] != 0; ++i);
    return (i);
}
