#include <cmath>
#include <cstdio>
#include <cstring>

char str[120], sta[120], staop[120];
int sta_top, staop_top, line[120], line_top;
int level(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    return 0;
}
int main() {
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            staop[++staop_top] = '(';
        } else if (str[i] == ')') {
            while (staop[staop_top] != '(')
                sta[++sta_top] = staop[staop_top--];
            staop_top--;
        } else if (str[i] >= '0' && str[i] <= '9') {
            sta[++sta_top] = str[i];
        } else {
            while (staop_top > 0 && (level(staop[staop_top]) > level(str[i]) ||
                                     (level(staop[staop_top]) == level(str[i]) && str[i] != '^'))) {
                sta[++sta_top] = staop[staop_top];
                staop_top--;
            }
            staop[++staop_top] = str[i];
        }
    }
    while (staop_top > 0)
        sta[++sta_top] = staop[staop_top--];
    for (int i = 1; i <= sta_top; i++) {
        printf("%c ", sta[i]);
    }
    printf("\n");
    for (int i = 1; i <= sta_top; i++) {
        if (sta[i] >= '0' && sta[i] <= '9') {
            line[++line_top] = sta[i] - '0';
            continue;
        }
        switch (sta[i]) {
        case '+':
            line[line_top - 1] += line[line_top];
            break;
        case '-':
            line[line_top - 1] -= line[line_top];
            break;
        case '*':
            line[line_top - 1] *= line[line_top];
            break;
        case '/':
            line[line_top - 1] /= line[line_top];
            break;
        case '^':
            line[line_top - 1] = pow(line[line_top - 1], line[line_top]);
            break;
        }
        line_top--;
        for (int j = 1; j <= line_top; j++)
            printf("%d ", line[j]);
        for (int j = i + 1; j <= sta_top; j++)
            printf("%c ", sta[j]);
        printf("\n");
    }
    return 0;
}