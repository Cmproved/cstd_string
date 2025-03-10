#include "../include/cstr.h"

cstr *_copy_values(cstr *s)
{
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
    s->resize = &resize;
    s->clear = &clear;
    return (s);
}

cstr *Cstr_create(const char *str)
{
    cstr *s = malloc(sizeof(cstr));

    if (s == NULL) {
        return (NULL);
    }

    if (!str || *str == '\0') {
        free(s);
        return (NULL);
    }

    s->_str = my_strdup(str);

    if (!s->_str){
        free(s);
        return (NULL);
    }

    _copy_values(s);
    return (s);
}

void Cstr_destroy(cstr *c)
{
    free((void *)c->_str);
    free((void *)c);
}
