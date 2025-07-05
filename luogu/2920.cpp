#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010;
struct node{
	int t, s;
	friend bool operator<(const node a, const node b) {
		return a.s < b.s;
	}
};
node line[N];
int n;
bool check(int x) {
	int t = x;
	for(int i=1; i<=n; i++) {
		t += line[i].t;
		if(t > line[i].s)
			return false;
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) 
		scanf("%d %d", &line[i].t, &line[i].s);
	sort(line+1, line+1+n);
	int l=0, r=line[1].s, mid;
	while(l < r) {
		mid = (l + r + 1) / 2;
		if(check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	if(!check(0))
		printf("-1");
	else
		printf("%d", l);
	return 0;
}
