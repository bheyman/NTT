#include <cstdint>		/* uint32_t */

#include <iostream>

#include "../include/ntt.h"	/* naiveNTT(), outOfPlaceNTT() */
#include "../include/utils.h"	/* printVec() */

using namespace std;

int main(int argc, char *argv[]){

	uint32_t n = 8;
	uint32_t p = 17;
	uint32_t r = 3;

	uint32_t *vec = randVec(n,2048);

	printVec(vec, n);

	uint32_t *out = naiveNTT(vec, n, p, r);
	uint32_t *out2 = outOfPlaceNTT(vec, n, p, r);

	printVec(out,n);
	printVec(out2,n);

	return 0;

}
