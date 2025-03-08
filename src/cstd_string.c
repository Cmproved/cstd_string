#include "../include/cstr.h"

const char *c_str(cstr *c)
{
    return (c->_str);
}

char at(cstr *c, size_t i)
{
    if (!c || c->len(c) < i)
        return(-1);
    return (c->_str[i]);
}

size_t len(cstr *c)
{
    return (my_strlen(c->_str));
}

void set_str(cstr *c, const char *str)
{
    if (!c || !str)
        return;
    free(c->_str);
    c->_str = my_strdup(str);
    return;
}

int my_str_equal(cstr *a, cstr *b)
{
    if (!a || !b)
        return (-1);
    if (!a->_str || *a->_str == '\0' || !b->_str || *b->_str == '\0')
        return (-2);
    if (my_strcmp(a->_str, b->_str))
        return (0);
    return (1);
}
