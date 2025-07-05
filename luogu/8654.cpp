#include <cstdio>

int n, m, k, ans;
int father[1000010];

int find_father(int x) {
    return father[x] == x ? x : father[x] = find_father(father[x]);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n * m; i++)
        father[i] = i;
    for(int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x = find_father(x);
        y = find_father(y);
        father[y] = x;
    }
    for(int i = 1; i <= n*m; i++) 
        if(i == find_father(i))
            ans++;
    printf("%d", ans);
    return 0;
}