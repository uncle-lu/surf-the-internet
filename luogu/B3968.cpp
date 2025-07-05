#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e4+10;
struct node {
    int s1, s2, s3, s;
    int sit, rank;
};
node line[N];

bool cmp1(node a, node b) {
    return a.s > b.s ||
        (a.s == b.s && (a.s1 + a.s2) > (b.s1 + b.s2)) ||
        (a.s == b.s && (a.s1 + a.s2) == (b.s1 + b.s2) && max(a.s1, a.s2) > max(b.s1, b.s2));
}

bool cmp2(node a, node b) {
    return (a.s == b.s && (a.s1 + a.s2) == (b.s1 + b.s2) && max(a.s1, a.s2) == max(b.s1, b.s2));
}

bool cmp3(node a, node b) {
    return a.sit < b.sit;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> line[i].s1 >> line[i].s2 >> line[i].s3;
        line[i].s = line[i].s1 + line[i].s2 + line[i].s3;
        line[i].sit = i;
    }
    sort(line, line+n, cmp1);
    for(int i = 0; i < n; i++) { // 处理并记录排名
        if(i == 0)
            line[i].rank = 1;
        else if (cmp2(line[i], line[i-1]))
            line[i].rank = line[i-1].rank;
        else
            line[i].rank = i+1;
    }
    sort(line, line+n, cmp3);
    for(int i = 0; i < n; i++)
        cout << line[i].rank << endl;
    return 0;
}