#include <cstdio>
#include <algorithm>

const int N = 2e3 + 10;
struct node {
    int a, b;
    friend bool operator<(const node x, const node y) {
        return x.a + x.b < y.a + y.b || (x.a+x.b == y.a + y.b && x.b < y.b);
    }
};
int F[N];

int main() {

}