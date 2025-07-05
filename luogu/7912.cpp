#include <cstdio>

const int N = 2e5 + 10;
struct node {
    int pre, next, val, sit;
};
node line[N], block[N];
int n, cnt = 1;

void cut_line(int sit) {
    int f = line[sit].pre;
    int nx = line[sit].next;
    line[f].next = nx;
    line[nx].pre = f;
    return;
}

void cut_block(int sit) {
    int f = block[sit].pre;
    int nx = block[sit].next;
    block[f].next = nx;
    block[nx].pre = f;
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &line[i].val);
        line[i].sit = i;
        line[i].pre = i - 1;
        line[i].next = i + 1;
    }
    line[0].val = line[n + 1].val = -1;
    line[0].next = 1;
    line[n + 1].pre = n;
    block[1] = (node){ 0, 2, line[1].val, 1};
    for (int i = 2; i <= n; i++)
        if (line[i].val != block[cnt].val) {
            cnt++;
            block[cnt].val = line[i].val;
            block[cnt].sit = i;
            block[cnt].next = cnt + 1;
            block[cnt].pre = cnt - 1;
        }
    block[0].val = block[cnt + 1].val = -1;
    block[0].next = 1;
    block[cnt + 1].pre = cnt;
    while (n != 0) {
        for (int i = block[0].next; i != cnt + 1; i = block[i].next) {
            printf("%d ", block[i].sit);
            n--;
            cut_line(block[i].sit);
            block[i].sit = line[block[i].sit].next;
            if (line[block[i].sit].val != block[i].val) {
                cut_block(i);
            }
        }
        printf("\n");
        for (int i = block[0].next; i != cnt + 1; i = block[i].next) {
            int nx = block[i].next;
            while (block[nx].val == block[i].val)
                nx = block[nx].next;
            block[nx].pre = i;
            block[i].next = nx;
        }
    }
    return 0;
}