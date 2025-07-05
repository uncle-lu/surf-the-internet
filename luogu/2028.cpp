#include <cstdio>

const int N = 10010, K = 1010;
unsigned long long int f[N][K];
int main() {
    int n, k;
    long long int p;
    scanf("%d %d %lld", &n, &k, &p);
    for (int i = 1; i <= n; i++) {
        f[i][1] = 1;
        for (int j = 2; j <= k; j++) {
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * j % p) % p;
        }
    }
    printf("%llu", f[n][k]);
    return 0;
}