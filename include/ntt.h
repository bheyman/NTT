#ifndef NTT_H
#define NTT_H

#include <cstdint> 	/* int32_t */

/**
 * Perform a basic NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param m	The modulus to be used for the transformation
 * @param prim	The primitive root as applied to length and modulus
 * @return 	The transformed vector
 */
int32_t *naiveNTT(int32_t *vec, int32_t n, int32_t m, int32_t prim);

int32_t *outOfPlaceNTT(int32_t *vec, int32_t n, int32_t m, int32_t prim);

int32_t *inPlaceNTT(int32_t *vec, int32_t n);

#endif
