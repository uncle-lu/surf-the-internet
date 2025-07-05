#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 * 2 + 10;
int c[N], t[N];
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    for (int i = 1; i <= n; i++)
        c[i] -= t[i];
    sort(c + 1, c + 1 + n, cmp);
    while (q--) {
        int v, s;
        scanf("%d %d", &v, &s);
        if (c[v] > s)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}