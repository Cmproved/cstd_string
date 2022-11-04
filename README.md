# cstd_string
This repo aims to bring C++ std::string to C, with automatic memory (re)allocation. Char[]s can be boring sometimes !
# The std_cstring library

This library aims to reproduce the behaviour of the C++ std::string class in C. Of course, C isn't OOP, so it's been a bit tricky to create a class in C.

## Basic usage

With a correct usage, the cstring library has no valgrind errors, nor memory leaks.

```c
#include "cstring.h"

int main(int ac, char **av)
{
    cstr *my_str_a = Cstr("this is a string !"); // Cstr() is the constructor
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

## The cstr object

### Values

| value | type | description |
|----|----|----|
| `_str` | `char *` | store the actual string. Please use `c_str( )` function instead |

### Methods
Here are the methods of the `cstr ` object :

|name | return type | parameters | description |
|----|----|----|----|
| `c_str( )` | `char *` | `cstr *` | returns the pointer of `_str` - same as `std::string::c_str()` |
| `at( )` | `const char` | `cstr *`, `size_t` | equivalent to `str[n]` |
| `len( )` | `const int` | `cstr *` | equivalent to `strlen()` |
| `set_str( )` | `void` | `cstr *`, `const char *` | set `_str` to the given value free cstr if error |
| `clear( )` | `void` | `cstr *` | set `_str` to '\0' |
| `copy( )` | `cstr *` | `const cstr *` | return a new cstr object |

### External fonctions

| name | return type | parameters | description |
|------|-------------|------------|-------------|
| `Cstr( )` | `cstr *` | `const char *` | creates a new cstr object with the given string |
| `Cstr_destroy( )` | `void` | `cstr *` | destroys a cstr object |
| `is_str_equal( )` | `int` | `cstr *`, `cstr *` | compares two strings : returns 1 if equal, 0 otherwise |

## Contributing
Contributions are greatly apreciated. Do not hesitate to pull request, or open issues !
Thanks !
