#include <cstdint>
#include <cmath>


bool isqrt(int64_t n, int64_t & s){
	// calculates integer square root of n and returns result in s
	// returns true if n is a perfect square
	double d = std::sqrtl((double)n);
	s = (int64_t)d;
	while (s * s > n) s--;
	while (s * s <= n) s++;
	s--;
	if( s * s == n) return true;
    return false;
}


bool issquare2(int64_t n, int64_t& s) {
    //thanks fenderbender @ mersenneforum.org

    // start with mod 128 rejection. 82 % rejection rate
    // VERY fast, can read bits directly
    int64_t m = n & 127; // n mod 128
    if ((m * 0x8bc40d7d) & (m * 0xa1e2f5d1) & 0x14020a)
        return false;

    //Other modulii share one BigInt modulus.
    int64_t largeMod = n % (63ll * 25 * 11 * 17 * 19 * 23 * 31); // SLOW, bigint modulus

    // residues mod 63. 75 % rejection
    m = largeMod % 63; // fast, all 32 - bit math
    if ((m * 0x3d491df7) & (m * 0xc824a9f9) & 0x10f14008)
        return false;

    // residues mod 25. 56 % rejection
    m = largeMod % 25;
    if ((m * 0x1929fc1b) & (m * 0x4c9ea3b2) & 0x51001005)
        return false;

    // residues mod 31. 48.4 % rejection
    //  Bloom filter has a little different form to keep it perfect
    m = 0xd10d829a * (largeMod % 31);
    if (m & (m + 0x672a5354) & 0x21025115)
        return false;

    // residues mod 23. 47.8 % rejection
    m = largeMod % 23;
    if ((m * 0x7bd28629) & (m * 0xe7180889) & 0xf8300)
        return false;

    // residues mod 19. 47.3 % rejection
    m = largeMod % 19;
    if ((m * 0x1b8bead3) & (m * 0x4d75a124) & 0x4280082b)
        return false;

    // residues mod 17. 47.1 % rejection
    m = largeMod % 17;
    if ((m * 0x6736f323) & (m * 0x9b1d499) & 0xc0000300)
        return false;

    // residues mod 11. 45.5 % rejection
    m = largeMod % 11;
    if ((m * 0xabf1a3a7) & (m * 0x2612bf93) & 0x45854000)
        return false;


    return isqrt(n, s);
}