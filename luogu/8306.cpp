#include <cstdio>
#include <cstring>
#include <vector>

const int N = 3e6 + 10;
struct node {
    int next[65];
    int leaf = 0, son = 0;
    node() {
        memset(next, -1, sizeof(next));
    }
};
char str[N];
std::vector<node> trie;

int trans(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    if (c >= 'A' && c <= 'Z')
        return 26 + c - 'A';
    if (c >= '0' && c <= '9')
        return 52 + c - '0';
    return -1;
}

void add_word() {
    scanf("%s", str);
    int len = strlen(str), sit = 0;
    for (int i = 0; i < len; i++) {
        int ch = trans(str[i]);
        if (trie[sit].next[ch] == -1) {
            trie[sit].next[ch] = trie.size();
            trie.emplace_back();
        }
        sit = trie[sit].next[ch];
    }
    trie[sit].leaf++;
    return;
}

int DFS(int x) {
    int sum = trie[x].leaf;
    for (int i = 0; i <= 62; i++) {
        if (trie[x].next[i] != -1)
            sum += DFS(trie[x].next[i]);
    }
    return trie[x].son = sum;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        trie.clear();
        trie.emplace_back();
        int n, q;
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++)
            add_word();
        DFS(0);
        for (int i = 1; i <= q; i++) {
            scanf("%s", str);
            bool flag = true;
            int sit = 0, len = strlen(str);
            for (int i = 0; i < len; i++) {
                int ch = trans(str[i]);
                if (trie[sit].next[ch] == -1) {
                    flag = false;
                    break;
                }
                sit = trie[sit].next[ch];
            }
            if (flag)
                printf("%d\n", trie[sit].son);
            else
                printf("0\n");
        }
    }
    return 0;
}