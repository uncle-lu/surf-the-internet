#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;
int s, n, d;
int a[N],b[N];
int f[1000010];

int main() {
    scanf("%d %d %d", &s, &n, &d);
    for(int i = 1; i <= d; i++)
        scanf("%d %d", &a[i], &b[i]);
    for(int i = 1; i <= n; i++) {
        memset(f, 0, sizeof(f));
        int m = s / 1000;
        for(int j = 1; j <= d; j++)
            for(int t = a[j]/1000; t <= m; t++)
                f[t] = max(f[t], f[t - a[j]/1000] + b[j]);
        s += f[m];
    }
    printf("%d", s);
    return 0;
}