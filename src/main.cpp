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
	
	uint64_t *vec = randVec(n,10);
	printVec(vec,n);

	uint64_t *out1 = naiveNTT(vec,n,p,r);
	printVec(out1,n);

	uint64_t *out2 = outOfPlaceNTT_DIT(vec,n,p,r);
	printVec(out2,n);

	uint64_t *out3 = outOfPlaceNTT_DIF(vec,n,p,r);
	printVec(bit_reverse(out3,n),n);

	uint64_t *out4 = inPlaceNTT_DIT(vec,n,p,r);
	printVec(out4,n);

	uint64_t *out5 = inPlaceNTT_DIF(vec,n,p,r);
	printVec(out5,n);

	uint64_t *out6 = inPlaceNTT_DIT(out5,n,p,6);

	for(uint64_t i = 0; i < n; i++){
		out6[i] = modulo(out6[i]*15,p);
	}
	printVec(out6,n);

	return 0;

}
