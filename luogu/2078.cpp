#include <cstdio>
#include <cmath>

int father[10010];

int find_father(int x) {
    return father[x] == x ? x : father[x] = find_father(father[x]);
}

int func(int num, int re) {
    for(int i = 1; i <= num; i++) // 初始化
        father[i] = i;
    for(int i = 1; i <= re; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x = find_father(abs(x));
        y = find_father(abs(y));
        if(x != y) 
            father[y] = x;
    }
    int fa = find_father(1), cnt = 0;
    for(int i = 1; i <= num; i++)
        if(find_father(i) == fa)
            cnt++;
    return cnt;
}

int main() {
    int n, m, p, q;
    scanf("%d %d %d %d", &n, &m, &p, &q);
    int a = func(n, p);
    int b = func(m, q);
    printf("%d", a < b ? a : b);
    return 0;
}