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
 * @param m	The modulus to be used for the transformation
 * @param prim	The primitive root as applied to length and modulus
 * @return 	The transformed vector
 */
uint32_t *naiveNTT(uint32_t *vec, uint32_t n, uint32_t m, uint32_t prim){

	uint32_t *result;
	result = (uint32_t *) malloc(n*sizeof(uint32_t));

	uint32_t temp;
	for(uint32_t i = 0; i < n; i++){

		temp = 0;
		for(uint32_t j = 0; j < n; j++){

			temp = temp + modulo(vec[j]*modExp(prim, i*j, m),m);

		}
		result[i] = modulo(temp,m);

	}

	return result;

}

/**
 * Perform an out-of-place Cooley-Tukey NTT on an input vector and return the result
 * TODO NOT WORKING
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param m	The modulus to be used for the transformation
 * @param prim	The primitive root as applied to length and modulus
 * @return 	The transformed vector
 */
uint32_t *outOfPlaceNTT(uint32_t *vec, uint32_t n, uint32_t m, uint32_t prim){

	if(n == 1){
		
		return vec;

	}

	uint32_t halfN = n >> 1;

	uint32_t *A0;
	A0 = (uint32_t *) malloc(halfN * sizeof(uint32_t));

	uint32_t *A1;
	A1 = (uint32_t *) malloc(halfN * sizeof(uint32_t));

	for(uint32_t i = 0; i < halfN; i++){

		A0[i] = vec[i*2];
		A1[i] = vec[i*2 + 1];

	}

	uint32_t *y0 = outOfPlaceNTT(A0, halfN, m, prim);
	uint32_t *y1 = outOfPlaceNTT(A1, halfN, m, prim);

	uint32_t *result;
	result = (uint32_t *) calloc(n, sizeof(uint32_t));

	for(uint32_t i = 0; i < halfN; i++){

		result[i] 		= modulo((int32_t)y0[i] + (int32_t)modulo(modExp(prim,i,m)*y1[i],m),m);
		result[i + halfN] 	= modulo((int32_t)y0[i] - (int32_t)modulo(modExp(prim,i,m)*y1[i],m),m);

	}

	return result;

}

uint32_t *inPlaceNTT(uint32_t *vec, uint32_t n){

	uint32_t *result;
	result = (uint32_t *) calloc(n, sizeof(uint32_t));

	return result;

}

