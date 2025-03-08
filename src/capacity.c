#include "../include/cstr.h"

int resize(Cstr s, size_t new_size, char fill)
{
    size_t len = s->len(s);

    if (len == new_size) {
        return (0);
    }

    if (len > new_size) {
        int size_diff = len - new_size;

        for (int i = 0; i < size_diff; ++i) {
            s->pop_back(s);
        }

        return (0);
    }

    int size_diff = new_size - len;

    for (int i = 0; i < size_diff; ++i) {
        s->push_back(s, fill);
    }

    return (0);
}

int clear(Cstr c)
{
    free(c->_str);
    c->_str = my_strdup("\0");
    return (0);
}

int empty(cstr c)
{
    return (my_strlen(c._str) == 0);
}

