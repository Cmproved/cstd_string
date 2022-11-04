#include "cstr.h"

cstr *Cstr(const char *str)
{
    cstr *s = (cstr *)malloc(sizeof(cstr));

    if (!s || !str || *str == '\0')
        return (NULL);
    s->_str = my_strdup(str);
    if (!s->_str){
        free(s);
        return (NULL);
    }
    s->at = &at;
    s->c_str = &c_str;
    s->set_str = &set_str;
    s->len = &len;
    return (s);
}

void Cstr_destroy(cstr *c)
{
    free((void *)c->_str);
    free((void *)c);
}
