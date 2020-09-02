#ifndef NTT_H
#define NTT_H

#include <cstdint> 	/* uint32_t */

/**
 * Perform a basic NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint32_t *naiveNTT(uint32_t *vec, uint32_t n, uint32_t p, uint32_t r);

/**
 * Perform an out-of-place Cooley-Tukey NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint32_t *outOfPlaceNTT(uint32_t *vec, uint32_t n, uint32_t p, uint32_t r);

uint32_t *inPlaceNTT(uint32_t *vec, uint32_t n);

#endif
