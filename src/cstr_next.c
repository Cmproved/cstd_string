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
    cstr *new = Cstr(c->_str);
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
    size_t size = my_strlen(c->_str) + my_strlen(str);
    char *a = malloc(size);
    if (a == NULL) {
        return (1);
    }
    a = strcat(a, c->_str);
    a = strcat(a, str);
    c->set_str(c, a);
    return (0);
}

int append_s(cstr *c, const cstr b)
{
    return (append(c, b._str));
}

int push_back(cstr *c, const char str)
{
    // see flaws because of undefined \0
    return (append(c, &str));
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
    return (0);
}
