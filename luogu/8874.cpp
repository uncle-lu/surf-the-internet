#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 110;
int n, m, q, l, person;
int c[N][N], d[N], who[N], level[N], sit[2];
long long int money[2], a[N];
// renko 0 merry 1

void check(int model) {
    if (money[model] < 0) {
        printf("%s", model == 0 ? "Renko" : "Merry");
        exit(0);
    }
    return;
}

int main() {
    memset(who, -1, sizeof(who));
    scanf("%d %d %d %d", &n, &m, &q, &l);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < l; j++)
            scanf("%d", &c[i][j]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    sit[0] = sit[1] = 1;
    money[0] = money[1] = m;
    int model = 1, t, k;
    while (~scanf("%d %d", &t, &k)) {
        if (t == 1) {
            model ^= 1;
            if (model == 0) {
                for (int i = 1; i <= n; i++)
                    if (who[i] != -1)
                        money[who[i]] += d[i];
            }
        }
        if (t == 1) { // 走路模式
            while (k--) {
                sit[model]++;
                if (sit[model] > n)
                    sit[model] = 1;
                if (who[sit[model]] == model)
                    money[model] += a[sit[model]];
                else if (who[sit[model]] == (model ^ 1)) {
                    money[model] -= a[sit[model]];
                    money[model ^ 1] += a[sit[model]];
                }
                check(model);
            }
        } else {
            int build = sit[model];
            if (who[build] == (model ^ 1)) // 如果建筑不是自己的
                continue;
            for (int i = 1; i <= k; i++) { // 升级 k 次
                if (money[model] >= c[build][level[build]] && level[build] < l) {
                    money[model] -= c[build][level[build]];
                    a[build] += c[build][level[build]];
                    level[build]++;
                    who[build] = model;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (who[i] != -1)
            money[who[i]] += d[i];
    printf("%lld %lld", money[0], money[1]);
    return 0;
}