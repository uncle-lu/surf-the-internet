#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5*2+10;
int sta[N], top;
int main() {
	int T, mod, temp;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &mod);
		if(mod == 0) {
			scanf("%d", &temp);
			sta[top+1] = max(sta[top], temp);
			top++;
		}
		else if(mod == 1) {
			top--;
		}
		else if(mod == 2) {
			printf("%d\n", sta[top]);
		}
	}
	return 0;
}
