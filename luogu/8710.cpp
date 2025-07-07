#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e4 + 10;
int s[N], father[N], d[N], q[N], n, m;

int find_father(int x) {
    return father[x] == x ? x : father[x] = find_father(father[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        s[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int model, x, y;
        scanf("%d %d %d", &model, &x, &y);
        if (model == 1) {
            x = find_father(x);
            y = find_father(y);
            if(x == y) 
                continue;
            for (int i = 1; i <= n; i++)
                d[i] += q[find_father(i)];
            for (int i = 1; i <= n; i++)
                q[i] = 0;
            if (s[x] < s[y])
                swap(x, y);
            s[x] += s[y];
            father[y] = x;
        } else {
            x = find_father(x);
            q[x] += y;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", d[i] + q[find_father(i)]);
    return 0;
}