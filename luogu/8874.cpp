#include <cstdio>

int n, m, q, l, person, c[110][110], d[110], sit[2], money[2];

int main() {
    scanf("%d %d %d %d", &n, &m, &q, &l);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < l; j++)
            scanf("%d", &c[i][j]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    sit[1] = sit[2] = 1;
}