#include <cstdint> 		/* int32_t */
#include <cstdlib>		/* srand(), rand() */
#include <ctime>		/* time() */
#include <iostream> 		/* std::cout, std::endl */

#include "../include/utils.h" 	//INCLUDE HEADER FILE

/**
 * Perform the operation 'base (mod m)'
 *
 * @param base	The base of the expression
 * @param m	The modulus of the expression
 * @return 	The result of the expression
 */
int32_t modulo(int32_t base, int32_t m){

	int32_t result = base % m;
	return (result >= 0) ? result : result + m;

}

/**
 * Perform the operation 'base^exp (mod m)' using the memory-efficient method
 *
 * @param base	The base of the expression
 * @param exp	The exponent of the expression
 * @param m	The modulus of the expression
 * @return 	The result of the expression
 */
int32_t modExp(int32_t base, int32_t exp, int32_t m){

	int32_t result = 1;
	
	while(exp > 0){

		if(exp % 2){

			result = modulo(result*base, m);

		}

		exp = exp >> 1;
		base = modulo(base*base, m);
	}

	return result;

}

/**
 * Print an array of arbitrary length in a readable format
 *
 * @param vec	The array to be displayed
 * @param n	The length of the array
 */
void printVec(int32_t *vec, int32_t n){

	std::cout << "[";
	for(int32_t i = 0; i < n; i++){

		std::cout << vec[i];
		if(i != (n-1)){
			std::cout << " ";
		}

	}
	std::cout << "]" << std::endl;

}

/**
 * Generate an array of arbitrary length containing random positive integers 
 *
 * @param n	The length of the array
 * @param max	The maximum value for an array element [Default: RAND_MAX]
 */
int32_t *randVec(int32_t n, int32_t max){

	int32_t *vec;
	vec = (int32_t *)malloc(n*sizeof(int32_t));

	srand(time(0));
	for(int32_t i = 0; i < n; i++){

		vec[i] = rand()%(max + 1);

	}

	return vec;

}
