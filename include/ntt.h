#ifndef NTT_H
#define NTT_H

#include <cstdint> 	/* uint32_t */

/**
 * Perform a basic NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param m	The modulus to be used for the transformation
 * @param prim	The primitive root as applied to length and modulus
 * @return 	The transformed vector
 */
uint32_t *naiveNTT(uint32_t *vec, uint32_t n, uint32_t m, uint32_t prim);

uint32_t *outOfPlaceNTT(uint32_t *vec, uint32_t n, uint32_t m, uint32_t prim);

uint32_t *inPlaceNTT(uint32_t *vec, uint32_t n);

#endif
