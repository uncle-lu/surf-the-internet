#include <cstdio>
const int N = 100010;
int line1[N], line2[N];
int head1 = 1, last1 = 0, head2 = 1, last2 = 0, cnt;
int main() {
    int s, temp;
    char mod, turn;
    scanf("%d", &s);
    for (int i = 1; i <= s; i++) {
        scanf("\n%c %c", &mod, &turn);
        if (mod == 'A') {
            ++cnt;
            if (turn == 'L')
                line1[++last1] = cnt;
            else
                line2[++last2] = cnt;
        } else {
            scanf("%d", &temp);
            if (turn == 'R') {
                if (temp > (last2 - head2 + 1)) {
                    temp -= (last2 - head2 + 1);
                    last2 = head2 - 1;
                    head1 += temp;
                } else
                    last2 -= temp;
            } else {
                if (temp > (last1 - head1 + 1)) {
                    temp -= (last1 - head1 + 1);
                    last1 = head1 - 1;
                    head2 += temp;
                } else
                    last1 -= temp;
            }
        }
    }
    for (int i = last1; i >= head1; i--)
        printf("%d\n", line1[i]);
    for (int i = head2; i <= last2; i++)
        printf("%d\n", line2[i]);
    return 0;
}
