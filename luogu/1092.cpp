#include <algorithm>
#include <cstdio>
#include <cstring>

int n;
char line_1[30], line_2[30], line_3[30];
bool visit[30];
int search_list[30], cnt;
int number[30];

bool mini_check() {
    for (int i = n - 1; i >= 0; i--) {
        if (number[line_1[i] - 'A'] == -1 || number[line_2[i] - 'A'] == -1 || number[line_3[i] - 'A'] == -1)
            continue;
        if ((number[line_1[i] - 'A'] + number[line_2[i] - 'A']) % n != number[line_3[i] - 'A'] &&
            (number[line_1[i] - 'A'] + number[line_2[i] - 'A'] + 1) % n != number[line_3[i] - 'A'])
            return false;
    }
    return true;
}

bool check() {
    int before = 0;
    for (int i = n - 1; i >= 0; i--) {
        int temp = number[line_1[i] - 'A'] + number[line_2[i] - 'A'] + before;
        if (temp % n != number[line_3[i] - 'A'])
            return false;
        before = temp / n;
    }
    printf("%d", number[0]);
    for (int i = 1; i <= n - 1; ++i)
        printf(" %d", number[i]);
    exit(0);
}

void DFS(int x) {
    if (x == n) {
        check();
        return;
    }

    for (int i = n - 1; i >= 0; --i) {
        if (visit[i])
            continue;
        number[search_list[x]] = i;
        if (mini_check()) {
            visit[i] = true;
            DFS(x + 1);
            visit[i] = false;
        }
    }

    number[search_list[x]] = -1;

    return;
}

int main() {
    scanf("%d", &n);
    scanf("%s%s%s", line_1, line_2, line_3);

    for (int i = n - 1; i >= 0; i--) {
        if (!visit[line_1[i] - 'A'])
            search_list[cnt++] = line_1[i] - 'A', visit[line_1[i] - 'A'] = true;
        if (!visit[line_2[i] - 'A'])
            search_list[cnt++] = line_2[i] - 'A', visit[line_2[i] - 'A'] = true;
        if (!visit[line_3[i] - 'A'])
            search_list[cnt++] = line_3[i] - 'A', visit[line_3[i] - 'A'] = true;
    }

    memset(visit, false, sizeof(visit));
    memset(number, -1, sizeof(number));
    DFS(0);

    return 0;
}