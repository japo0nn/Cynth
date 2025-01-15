#ifndef HASH_OPERATIONS_H
#define HASH_OPERATIONS_H

#define ROTR(x, n, w) ((x >> n) | x << (w - n))
#define ROTL(x, n, w) ((x << n) | x >> (w - n))
#define SHR(x, n) (x >> n)

#endif
