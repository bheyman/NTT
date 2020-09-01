#ifndef UTILS_H
#define UTILS_H

#include <cstdint> 	/* int32_t */
#include <cstdlib>	/* RAND_MAX */

/**
 * Perform the operation 'base (mod m)'
 *
 * @param base	The base of the expression
 * @param m	The modulus of the expression
 * @return 	The result of the expression
 */
int32_t modulo(int32_t base, int32_t m);

/**
 * Perform the operation 'base^exp (mod m)' using the memory-efficient method
 *
 * @param base	The base of the expression
 * @param exp	The exponent of the expression
 * @param m	The modulus of the expression
 * @return 	The result of the expression
 */
int32_t modExp(int32_t base, int32_t exp, int32_t m);


/**
 * Print an array of arbitrary length in a readable format
 *
 * @param vec	The array to be displayed
 * @param n	The length of the array
 */
void printVec(int32_t *vec, int32_t n);

/**
 * Generate an array of arbitrary length containing random positive integers 
 *
 * @param n	The length of the array
 * @param max	The maximum value for an array element [Default: RAND_MAX]
 */
int32_t *randVec(int32_t n, int32_t max=RAND_MAX);

#endif
