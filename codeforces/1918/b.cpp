#include<cstdio>
#include<algorithm>
using namespace std;
struct node {
	int a, b;
};
bool cmp(node a, node b) {
	return a.a < b.a;
}
const int N = 2e5+10;
node line[N];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) 
			scanf("%d", &line[i].a);
		for(int i=1; i<=n; i++) 
			scanf("%d", &line[i].b);
		sort(line+1, line+1+n, cmp);
		for(int i=1; i<=n; i++)
			printf("%d%c", line[i].a, " \n"[i==n]);
		for(int i=1; i<=n; i++)
			printf("%d%c", line[i].b, " \n"[i==n]);
	}
	return 0;
}
