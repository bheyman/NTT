#include <cstdint>		/* int32_t */

#include "../include/ntt.h"	/* naiveNTT(), outOfPlaceNTT() */
#include "../include/utils.h"	/* printVec() */

using namespace std;

int main(int argc, char *argv[]){

	int32_t n = 16;
	int32_t m = 17;
	int32_t p = 3;

	int32_t *vec = randVec(n,10);

	printVec(vec, n);

	int32_t *out = naiveNTT(vec, n, m, p);
	int32_t *out2 = outOfPlaceNTT(vec, n, m, p);

	printVec(out,n);
	printVec(out2,n);

	return 0;

}
