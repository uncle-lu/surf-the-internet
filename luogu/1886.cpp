#include <cstdio>
#include <cstring>

const int N = 1e6 + 10;
int line[N], qu[N], sit[N], head = 0, last = -1;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i <= n; i++) {
        while (head <= last && qu[last] >= line[i])
            last--;
        qu[++last] = line[i];
        sit[last] = i;
        while (head <= last && sit[head] < i - k + 1)
            head++;
        if (i >= k) {
            printf("%d ", qu[head]);
        }
    }
    head = 0;
    last = -1;
    memset(qu, 0, sizeof(qu));
    memset(sit, 0, sizeof(sit));
    printf("\n");
    for (int i = 1; i <= n; i++) {
        while (head <= last && qu[last] <= line[i])
            last--;
        qu[++last] = line[i];
        sit[last] = i;
        while (head <= last && sit[head] < i - k + 1)
            head++;
        if (i >= k) {
            printf("%d ", qu[head]);
        }
    }
    return 0;
}