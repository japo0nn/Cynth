#ifndef HEADERS_H
#define HEADERS_H

#include <bool.h>
#include <safefree.h>

#define SUCCESS 0
#define FAILURE -1

#define string_equals(str1, str2) (strcmp((str1), (str2)) == 0)
#define get_len(arr) (sizeof(arr) / sizeof((arr)[0]))
#define to_string(value) #value

#endif
