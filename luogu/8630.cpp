#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 1024 * 1024 + 10;
struct node {
    int next[26];
    int leaf = 0;
    node() {
        memset(next, -1, sizeof(next));
    }
};
std::vector<node> trie(1);
char word[10], str[N];

void add_word() {
    scanf("%s", word);
    std::sort(word, word + 8);
    int sit = 0;
    for (int i = 0; i < 8; i++) {
        int ch = word[i] - 'a';
        if (trie[sit].next[ch] == -1) {
            trie[sit].next[ch] = trie.size();
            trie.emplace_back();
        }
        sit = trie[sit].next[ch];
    }
    trie[sit].leaf++;
    return;
}

int main() {
    int n, len, ans = 0;
    scanf("%s", str);
    len = strlen(str);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        add_word();

    for (int i = 7; i < len; i++) {
        for (int curr = 0; curr <= 7; curr++)
            word[curr] = str[i - curr];
        std::sort(word, word + 8);
        bool flag = true;
        int sit = 0;
        for (int i = 0; i < 8; i++) {
            int ch = word[i] - 'a';
            if (trie[sit].next[ch] == -1) {
                flag = false;
                break;
            }
            sit = trie[sit].next[ch];
        }
        if (flag)
            ans += trie[sit].leaf;
    }

    printf("%d", ans);
    return 0;
}