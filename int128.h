#ifndef INT128_H
#define INT128_H


#include <stdint.h>

#ifdef __SIZEOF_INT128__
    typedef __uint128_t uint128_t;
    typedef __int128_t int128_t;
#elif defined __has_attribute && __has_attribute(mode)
    typedef unsigned int uint128_t __attribute__((mode (TI)));
    typedef int int128_t __attribute__((mode (TI)));
#else
    #pragma message ("Unsupported compiler: 128 bit types implemented using a struct")
    typedef struct
    {
        uint64_t low;
        uint64_t high;
    } uint128_t;
    typedef uint128_t int128_t;
    _Static_assert(sizeof(uint128_t) == 16, "Unsupported struct layout: uint128_t must be 16 bytes");
#endif

uint128_t add128(uint128_t x, uint128_t y);
uint128_t sub128(uint128_t x, uint128_t y);
uint128_t umul64(uint64_t x, uint64_t y);
int128_t smul64(int64_t x, int64_t y);

typedef struct
{
    uint64_t quotient;
    uint64_t reminder;
} udiv64_t;

uint64_t udiv12864(uint128_t dividend, uint64_t divisor);
udiv64_t udiv12864r(uint128_t dividend, uint64_t divisor);
uint64_t umod12864(uint128_t dividend, uint64_t divisor);


#endif
