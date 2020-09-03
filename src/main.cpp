#include <cstdint>		/* uint64_t */
#include <ctime>		/* time() */

#include <unistd.h>
#include <iostream>

#include "../include/ntt.h"	/* naiveNTT(), outOfPlaceNTT() */
#include "../include/utils.h"	/* printVec() */

using namespace std;

int main(int argc, char *argv[]){

	uint64_t time_track;

	uint64_t n = 32768;
	uint64_t p = 65537;
	uint64_t r = 3;

	time_track = time(0);
	uint64_t *vec = randVec(n,10);
	time_track = time(0) - time_track;
	cout << "vec DONE in " << time_track << " seconds" << endl;

	time_track = time(0);
	uint64_t *out1 = naiveNTT(vec, n, p, r);	
	time_track = time(0) - time_track;
	cout << "out1 DONE in " << time_track << " seconds" << endl;

	time_track = time(0);
	uint64_t *out2 = outOfPlaceNTT(vec, n, p, r);
	time_track = time(0) - time_track;
	cout << "out2 DONE in " << time_track << " seconds" << endl;

	cout << (compVec(out1, out2, n, true) ? "PASS" : "FAIL") << endl;
	cout << endl;

	return 0;

}
