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
	

	return 0;

}
