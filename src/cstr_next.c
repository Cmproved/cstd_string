#include "../include/cstr.h"
#include <stdio.h>

void clear(cstr *c)
{
    free(c->_str);
    c->_str = my_strdup("\0");
    return;
}

cstr *copy(cstr *c)
{
    cstr *new = Cstr_create(c->_str);
    return (new);
}

char *front(cstr *c)
{
   return &(c->_str[0]);
}

char *back(cstr *c)
{
    size_t i = my_strlen(c->_str);
    return &(c->_str[i - 1]);
}

int empty(cstr c)
{
    return (my_strlen(c._str) == 0);
}

int append(cstr *c, const char *str)
{
    int c_len = my_strlen(c->_str);
    int str_len = my_strlen(str);
    int size = c_len + str_len + 1;
    char *a = malloc(sizeof(char) * size);
    int i = 0;

    if (a == NULL) {
        return (1);
    }

    for (i = 0; i < c_len && c->at(c, i) != 0; ++i) {
        a[i] = c->at(c, i);
    }

    for (int j = 0; j < str_len && i < size; ++i, ++j) {
        if (str[j] == 0) {
            a[i] = 0;
            break;
        }
        a[i] = str[j];
    }

    a[size - 1] = 0;

    c->set_str(c, a);
    free(a);
    return (0);
}

int append_s(cstr *c, const cstr b)
{
    return (append(c, b._str));
}

int push_back(cstr *c, const char str)
{
    char *a = malloc(2);

    if (a == NULL) {
        return (1);
    }

    a[0] = str;
    a[1] = 0;

    int result = append(c, a);
    free(a);
    return result;
}

int pop_back(cstr *c)
{
    size_t size = my_strlen(c->_str) - 1;
    char *a = malloc(size + 1);

    if (a == NULL) {
        return (1);
    }

    for (size_t i = 0; i < size; ++i) {
        a[i] = c->_str[i];
    }

    a[size] = '\0';
    c->set_str(c, a);
    free(a);
    return (0);
}
