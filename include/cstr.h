#pragma once
#include <stddef.h>
#include <stdlib.h>

typedef struct cstring_s {
// values
    char *_str;

// methods
    const char *(*c_str)(struct cstring_s *c);
    const char (*at)(struct cstring_s *, size_t);
    const size_t (*len)(struct cstring_s *);
    void (*set_str)(struct cstring_s *, const char *);
    struct cstring_s *(*copy)(struct cstring_s *);
    void (*clear)(struct cstring_s *);
} cstring;

// less chars typedef
typedef cstring cstr;

cstr *Cstr(const char *str);
void Cstr_destroy(cstr *s);

const char *c_str(cstr *s);
const char at(cstr *s, size_t i);
size_t my_strlen(const char *str);
const size_t len(cstr *s);
void set_str(cstr *s, const char *str);
char *my_strcpy(char *dest, const char *str);
char *my_strdup(const char *str);
int my_strcmp(const char *a, const char *b);
int is_str_equal(cstr *s, cstr *b);
cstr *copy(cstr *c);
