#include <cstdio>

int main() {
    long long int a, b, ans = 1;
    scanf("%lld %lld", &a, &b);
    while (b != 0) {
        if (b & 1)
            ans *= a;
        a = a * a;
        b >>= 1;
        if (ans > 1e9) {
            printf("-1");
            return 0;
        }
    }
    printf("%lld", ans);
    return 0;
}