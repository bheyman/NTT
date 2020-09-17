#include <cmath>		/* log2() */
#include <cstdint>		/* uint64_t */
#include <cstdlib> 		/* malloc() */

#include <iostream>

#include "../include/utils.h"	/* bit_reverse(), modExp(), modulo() */

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
uint64_t *naiveNTT(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r){

	uint64_t k = (p - 1)/n;
	uint64_t a = modExp(r,k,p);

	uint64_t *result;
	result = (uint64_t *) malloc(n*sizeof(uint64_t));

	uint64_t temp;
	for(uint64_t i = 0; i < n; i++){

		temp = 0;
		for(uint64_t j = 0; j < n; j++){
	
			temp = modulo(temp + modulo(vec[j]*modExp(a, i*j, p),p),p);
			/*temp = temp + modulo(vec[j]*modExp(a, i*j, p),p);*/
			/*temp = temp + vec[j]*modExp(a, i*j, p);*/

		}
		result[i] = modulo(temp,p);

	}

	return result;

}

/**
 * Perform an out-of-place decimation-in-time depth-first Cooley-Tukey NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint64_t *outOfPlaceNTT_DIT(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r){
	
	if(n == 1){
		
		return vec;

	}

	uint64_t k = (p - 1)/n;
	uint64_t a = modExp(r,k,p);

	uint64_t halfN = n >> 1;

	uint64_t *A0;
	A0 = (uint64_t *) malloc(halfN * sizeof(uint64_t));

	uint64_t *A1;
	A1 = (uint64_t *) malloc(halfN * sizeof(uint64_t));

	for(uint64_t i = 0; i < halfN; i++){

		A0[i] = vec[i*2];
		A1[i] = vec[i*2 + 1];

	}

	uint64_t *y0 = outOfPlaceNTT_DIT(A0, halfN, p, r);
	uint64_t *y1 = outOfPlaceNTT_DIT(A1, halfN, p, r);

	uint64_t *result;
	result = (uint64_t *) malloc(n*sizeof(uint64_t));

	uint64_t factor;
	for(uint64_t i = 0; i < halfN; i++){

		factor = modulo(modExp(a,i,p)*y1[i],p);

		result[i] 		= modulo(y0[i] + factor,p);	
		result[i + halfN] 	= modulo(y0[i] - factor,p);
	
	}

	return result;

}

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
uint64_t *outOfPlaceNTT_DIF(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r){

	if(n == 1){
	
		return vec;
	
	}

	uint64_t k = (p - 1)/n;
	uint64_t a = modExp(r,k,p);

	uint64_t halfN = n >> 1;

	uint64_t *A0;
	A0 = (uint64_t *) malloc(halfN * sizeof(uint64_t));

	uint64_t *A1;
	A1 = (uint64_t *) malloc(halfN * sizeof(uint64_t));

	for(uint64_t i = 0; i < halfN; i++){

		A0[i] = modulo(vec[i] + vec[i+halfN],p);
		A1[i] = modulo((vec[i] - vec[i+halfN])*modExp(a,i,p),p);

	}

	uint64_t *y0 = outOfPlaceNTT_DIF(A0,halfN,p,r);
	uint64_t *y1 = outOfPlaceNTT_DIF(A1,halfN,p,r);

	uint64_t *result;
	result = (uint64_t *) malloc(n*sizeof(uint64_t));

	for(uint64_t i = 0; i < halfN; i++){

		result[i] = y0[i];
		result[i + halfN] = y1[i];

	}

	return result;

}

/**
 * Perform an in-place decimation-in-time breadth-first Cooley-Tukey NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint64_t *inPlaceNTT_DIT(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r){

	uint64_t *result;
	result = (uint64_t *) malloc(n*sizeof(uint64_t));

	result = bit_reverse(vec,n);
	
	uint64_t m,k_,a,factor1,factor2;
	for(uint64_t i = 1; i <= log2(n); i++){

		m = pow(2,i);

		k_ = (p - 1)/m;
		a = modExp(r,k_,p);

		for(uint64_t j = 0; j < m/2; j++){

			for(uint64_t k = j; k < n; k+=m){

				factor1 = result[k];
				factor2 = modulo(modExp(a,j,p)*result[k + m/2],p);
				
				result[k] 	= modulo(factor1 + factor2, p);
				result[k+m/2] 	= modulo(factor1 - factor2, p);

			}
		}
	}

	return result;

}

/**
 * Perform an in-place decimation-in-frequency breadth-first Cooley-Tukey NTT on an input vector and return the result
 *
 * @param vec 	The input vector to be transformed
 * @param n	The size of the input vector
 * @param p	The prime to be used as the modulus of the transformation
 * @param r	The primitive root of the prime
 * @return 	The transformed vector
 */
uint64_t *inPlaceNTT_DIF(uint64_t *vec, uint64_t n, uint64_t p, uint64_t r){

	uint64_t *result;
	result = (uint64_t *) malloc(n*sizeof(uint64_t));

	for(uint64_t i = 0; i < n; i++){
		result[i] = vec[i];
	}

	uint64_t m,k_,a,factor1,factor2;
	for(uint64_t i = log2(n); i >= 1; i--){

		m = pow(2,i);

		k_ = (p - 1)/m;
		a = modExp(r,k_,p);

		for(uint64_t j = 0; j < n/m; j++){

			for(uint64_t k = 0; k < m/2; k++){

				factor1 = result[m*j + k];
				factor2 = result[m*j + k + m/2];

				result[m*j + k] 	= modulo(factor1 + factor2,p);
				result[m*j + k + m/2]	= modulo(factor1 - factor2,p);

				result[m*j + k + m/2] = modulo(result[m*j + k + m/2]*modExp(a,k,p),p);

			}
		}
	}

	return bit_reverse(result,n);

}
