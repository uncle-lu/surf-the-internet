#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 150;

int F[N], line[20], t[20], val[20];

int main() {
    int n, m, k, r;
    scanf("%d %d %d %d", &n, &m, &k, &r);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    sort(line + 1, line + 1 + n);
    for(int i = 1; i <= m; i++)
        scanf("%d", &t[i]);
    for(int i = 1; i <= m; i++)
        scanf("%d", &val[i]);
    for(int i = 1; i <= m; i++)
        for(int j = r; j >= t[i]; j--)
            F[j] = max(F[j], F[j - t[i]] + val[i]);
    for(int i = 1; i <= r; i++)
        if(F[i] >= k) {
            r = r - i;
            break;
        }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(line[i] <= r) {
            r -= line[i];
            ans++;
        }
    printf("%d", ans);
    return 0;
}