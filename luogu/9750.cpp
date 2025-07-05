#include <cmath>
#include <cstdio>

bool check_1(int x) {
    return (int)sqrt(x) * (int)sqrt(x) == x;
}

int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int func_2(int x) { // 从根号中取完全平方数
    int k = 1;
    for (int i = 2; i * i <= x; i++)
        while (x % (i * i) == 0) {
            k *= i;
            x /= (i * i);
        }
    return k;
}

void printxy(int x, int y) {
    bool flag = (x < 0) ^ (y < 0); // 算出符号
    if (flag)
        printf("-");
    x = abs(x), y = abs(y);
    int g = gcd(x, y);
    x /= g, y /= g;
    if (y == 1)
        printf("%d", x);
    else
        printf("%d/%d", x, y);
}

int main() {
    int t, m, a, b, c;
    scanf("%d %d", &t, &m);
    while (t--) {
        scanf("%d %d %d", &a, &b, &c);
        int delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("NO\n");
            continue;
        }
        if (check_1(delta)) { // 是完全平方数
            delta = sqrt(delta);
            int x = -b + (a < 0 ? -1 : 1) * delta, y = 2 * a;
            if (x == 0) {
                printf("0\n");
                continue;
            }
            printxy(x, y);
            printf("\n");
        } else {                     // 不是完全平方数
            int x = func_2(delta);   // x * sqrt(delta);
            delta = delta / (x * x); // sqrt(delta);
            if (b != 0) {
                printxy(-b, 2 * a);
                printf("+");
            }
            int y = 2 * a;
            x = abs(x), y = abs(y);
            int g = gcd(x, y);
            x /= g, y /= g;
            if (x != 1)
                printf("%d*", x);
            printf("sqrt(%d)", delta);
            if (y != 1)
                printf("/%d", y);
            printf("\n");
        }
    }
    return 0;
}