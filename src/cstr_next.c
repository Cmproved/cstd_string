#include "cstr.h"

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
