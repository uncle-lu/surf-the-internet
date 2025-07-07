#include <algorithm>
#include <cstdio>

const int N = 1e5 + 10;
struct node {
    int l, r, val, lazy_b, lazy_d;
};
node tree[N * 4];
int n, m, line[N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    
}