#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int M = 1e4 + 10, N = 100;
struct node {
    int v, next, val;
} edge[M * 2];
struct heapnode {
    int v, w;
    friend bool operator<(const heapnode a, const heapnode b) {
        return a.w > b.w;
    }
};
int head[N], dis[N], cnt;
bool vis[N];

int char_turn(char x) {
    if (x <= 'z' && x >= 'a')
        return x - 'a';
    else
        return x - 'A' + 30;
}

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].val = val;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void Dijkstra(int start) {
    memset(dis, 0x7f, sizeof(dis));
    dis[start] = 0;
    priority_queue<heapnode> qu;
    qu.push((heapnode){start, 0});
    while (!qu.empty()) {
        heapnode now = qu.top();
        qu.pop();
        int x = now.v;
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = head[x]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (dis[v] > dis[x] + edge[i].val) {
                dis[v] = dis[x] + edge[i].val;
                qu.push((heapnode){v, dis[v]});
            }
        }
    }
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        char u, v;
        int val;
        scanf("\n%c %c %d", &u, &v, &val);
        add_edge(char_turn(u), char_turn(v), val);
        add_edge(char_turn(v), char_turn(u), val);
    }
    Dijkstra(char_turn('Z'));
    int mi = 0x7f7f7f7f;
    char ans;
    for (char i = 'A'; i <= 'Y'; i++) {
        int x = char_turn(i);
        if (mi > dis[x]) {
            mi = dis[x];
            ans = i;
        }
    }
    printf("%c %d", ans, mi);
    return 0;
}