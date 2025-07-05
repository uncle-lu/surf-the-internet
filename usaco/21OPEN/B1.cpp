#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int line[N];

int main() {
	int n, l, h = 0;
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &line[i]);
	sort(line+1, line+1+n);

	for (int i = n; i >= 1; --i) {
		if(line[i] < (n - i + 1)) {
			if(line[i] + 1 < (n - i + 1))
				break;
			for(int j = i+1; j <= n; j++) {
				if(line[j] == line[j-1]) {
					l--;
					line[j-1]++;
				}
				else
					break;
			}
			if(l <= 0)
				break;
			h = n - i + 1;
		}
		else
			h = n - i + 1;
	}

	printf("%d", h);

	return 0;
}
