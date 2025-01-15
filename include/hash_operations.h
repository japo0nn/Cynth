#ifndef HASH_OPERATIONS_H
#define HASH_OPERATIONS_H

#include <stdlib.h>
#include <stdint.h>

#define ROTR(x, n, w) ((x >> n) | x << (w - n))
#define ROTL(x, n, w) ((x << n) | x >> (w - n))
#define SHR(x, n) (x >> n)
#define FNV_1a 2166136261u 
#define FNV 16777619u

uint32_t hash_data(const void *data, size_t length);

#endif
