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
 * Perform an out-of-place decimation-in-time Cooley-Tukey NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint64_t *outOfPlaceNTT_DIT(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r);

/**
 * Perform an out-of-place decimation-in-frequency Cooley-Tukey NTT on an input vector and return the result
 * TODO: The output of this method is currently bit-reversed. Hard to fix because it's implemented recursively
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint64_t *outOfPlaceNTT_DIF(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r);

/**
 * Perform an in-place decimation-in-time Cooley-Tukey NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @param rev	Whether to perform bit reversal on the input vector
 * @return 	The transformed vector
 */
uint64_t *inPlaceNTT_DIT(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r, bool rev=true);

/**
 * Perform an in-place decimation-in-frequency Cooley-Tukey NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @param rev	Whether to perform bit reversal on the output vector
 * @return 	The transformed vector
 */
uint64_t *inPlaceNTT_DIF(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r, bool rev=true);

/**
 * Perform an in-place decimation-in-time Cooley-Tukey NTT on an input vector using precomputed 
 * twiddle factors and return the result
 *
 * @param vec 		The input vector to be transformed
 * @param n		The size of the input vector
 * @param p		The prime to be used as the modulus of the transformation
 * @param r		The primitive root of the prime
 * @param twiddle	The precomputed list of necessary twiddle factors
 * @param rev		Whether to perform bit reversal on the input vector
 * @return 		The transformed vector
 */
uint64_t *inPlaceNTT_DIT_precomp(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r, uint64_t *twiddle, bool rev=true);

#endif
