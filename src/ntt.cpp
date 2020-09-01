#include <cmath>		/* log2(), pow() */
#include <cstdint>		/* int32_t */
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
int32_t *naiveNTT(int32_t *vec, int32_t n, int32_t m, int32_t prim){

	int32_t *result;
	result = (int32_t *) malloc(n*sizeof(int32_t));

	int32_t temp;
	for(int32_t i = 0; i < n; i++){

		temp = 0;
		for(int32_t j = 0; j < n; j++){

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
int32_t *outOfPlaceNTT(int32_t *vec, int32_t n, int32_t m, int32_t prim){

	if(n == 1){
		
		return vec;

	}

	int32_t halfN = n >> 1;

	int32_t *A0;
	A0 = (int32_t *) malloc(halfN * sizeof(int32_t));

	int32_t *A1;
	A1 = (int32_t *) malloc(halfN * sizeof(int32_t));

	for(int32_t i = 0; i < halfN; i++){

		A0[i] = vec[i*2];
		A1[i] = vec[i*2 + 1];

	}

	int32_t *y0 = outOfPlaceNTT(A0, halfN, m, prim);
	int32_t *y1 = outOfPlaceNTT(A1, halfN, m, prim);

	int32_t *result;
	result = (int32_t *) calloc(n, sizeof(int32_t));

	for(int32_t i = 0; i < halfN; i++){

		result[i] 		= modulo(y0[i] + modulo(modExp(prim,i,m)*y1[i],m),m);
		result[i + halfN] 	= modulo(y0[i] - modulo(modExp(prim,i,m)*y1[i],m),m);

	}

	return result;

}

int32_t *inPlaceNTT(int32_t *vec, int32_t n){

	int32_t *result;
	result = (int32_t *) calloc(n, sizeof(int32_t));

	return result;

}

