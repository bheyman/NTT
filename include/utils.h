#ifndef UTILS_H
#define UTILS_H

#include <cstdint> 	/* uint32_t */
#include <cstdlib>	/* RAND_MAX */

/**
 * Perform the operation 'base (mod m)'
 *
 * @param base	The base of the expression
 * @param m	The modulus of the expression
 * @return 	The result of the expression
 */
uint32_t modulo(int32_t base, int32_t m);

/**
 * Perform the operation 'base^exp (mod m)' using the memory-efficient method
 *
 * @param base	The base of the expression
 * @param exp	The exponent of the expression
 * @param m	The modulus of the expression
 * @return 	The result of the expression
 */
uint32_t modExp(uint32_t base, uint32_t exp, uint32_t m);


/**
 * Print an array of arbitrary length in a readable format
 *
 * @param vec	The array to be displayed
 * @param n	The length of the array
 */
void printVec(uint32_t *vec, uint32_t n);

/**
 * Generate an array of arbitrary length containing random positive integers 
 *
 * @param n	The length of the array
 * @param max	The maximum value for an array element [Default: RAND_MAX]
 */
uint32_t *randVec(uint32_t n, uint32_t max=RAND_MAX);

#endif
