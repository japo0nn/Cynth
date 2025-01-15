#include <hash_operations.h>

uint32_t hash_data(const void *data, size_t length){
    const uint8_t* bytes = (const uint8_t*)data;
    uint32_t hash = FNV_1a;

    #pragma unroll 4
    for (size_t i = 0; i < length; i++) {
        hash ^= bytes[i];
        hash *= FNV; // Константа FNV
    }

    return hash;
}
