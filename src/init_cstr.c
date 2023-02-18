#include "../include/cstr.h"

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
    s->front = &front;
    s->back = &back;
    s->empty = &empty;
    s->append = &append;
    s->append_s = &append_s;
    s->push_back = &push_back;
    s->pop_back = &pop_back;
    return (s);
}

void Cstr_destroy(cstr *c)
{
    free((void *)c->_str);
    free((void *)c);
}
