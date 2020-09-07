#include <cstdint>		/* uint64_t */
#include <ctime>		/* time() */

#include <unistd.h>
#include <iostream>

#include "../include/ntt.h"	/* naiveNTT(), outOfPlaceNTT() */
#include "../include/utils.h"	/* printVec() */

using namespace std;

int main(int argc, char *argv[]){

	uint64_t time_track;

	uint64_t n = 8;
	uint64_t p = 17;
	uint64_t r = 3;	
	
	time_track = time(0);
	uint64_t *vec = randVec(n,10);
	time_track = time(0) - time_track;
	cout << "vec DONE in " << time_track << " seconds" << endl;

	printVec(vec,n);
	
	time_track = time(0);
	uint64_t *out1 = naiveNTT(vec, n, p, r);	
	time_track = time(0) - time_track;
	cout << "out1 DONE in " << time_track << " seconds" << endl;
	printVec(out1,n);

	time_track = time(0);
	uint64_t *out2 = outOfPlaceNTT(vec, n, p, r);
	time_track = time(0) - time_track;
	cout << "out2 DONE in " << time_track << " seconds" << endl;
	printVec(out2,n);

	time_track = time(0);
	uint64_t *out3 = inPlaceNTT(vec, n, p, r);
	time_track = time(0) - time_track;
	cout << "out3 DONE in " << time_track << " seconds" << endl;
	printVec(out3,n);

	cout << (compVec(out1, out2, n) && compVec(out2, out3, n) ? "PASS" : "FAIL") << endl;
	cout << endl;
	
	return 0;

}
