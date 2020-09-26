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
	printVec(vec,n);

	uint64_t *out1 = naiveNTT(vec,n,p,r);
	printVec(out1,n);

	uint64_t *out2 = fourStepNTT(vec,n,p,r,2);
	printVec(out2,n);

	return 0;

}
