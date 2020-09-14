#include <cmath>		/* pow() */
#include <cstdint>		/* uint64_t */
#include <ctime>		/* time() */

#include <unistd.h>
#include <iostream>

#include "../include/ntt.h"	/* naiveNTT(), outOfPlaceNTT_DIT() */
#include "../include/utils.h"	/* printVec() */

using namespace std;

int main(int argc, char *argv[]){

	uint64_t k = 3;

	uint64_t n = pow(2,k);
	uint64_t p = 17;
	uint64_t r = 3;	
	
	//uint64_t *vec = randVec(n,10);
	uint64_t vec[8] = {0,1,2,3,4,5,6,7};

	uint64_t *out1;
	out1 = (uint64_t *)malloc(n*sizeof(uint64_t));	
	uint64_t *out2;
	out2 = (uint64_t *)malloc(n*sizeof(uint64_t));
	uint64_t *out3;
	out3 = (uint64_t *)malloc(n*sizeof(uint64_t));
	uint64_t *out4;
	out4 = (uint64_t *)malloc(n*sizeof(uint64_t));
	uint64_t *out5;
	out5 = (uint64_t *)malloc(n*sizeof(uint64_t));

	out1 = naiveNTT(vec, n, p, r);		
	out2 = outOfPlaceNTT_DIT(vec,n,p,r);
	out3 = outOfPlaceNTT_DIF(vec,n,p,r);
	out4 = inPlaceNTT_DIT(vec,n,p,r);
	out5 = inPlaceNTT_DIF(vec,n,p,r);

//	printVec(vec,n);
	printVec(out1, n);
	printVec(out2, n);
	printVec(bit_reverse(out3,n), n);
	printVec(bit_reverse(out4,n), n);
	printVec(bit_reverse(out5,n), n);

	return 0;

}
