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
	cout << &vec << endl;

	uint64_t *out1 = naiveNTT(vec,n,p,r);
	cout << &out1 << endl;
	
	uint64_t *out2 = inPlaceNTT_DIF(vec,n,p,r);
	cout << &out2 << endl;

	printVec(out1,n);
	printVec(out2,n);


	return 0;

}
