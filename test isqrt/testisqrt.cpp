#include <cstdint>
#include "../Ponder This Nov 2024/isqrt.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "timer.h"

int64_t test() {
	int64_t r, s;

	Timer tim;

	int64_t b_lim = 50000000;

	printf("issquare tests started\n");
	tim.start();
	
	for (int64_t a = 10; a < 1000000000ll; a *= 10)
		for (int64_t b = 0; b < b_lim; b++) {
			r = a + b;
			if (!issquare(r * r, s)) {
				printf("n=%lld, s=%lld\n", r * r, s);  return r * r;
			}
			if (issquare(r * r - 1, s)) {
				printf("n=%lld, s=%lld\n", r * r-1, s);  return r * r-1;
			}
			if (issquare(r * r + 1, s)) {
				printf("n=%lld, s=%lld\n", r * r+1, s);  return r * r+1;
			}
		}
	tim.end();
	printf("issquare tests completed successfully in %lld ms\n", tim.ms() );

	tim.start();
	for (int64_t a = 10; a < 1000000000ll; a *= 10)
		for (int64_t b = 0; b < b_lim; b++) {
			r = a + b;
			if (!issquare2(r * r, s)) return r*r;
			if (issquare2(r * r - 1, s)) return r*r-1;
			if (issquare2(r * r + 1, s)) return r*r+1;
		}
	tim.end();
	printf("issquare2 tests completed successfully in %lld ms\n", tim.ms() );

	return 0;
}


int main() {
	int64_t res = test();
	printf("%lld failed\n", res);

}