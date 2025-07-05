#include <cstdio>

const int N = 1e5 + 10;
int n, S, sum;
int line[N];

int main() {
    scanf("%d %d", &n, &S);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &line[i]);
        sum += line[i];
    }

    return 0;
}