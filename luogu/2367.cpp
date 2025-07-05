#include <cstdio>

const int N = 1e6 * 5 + 10;
int line[N], sum[N];
int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i <= p; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        sum[x] += z;
        sum[y + 1] -= z;
    }
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1];
    int mi = line[1] + sum[1];
    for (int i = 2; i <= n; i++)
        if (line[i] + sum[i] < mi)
            mi = line[i] + sum[i];
    printf("%d", mi);
    return 0;
}