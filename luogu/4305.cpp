#include <cstdio>
#include <vector>

const int Mod = 331;
std::vector<int> G[Mod];

bool find(int x) {
    int hash = (x % Mod + Mod) % Mod;
    for (int g : G[hash])
        if (g == x)
            return true;
    G[hash].push_back(x);
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < Mod; i++)
            G[i].clear();
        int n, temp;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &temp);
            if (!find(temp))
                printf("%d ", temp);
        }
        printf("\n");
    }
    return 0;
}