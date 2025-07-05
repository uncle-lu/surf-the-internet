#include <cstdio>

const int N = 1e5 + 10;
int t[N], val[N], head = 0, last = -1;
bool vis[N];

int main() {
    int n, type, ti, temp, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &type, &temp, &ti);
        while (head <= last && (ti - t[head] > 45 || vis[head]))
            head++;
        if (type) {
            bool flag = false;
            for (int t = head; t <= last; t++)
                if (val[t] >= temp && !vis[t]) {
                    flag = true;
                    vis[t] = true;
                    break;
                }
            if (!flag)
                ans += temp;
        } else {
            ans += temp;
            last++;
            t[last] = ti;
            val[last] = temp;
        }
    }
    printf("%d", ans);
    return 0;
}