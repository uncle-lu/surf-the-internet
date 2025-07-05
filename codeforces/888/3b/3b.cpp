#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 2*1e5+10;
int line[N], temp[N];

int main() {
	int T, n;
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &line[i]);
			temp[i] = line[i];
		}
		sort(temp+1, temp+1+n);
		bool flag = true;
		for(int i=1; i<=n; i++) {
			if( temp[i]%2 != line[i]%2 ) {
				flag = false;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
