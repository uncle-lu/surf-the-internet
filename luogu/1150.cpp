#include <cstdio>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", n + (n - 1) / (k - 1));
    return 0;
}