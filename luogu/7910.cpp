#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 8010;
struct node {
    int val, sit;
};
int now[N];
node line[N];

bool cmp(node a, node b) {
    return a.val < b.val || (a.val == b.val && a.sit < b.sit);
}

int main() {
    int n, T, model, x, v;
    scanf("%d %d", &n, &T);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &line[i].val);
        line[i].sit = i;
    }
    sort(line + 1, line + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        now[line[i].sit] = i;
    while (T--) {
        scanf("%d", &model);
        if (model == 1) {
            scanf("%d %d", &x, &v);
            line[now[x]].val = v;
            int sit = now[x];
            while (sit > 1 && (line[sit].val < line[sit - 1].val ||
                               (line[sit].val == line[sit - 1].val && line[sit].sit < line[sit - 1].sit))) {
                now[line[sit].sit] = sit - 1;
                now[line[sit - 1].sit] = sit;
                swap(line[sit], line[sit - 1]);
                sit--;
            }
            while (sit < n && (line[sit].val > line[sit + 1].val ||
                               (line[sit].val == line[sit + 1].val && line[sit].sit > line[sit + 1].sit))) {
                now[line[sit].sit] = sit + 1;
                now[line[sit + 1].sit] = sit;
                swap(line[sit], line[sit + 1]);
                sit++;
            }
        } else {
            scanf("%d", &x);
            printf("%d\n", now[x]);
        }
    }
    return 0;
}