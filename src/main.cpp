#include <cstdint>		/* uint32_t */

#include <unistd.h>
#include <iostream>

#include "../include/ntt.h"	/* naiveNTT(), outOfPlaceNTT() */
#include "../include/utils.h"	/* printVec() */

using namespace std;

int main(int argc, char *argv[]){

	uint32_t n = 16384;
	uint32_t p = 65537;
	uint32_t r = 3;

	uint32_t *vec = randVec(n,10);
	//cout << "vec DONE" << endl;
	printVec(vec, n);

	//uint32_t *out1 = naiveNTT(vec, n, p, r);
	//cout << "out1 DONE" << endl;
	uint32_t *out2 = outOfPlaceNTT(vec, n, p, r);
	//cout << "out2 DONE" << endl;
	//printVec(out1,n);
	printVec(out2,n);

	//cout << (compVec(out1, out2, n, true) ? "PASS" : "FAIL") << endl;
	cout << endl;

	return 0;

}
