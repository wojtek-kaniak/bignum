#include <stdio.h>
#include <inttypes.h>
#include "int128.h"

// __uint128_t add128(__uint128_t x, __uint128_t y);
// __uint128_t sub128(__uint128_t x, __uint128_t y);
// __uint128_t umul64(uint64_t x, uint64_t y);
// __int128_t smul64(int64_t x, int64_t y);
void print128(uint128_t x);

int main()
{
    // print128(umul64(4611686018427387904, 4611686018427387904));
    // print128(4611686018427387904);
    // print128(smul64(2, 4611686018427387904));
    // print128(add128(4611686018427387904, 4611686018427387904));
    // print128(add128(4611686018427387904, 4611686018427387904));
    print128(udiv12864r(4611686018427387905, 2).reminder);
	print128(umod12864(4611686018427387905, 2));
    // __uint128_t tmp = 4611686018427387904;
    // print128(sub128(tmp * 10, 2));
}

void print128(uint128_t x)
{
    printf("0x%" PRIX64, (uint64_t)(x >> 64)); // High
    printf("%" PRIX64 "\n", (uint64_t)x); // Low
}
