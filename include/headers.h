#ifndef HEADERS_H
#define HEADERS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <safefree.h>
#include <bool.h>
#include <stdint.h>

#define SUCCESS 0
#define FAILURE -1

#define string_equals(str1, str2) (strcmp((str1), (str2)) == 0)
#define get_len(arr) (sizeof(arr) / sizeof((arr)[0]))

#define SET_DEFAULT_VALUE(value, datatype)   \
    do {                                     \
        if (sizeof(datatype) == sizeof(void *)) {  \
            (value) = NULL;                  \
        } else {                             \
            (value) = 0;                     \
        }                                    \
    } while (0)

#endif
