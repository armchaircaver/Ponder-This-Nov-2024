#include <cstdint>
#include <cmath>
#include <vector>
#include "isqrt.h"

int64_t square(int64_t n) { return n * n; }

int64_t T(int64_t u, int64_t v, int64_t w, int64_t U, int64_t V, int64_t W) {
    int64_t u2 = u * u;
    int64_t    v2 = v * v;
    int64_t   w2 = w * w;
    int64_t   U2 = U * U;
    int64_t   V2 = V * V;
    int64_t  W2 = W * W;

    return 4 * (u2 * v2 * w2) - u2 * square(v2 + w2 - U2) - v2 * square(w2 + u2 - V2)
        - w2 * square(u2 + v2 - W2) + (v2 + w2 - U2) * (w2 + u2 - V2) * (u2 + v2 - W2);

}

double Volume(int64_t u, int64_t v, int64_t w, int64_t  U, int64_t V, int64_t W) {
    return sqrt(T(u, v, w, U, V, W)) / 12.0;
}


std::vector<int64_t> solve_w_results;
void solve_w(int64_t u, int64_t v, int64_t  U, int64_t  V, int64_t  W, int64_t  t) {
    solve_w_results.clear();
    u *= u;
    v *= v;
    U *= U;
    V *= V;
    W *= W;


    int64_t   d = 4 * W * (-t - square(u) * U
        + u * (-square(U) + U * (v + V + W) + v * (V - W))
        - V * (U * (W - v) + v * (v + V - W)))
        + square(u * (U - V + W) + U * (W - v) + v * V + v * W + V * W - square(W));

    if (d < 0)
        return;

    int64_t isqrt_d;
    if (!isqrt(d, isqrt_d))
        return;


    int64_t w = -isqrt_d + u * U - u * V + u * W - U * v + U * W + v * V + v * W + V * W
        - square(W);
    if (w > 0 and w % (2 * W) == 0) {
        w /= (2 * W);
        int64_t isqrt_w;
        if (isqrt(w, isqrt_w))
            solve_w_results.push_back(isqrt_w);
    }
    w = isqrt_d + u * U - u * V + u * W - U * v + U * W + v * V + v * W + V * W - square(W);
    if (w > 0 and w % (2 * W) == 0) {
        w /= (2 * W);
        int64_t isqrt_w;
        if (isqrt(w, isqrt_w))
            solve_w_results.push_back(isqrt_w);

    }
}

void search(int64_t t) {
    // edge lengths
    int64_t u, v, w;
    u = 1000; v = 1000; w= 1000;
    int64_t U, V, W;
    U = 3; V = 4; W= 5;

    double v1 = Volume(u, v, w, U, V, W);
    printf("test vol A %f\n", v1);

    v1 = Volume(2, 2, 2, 2, 2, 2);
    printf("test vol B %f\n", v1);
    printf("expected value %f\n", sqrt(128. / 144.));
    int64_t t1 = T(2, 2, 2, 2, 2, 2);
    printf("test T 2,2,2,2,2,2 %lld\n", t1);
    printf("expected value %f\n", sqrt(128. / 144.));

    int64_t vv = T(2, 2, 2, 2, 2, 2);
    printf("144V^2 = %lld \n", vv);

    solve_w(2, 2, 2, 2, 2, t);
    for (auto w : solve_w_results)
        printf("w=%lld for test case\n", w);


    printf("known solution %lld\n", T(117, 265, 177, 89, 197, 280));

    printf("known solution %lld\n", T(245, 102, 9, 94, 252, 345));

    int64_t LIM = 350;

    //  U <= V <= W
    // wlog W is the largest length in the tetrahedron
    for (int64_t U = 2; U < LIM; U++) {
        printf("U=%lld\n", U);
        for (int64_t V = U; V < LIM; V++)
            for (int64_t W = V; W < U + V; W++)
                for (int64_t u = 1; u <= W; u++)
                    for (int64_t v = W - u+1; v <= W; v++) {
                        solve_w(u, v, U, V, W, t);
                        for (auto w : solve_w_results) {
                            int64_t t2 = T(u, v, w, U, V, W);
                            printf("(%lld %lld %lld %lld %lld %lld), %lld, %f\n",
                                u, v, w, U, V, W, t, Volume(u, v, w, U, V, W));
                            if ( t2== t)
                                printf("*********** SOLUTION ***********\n");
                            if (U > 2)  return;
                        }
                    }
    }

}


int main() {

    search(655);
}
