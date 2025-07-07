#include <cstdio>
#include <algorithm>

const int N = 1e3 +10;
int line[N], F[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            F[i] = std::max(F[i], F[i - j] + line[j]);
    printf("%d", F[n]);
    return 0;
}