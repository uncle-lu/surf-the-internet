#include <cstdio>
#include <cstring>

const int N = 1e6 + 10;
char str[N];
int ansor, ansand;

bool f(int l, int r) { // 计算字符串中 [l, r] 的值
    if (l == r) // 区间长度为 1 => 一定是一个值
        return str[l] - '0'; // 字符变成值 
    //倒序枚举 => 最后一个同级别的或 和 最后一个同级别的与
    int cnt = 0, sitor = -1, sitand = -1;
    for (int i = r; i >= l; i--)
        if (str[i] == ')') // 级别增加
            cnt++;
        else if (str[i] == '(') // 级别减少
            cnt--;
        else if (cnt == 0 && sitor == -1 && str[i] == '|') // 找到了最后一个同级别的或
            sitor = i;
        else if(cnt == 0 && sitand == -1 && str[i] == '&') // 找到了最后一个同级别的与
            sitand = i;

    if (sitor != -1) { // 找到了同级别的或
        bool x = f(l, sitor - 1); // 计算左边的部分
        if (x) { // 左边是 1 => 触发短路
            ansor++; // 或短路个数增加
            return true; // [l, r] => 计算的结果是 true
        }
        return f(sitor + 1, r); // 计算右边的部分 => 作为整个区间[l, r]的结果
    }

    if(sitand != -1) { // 找到了同级别的与
        bool x = f(l, sitand - 1); // 计算左边的部分
        if(!x){ // 左边是 0 => 触发短路
            ansand++; // 与短路个数增加
            return false; // [l, r] => 计算结果就是 false
        }
        return f(sitand + 1, r); // 计算右边的部分 => 作为整个区间[l, r]的结果
    }

    if(str[l] == '(' && str[r] == ')') // 去掉大括号继续计算
        return f(l + 1, r - 1); 
    return false;
}

int main() {
    scanf("%s", str);
    int len = strlen(str);
    printf("%d\n", f(0, len - 1));
    printf("%d %d", ansand, ansor);
    return 0;
}