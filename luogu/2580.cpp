#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 110;
struct node {
    int next[26];
    bool leaf, flag;
    node() {
        memset(next, -1, sizeof(next));
    }
};
std::vector<node> trie(1);
char str[N];

void add_word() {
    scanf("%s", str);
    int len = strlen(str), sit = 0;
    for (int i = 0; i < len; i++) {
        int ch = str[i] - 'a';
        if (trie[sit].next[ch] == -1) {
            trie[sit].next[ch] = trie.size();
            trie.emplace_back();
        }
        sit = trie[sit].next[ch];
    }
    trie[sit].leaf = true;
    return;
}

void query() {
    scanf("%s", str);
    int len = strlen(str), sit = 0;
    for (int i = 0; i < len; i++) {
        int ch = str[i] - 'a';
        if (trie[sit].next[ch] == -1) {
            printf("WRONG\n");
            return;
        }
        sit = trie[sit].next[ch];
    }
    if (!trie[sit].leaf)
        printf("WRONG\n");
    else if (trie[sit].flag)
        printf("REPEAT\n");
    else {
        printf("OK\n");
        trie[sit].flag = true;
    }
    return;
}

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        add_word();
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        query();
    return 0;
}