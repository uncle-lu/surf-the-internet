#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 5e5 + 10;
char str[N];
int len, F[N][3], G[N][3];

int DFS(int x) {
    int lson, rson;
    if (str[x] == '0') {
        F[x][0] = 1;
        G[x][0] = 1;
        return x;
    } else if (str[x] == '1') {
        lson = DFS(x + 1);
        F[x][0] = std::min(F[x + 1][1], F[x + 1][2]) + 1;
        G[x][0] = std::max(G[x + 1][1], G[x + 1][2]) + 1;
        F[x][1] = std::min(F[x + 1][0], F[x + 1][2]);
        G[x][1] = std::max(G[x + 1][0], G[x + 1][2]);
        F[x][2] = std::min(F[x + 1][0], F[x + 1][1]);
        G[x][2] = std::max(G[x + 1][0], G[x + 1][1]);
        return lson;
    }
    lson = DFS(x + 1);
    rson = DFS(lson + 1);
    F[x][0] = std::min(F[lson + 1][1] + F[x + 1][2], F[lson + 1][2] + F[x + 1][1]) + 1;
    G[x][0] = std::max(G[lson + 1][1] + G[x + 1][2], G[lson + 1][2] + G[x + 1][1]) + 1;
    F[x][1] = std::min(F[lson + 1][0] + F[x + 1][2], F[lson + 1][2] + F[x + 1][0]);
    G[x][1] = std::max(G[lson + 1][0] + G[x + 1][2], G[lson + 1][2] + G[x + 1][0]);
    F[x][2] = std::min(F[lson + 1][0] + F[x + 1][1], F[lson + 1][1] + F[x + 1][0]);
    G[x][2] = std::max(G[lson + 1][0] + G[x + 1][1], G[lson + 1][1] + G[x + 1][0]);
    return rson;
}

int main() {
    scanf("%s", str);
    len = strlen(str);
    DFS(0);
    printf("%d %d", std::max({G[0][0], G[0][1], G[0][2]}), std::min({F[0][0], F[0][1], F[0][2]}));
    return 0;
}