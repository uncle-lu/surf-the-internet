#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
    int l, w;
};
bool cmp(node a, node b) {
    return a.l < b.l || (a.l == b.l && a.w < b.w);
}
const int N = 5010;
node line[N];
int f[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &line[i].l, &line[i].w);
    sort(line + 1, line + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--)
            if (line[j].w > line[i].w)
                f[i] = max(f[i], f[j] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    printf("%d", ans + 1);
    return 0;
}