#include <cstdio>
#include <cmath>

const int N = 1e5 + 10;
int a[N], v[N], n, d;

int find_next(int x) { // 找x后第一个比它小的加油站
    for(int i = x + 1; i <= n; i++) 
        if(a[i] <= a[x])
            return i;
    return n;
}

int main() {
    scanf("%d %d", &n, &d);
    for (int i = 1; i < n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int sit = 1, l = 0;
    long long money = 0; // sit 当前车的位置, l 是当前能开的公里数
    while(sit < n) { // 模拟开车的过程
        int nxt = find_next(sit); 
        long long sum = 0; // 找到第一个比它小的加油站
        for(int i = sit; i < nxt; i++) // 枚举从sit -> nxt 一共的路程距离
            sum += v[i];
        long long oil = ceil(1.0 * (sum - l) / d);
        money += oil * a[sit];
        l = oil * d + l  - sum; // 算这次开完后能剩的公里数
        sit = nxt; // 让车开下一个位置
    }
    printf("%lld", money);
    return 0;
}