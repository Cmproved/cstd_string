#include "../include/cstr.h"
#include <stdio.h>

int main(void)
{
    Cstr a = Cstr_create("Bonjour");
    printf("%s\n", a->c_str(a));

    a->resize(a, 4, 'r');
    printf("%s\n", a->c_str(a));

    a->clear(a);
    printf("%s\n", a->c_str(a));
    Cstr_destroy(a);
    return (0);
}
