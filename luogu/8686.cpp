#include <cstdio>

const int N = 1e6+10;
int father[N], n, line[N];

int find_father(int x) {
    return father[x] == x ? x : father[x] = find_father(father[x]);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 1e6; i++)
        father[i] = i;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &line[i]);
        int temp = find_father(line[i]);
        line[i] = temp;
        father[temp] = find_father(temp + 1);
    }
    for(int i = 1; i <= n; i++) 
        printf("%d ", line[i]);
    return 0;
}