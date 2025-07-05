#include <cstdio>

int main() {
    int n;
    long long int sum = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int p, temp, t = 1;
        scanf("%d", &temp);
        p = temp % 10;
        temp /= 10;
        for(int j=1; j<=p; j++)
            t *= temp;
        sum += t;
    }
    printf("%lld", sum);
    return 0;
}