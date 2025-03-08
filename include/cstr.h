#pragma once
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct cstring_s {
// values
    char *_str;

// methods
    const char *(*c_str)(struct cstring_s *);
    char (*at)(struct cstring_s *, size_t);
    size_t (*len)(struct cstring_s *);
    void (*set_str)(struct cstring_s *, const char *);
    struct cstring_s *(*copy)(struct cstring_s *);
    void (*clear)(struct cstring_s *);

    // todo
    // access first char of the string
    char *(*front)(struct cstring_s *);
    // access last char of the string
    char *(*back)(struct cstring_s *);
    // test if string is empty
    int (*empty)(struct cstring_s);
    // add a string to the end of the string
    int (*append)(struct cstring_s *, const char *);
    int (*append_s)(struct cstring_s *, const struct cstring_s);
    // add a char to the end of the string
    int (*push_back)(struct cstring_s *, const char);
    // delete last char
    int (*pop_back)(struct cstring_s *);
    // find content in string (returns first occurence)
    char *(*find)(struct cstring_s *, const char *);
    char *(*find_s)(struct cstring_s *, const struct cstring_s *);
    // find content in string (returns last occurence)
    char *(*rfind)(struct cstring_s *, const char *);
    char *(*rfind_s)(struct cstring_s *, const struct cstring_s *);
    // generate substring
    struct cstring_s *(*substr_s)(struct cstring_s *, size_t, size_t);
    char *(*substr)(struct cstring_s *, size_t, size_t);
} cstring;

// less chars typedef
typedef cstring cstr;
typedef cstring *Cstr;

cstr *Cstr_create(const char *str);
void Cstr_destroy(cstr *s);

const char *c_str(cstr *s);
char at(cstr *s, size_t i);
size_t my_strlen(const char *str);
size_t len(cstr *s);
void set_str(cstr *s, const char *str);
char *my_strcpy(char *dest, const char *str);
char *my_strdup(const char *str);
int my_strcmp(const char *a, const char *b);
int is_str_equal(cstr *s, cstr *b);
cstr *copy(cstr *c);

char *front(cstr *c);
char *back(cstr *c);
int empty(cstr c);
int append(cstr *c, const char *str);
int append_s(cstr *c, const cstr b);
int push_back(cstr *c, const char str);
int pop_back(cstr *c);
