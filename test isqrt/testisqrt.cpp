#include <cstdint>
#include "../Ponder This Nov 2024/isqrt.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <chrono>
int64_t test() {
	int64_t r, s;

	int64_t b_lim = 50000000;

	printf("isqrt tests started\n");
	auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::cout << timenow << std::endl; 	
	
	for (int64_t a = 10; a < 1000000000ll; a *= 10)
		for (int64_t b = 0; b < b_lim; b++) {
			r = a + b;
			if (!isqrt(r * r, s)) {
				printf("n=%lld, s=%lld\n", r * r, s);  return r * r;
			}
			if (isqrt(r * r - 1, s)) {
				printf("n=%lld, s=%lld\n", r * r-1, s);  return r * r-1;
			}
			if (isqrt(r * r + 1, s)) {
				printf("n=%lld, s=%lld\n", r * r+1, s);  return r * r+1;
			}
		}

	printf("isqrt tests completed successfully\n");
	 timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	 std::cout << timenow << std::endl;


	for (int64_t a = 10; a < 1000000000ll; a *= 10)
		for (int64_t b = 0; b < b_lim; b++) {
			r = a + b;
			if (!issquare2(r * r, s)) return r*r;
			if (issquare2(r * r - 1, s)) return r*r-1;
			if (issquare2(r * r + 1, s)) return r*r+1;
		}

	printf("issquare2 tests completed successfully\n");
	 timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	 std::cout << timenow << std::endl;

	return 0;
}


int main() {
	int64_t res = test();
	printf("%lld failed\n", res);

}