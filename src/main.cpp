#include <cmath>		/* pow() */
#include <cstdint>		/* uint64_t */
#include <ctime>		/* time() */

#include <unistd.h>
#include <iostream>

#include "../include/ntt.h"	/* naiveNTT(), outOfPlaceNTT() */
#include "../include/utils.h"	/* printVec() */

using namespace std;

int main(int argc, char *argv[]){

	uint64_t time_track;

	uint64_t k = stoi(argv[1]);

	uint64_t n = pow(2,k);
	uint64_t p = 4046849;
	uint64_t r = 3;	
	
	uint64_t *vec = randVec(n,65535);

	uint64_t sel = stoi(argv[2]);

	if(sel == 0){
	
		uint64_t *out1 = naiveNTT(vec, n, p, r);	
	
	}else if(sel == 1){

		uint64_t *out2 = outOfPlaceNTT(vec, n, p, r);

	}else if(sel == 2){

		uint64_t *out3 = inPlaceNTT(vec, n, p, r);
	
	}

	return 0;

}
