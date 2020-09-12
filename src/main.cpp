#include <cmath>		/* pow() */
#include <cstdint>		/* uint64_t */
#include <ctime>		/* time() */

#include <unistd.h>
#include <iostream>

#include "../include/ntt.h"	/* naiveNTT(), outOfPlaceNTT_DIT() */
#include "../include/utils.h"	/* printVec() */

using namespace std;

int main(int argc, char *argv[]){

	uint64_t k = 2;

	uint64_t n = pow(2,k);
	uint64_t p = 4046849;
	uint64_t r = 3;	
	
	uint64_t *vec = randVec(n,10);

	uint64_t *out1 = naiveNTT(vec, n, p, r);	

	printVec(out1,n);

	uint64_t *out2 = outOfPlaceNTT_DIT(vec, n, p, r);

	printVec(out2,n);

	cout << compVec(out1,out2,n) << endl;

	return 0;

}
