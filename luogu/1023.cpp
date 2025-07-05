#include <cstdio>

const int N = 1e5 + 10;
int s[N], l, r; // s[x] 价格为 x 的销售量

int getmax(int x) { // 找到最大的利润点
    int mx = -1e9, mx_sit = l;
    for (int i = l; i <= r; i++)
        if (mx < (i - l + x) * s[i]) {
            mx = (i - l + x) * s[i];
            mx_sit = i;
        }
    return mx_sit;
}

int main() {
    freopen("out","w", stdout);
    int target, a, b, down;
    scanf("%d", &target);
    scanf("%d %d", &a, &b);
    l = a;
    s[l] = b;
    int curr = l + 1;
    while (scanf("%d %d", &a, &b) && a != -1 && b != -1) {
        while (curr <= a) {
            s[curr] = s[curr - 1] + (s[curr - 1] - b) / (curr - 1 - a);
            printf("%d ", (s[curr-1] - b) / (curr-1-a));
            printf("%d %d\n", curr, s[curr]);
            curr++;
        }
        s[a] = b;
    }
    scanf("%d", &down);
    curr -= 1;
    while (s[curr] - down > 0) {
        s[curr + 1] = s[curr] - down;
        curr++;
    }
    r = curr - 1;
    for(int i = l; i < r; i++) {
        printf("%d ", s[i]);
    }
    int s = getmax(0);
    if(s == target)
        printf("0");
    else if(s < target) { // 收税
        for(int i = -1; i >= -r; i--)
            if(getmax(i) == target) {
                printf("%d", i);
                return 0;
            }
        printf("NO SOLUTION");
    }
    else {
        for(int i = 1; i <= r; i++) 
            if(getmax(i) == target) {
                printf("%d", i);
                return 0;
            }
        printf("NO SOLUTION");
    }
    return 0;
}