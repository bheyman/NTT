#include <cmath>		/* log2(), pow() */
#include <cstdint>		/* int32_t, uint32_t */
#include <cstdlib> 		/* calloc() */

#include "../include/utils.h"	/* modExp() */

#include "../include/ntt.h" 	//INCLUDE HEADER FILE

/**
 * Perform a basic NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint32_t *naiveNTT(uint32_t *vec, uint32_t n, uint32_t p, uint32_t r){

	uint32_t k = (p - 1)/n;
	uint32_t a = modExp(r,k,p);

	uint32_t *result;
	result = (uint32_t *) malloc(n*sizeof(uint32_t));

	uint32_t temp;
	for(uint32_t i = 0; i < n; i++){

		temp = 0;
		for(uint32_t j = 0; j < n; j++){

			temp = temp + modulo(vec[j]*modExp(a, i*j, p),p);
			/*temp = temp + vec[j]*modExp(a, i*j, p); ???*/

		}
		result[i] = modulo(temp,p);

	}

	return result;

}

/**
 * Perform an out-of-place Cooley-Tukey NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint32_t *outOfPlaceNTT(uint32_t *vec, uint32_t n, uint32_t p, uint32_t r){
	
	if(n == 1){
		
		return vec;

	}

	uint32_t k = (p - 1)/n;
	uint32_t a = modExp(r,k,p);

	uint32_t halfN = n >> 1;

	uint32_t *A0;
	A0 = (uint32_t *) malloc(halfN * sizeof(uint32_t));

	uint32_t *A1;
	A1 = (uint32_t *) malloc(halfN * sizeof(uint32_t));

	for(uint32_t i = 0; i < halfN; i++){

		A0[i] = vec[i*2];
		A1[i] = vec[i*2 + 1];

	}

	uint32_t *y0 = outOfPlaceNTT(A0, halfN, p, r);
	uint32_t *y1 = outOfPlaceNTT(A1, halfN, p, r);

	uint32_t *result;
	result = (uint32_t *) malloc(n*sizeof(uint32_t));

	for(uint32_t i = 0; i < halfN; i++){

		result[i] 		= modulo(y0[i] + modulo(modExp(a,i,p)*y1[i],p),p);	
		result[i + halfN] 	= modulo(y0[i] - modulo(modExp(a,i,p)*y1[i],p),p);
	
	}

	return result;

}

uint32_t *inPlaceNTT(uint32_t *vec, uint32_t n){

	uint32_t *result;
	result = (uint32_t *) calloc(n, sizeof(uint32_t));

	return result;

}

