#include "../include/cstr.h"
#include <stdio.h>

int main(void)
{
    Cstr a = Cstr_create("Bonjour");
    printf("%s\n", a->c_str(a));
    a->pop_back(a);
    printf("%s\n", a->c_str(a));
    a->push_back(a, 'r');
    printf("%s\n", a->c_str(a));

    Cstr_destroy(a);
    return (0);
}
