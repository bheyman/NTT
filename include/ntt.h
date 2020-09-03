#ifndef NTT_H
#define NTT_H

#include <cstdint> 	/* uint64_t */

/**
 * Perform a basic NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint64_t *naiveNTT(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r);

/**
 * Perform an out-of-place Cooley-Tukey NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint64_t *outOfPlaceNTT(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r);

uint64_t *inPlaceNTT(uint64_t *vec, uint64_t n);

#endif
