#include <cstdint>		/* uint32_t */

#include "../include/ntt.h"	/* naiveNTT(), outOfPlaceNTT() */
#include "../include/utils.h"	/* printVec() */

using namespace std;

int main(int argc, char *argv[]){

	uint32_t n = 16;
	uint32_t m = 17;
	uint32_t p = 3;

	uint32_t *vec = randVec(n,10);

	printVec(vec, n);

	uint32_t *out = naiveNTT(vec, n, m, p);
	uint32_t *out2 = outOfPlaceNTT(vec, n, m, p);

	printVec(out,n);
	printVec(out2,n);

	return 0;

}
