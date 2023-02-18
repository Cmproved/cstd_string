#include "../include/cstr.h"
#include <stdio.h>

int main(void)
{
    cstr *a = Cstr("Bonjour");
    printf("%s\n", a->c_str(a));
    a->pop_back(a);
    printf("%s\n", a->c_str(a));
    a->push_back(a, 'r');
    printf("%s\n", a->c_str(a));
    return (0);
}
