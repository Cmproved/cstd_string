# cstd_string
This repo aims to bring C++ std::string to C, with automatic memory (re)allocation. Char[]s can be boring sometimes !

# The std_cstring library

This library aims to reproduce the behaviour of the C++ `std::string` class in C. Of course, C isn't OOP, so it's been a bit tricky to create a class in C.

## Installation

To compile a C program with this lib, you will need to run the Makefile first:
```bash
>> cd cstd_string/ && make
```
It should give you a `libcstdstring.a` binary.
```bash
# gcc {FILE}.c -L{LIB_DIRECTORY} -l{LIB_NAME}
>> gcc main.c -Lcstd_string -lcstdstring
```

> Note that the `-l` flag automatically removes `lib` and `.a` from the name. So `libcstdstring.a` becomes `cstdstring`.

## Basic usage

With a correct usage, the cstring library has no valgrind errors, nor memory leaks.

```c
#include "./cstd_string/include/cstr.h"

int main(int ac, char **av)
{
    Cstr my_str_a = Cstr_create("this is a string !"); // Cstr() is the constructor
    printf("%s\n", my_str_a->c_str(my_str_a));
    Cstr_destroy(my_str_a);
    return (0);
}
```

Output :
```bash
user@localhost~$ ./a.out
>> this is a string !
```

## The Cstr object

### Types

| type | equals to | description |
|----|----|----|
| `cstring` | `struct cstring_s` | the main structure |
| `cstr` | `struct cstring_s` | just a shorter name for the main structure |
| `Cstr` | `struct cstring_s *` | the main object pointer |

> It is your decision if you want to use `cstr *` or `Cstr`. Both are great, but some developers like to keep the `*` to clearly see when it's a pointer and when it's not. It's totally up to you.

### Properties

| value | type | description |
|----|----|----|
| `_str` | `char *` | store the actual string. It's supposed to be private so use the `c_str()` function instead |

### Methods
Here are the methods of the `cstr ` object :

|name | return type | parameters | description |
|----|----|----|----|
| `c_str()` | `char *` | `Cstr` | returns the pointer of `_str` - same as `std::string::c_str()` |
| `at()` | `const char` | `Cstr`, `size_t` | equivalent to `str[n]` |
| `len()` | `const int` | `Cstr` | equivalent to `strlen()` |
| `set_str()` | `void` | `Cstr`, `const char *` | set `_str` to the given value free cstr if error |
| `clear()` | `int` | `Cstr` | set `_str` to '\0' |
| `copy()` | `Cstr` | `const cstr *` | return a new cstr object |
| `front()` | `char *` | `Cstr` | returns a pointer to the first char |
| `back()` | `char *` | `Cstr` | returns a pointer to the last char |
| `empty()` | `int` | `Cstr` | checks if string is empty |
| `append()` | `int` | `Cstr`, `const char *` | adds a string to the end of the string |
| `append_s()` | `int` | `Cstr`, `Cstr` | same |
| `push_back()` | `int` | `Cstr`, `const char` | adds a char to the end of the string |
| `pop_back()` | `int` | `Cstr` | deletes the last char of the string |
| `find()` | `char *` | `Cstr`, `const char` | returns the first occurence of CHAR. NULL if not found |
| `find_s()` | `char *` | `Cstr`, `const Cstr` | same |
| `rfind()` | `char *` | `Cstr`, `const char` | return the last occurence of CHAR. NULL if not found |
| `rfind_s()` | `char *` | `Cstr`, `const Cstr` | same |
| `substr_s()` | `Cstr` | `Cstr`, `size_t FROM`, `size_t TO` | creates a new Cstr object from an existing one that start at index FROM and ends at index TO |
| `substr()` | `char *` | `Cstr`, `size_t`, `size_t` | same |
| `resize()` | `int` | `Cstr`, `size_t`, `char` | resizes the string to SIZE_T. Fills extra characters with CHAR |

### External fonctions

| name | return type | parameters | description |
|------|-------------|------------|-------------|
| `Cstr_create()` | `Cstr` | `const char *` | creates a new cstr object with the given string |
| `Cstr_destroy()` | `void` | `Cstr` | destroys a cstr object |
| `is_str_equal()` | `int` | `Cstr`, `cstr *` | compares two strings : returns 1 if equal, 0 otherwise |

## Contributing
Contributions are greatly apreciated. We are trying to replicate the `std::string` object as close as we can. Our goal is to make memory management easier in C for everyone, so if you feel like you share our vision, do not hesitate to make pull requests or open issues ! 
