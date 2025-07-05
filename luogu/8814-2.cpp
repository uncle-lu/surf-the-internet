#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long int n, d, e, A, B, p, q;
        scanf("%lld %lld %lld", &n, &d, &e);
        A = n - e * d + 2;
        B = n;
        if (A * A - 4 * B < 0) {
            printf("NO\n");
            continue;
        }
        p = (sqrt(A * A - 4 * B) + A) / 2;
        q = A - p;
        if (p * q == n && e * d == (p - 1) * (q - 1) + 1 && p && q)
            printf("%lld %lld\n", min(p, q), max(p, q));
        else
            printf("NO\n");
    }
    return 0;
}