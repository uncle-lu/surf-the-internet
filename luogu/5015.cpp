#include <cstdio>
#include <cstring>
char str[10];
int main() {
    fgets(str, sizeof(str), stdin);
    int cnt = 0, len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\n')
            continue;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}