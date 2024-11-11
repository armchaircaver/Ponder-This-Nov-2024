#include <cstdint>
#include "../Ponder This Nov 2024/isqrt.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "timer.h"

int64_t test( bool (*func)( int64_t a, int64_t & res), std::string desc ) {
	int64_t s;

	Timer tim;

	int64_t range = 1LL<<26;

	std::cout << desc << " tests started\n";
	tim.start();
	
	for (int64_t a : {3LL, 1LL << 27, 1LL << 28, 1LL << 29, 1LL << 30, 1LL << 31 })
		for (int64_t r = a; r < a + range; r++) {
			if (!(*func)(r * r, s)) {
				printf("failed A n=%lld, s=%lld\n", r * r, s);  return r * r;
			}
			if ((*func)(r * r - 1, s)) {
				printf("failed B n=%lld, s=%lld\n", r * r-1, s);  return r * r-1;
			}
			if ((*func)(r * r + 1, s)) {
				printf("failed C n=%lld, s=%lld\n", r * r+1, s);  return r * r+1;
			}
		}
	tim.end();
	std::cout << desc << " tests completed successfully in "<< tim.ms() <<" ms\n";

	
	return 0;
}


int main() {
	int64_t result;
	result = test(issquare, "issquare");
	result = test(issquare2, "issquare2");
	result = test(issquare3, "issquare3");

}