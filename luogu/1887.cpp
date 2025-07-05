#include <cstdio>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m - n % m; i++) 
        printf("%d ", n / m);
    for (int i = 1; i <= n % m; i++) 
        printf("%d ", n / m + 1);
    return 0;
}