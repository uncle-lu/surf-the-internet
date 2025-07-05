#include <cstdio>

int main() {
    long long int n;
    scanf("%lld", &n);
    for (long long int i = 1; i * i <= n; i++) {
        printf("%lld ", i * i);
    }
    return 0;
}