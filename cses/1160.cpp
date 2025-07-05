#include <cstdio>
#include <vector>

const int N = 2e5 + 10;
int n, q, f[N][35], fa[N];
std::vector<int> start;

int find_father(int x) {
    return fa[x] == x ? x : fa[x] = find_father(fa[x]);
}

bool merge(int x, int y) {
    int fx = find_father(x), fy = find_father(y);
    if (fx != fy) {
        fa[fy] = fx;
        return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i][0]);
        if (merge(i, f[i][0])) {
            start.push_back(i);
        }
    }
}