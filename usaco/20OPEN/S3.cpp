#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
struct node {
	int x, y;
	friend bool operator<(const node a, const node b) {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	}
};
node line[N];
int s[N], top;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		scanf("%d %d", &line[i].x, &line[i].y);
	sort(line, line + n);

	for (int i = 0; i < n; ++i) {
		if(top == 0 || s[top] > line[i].y) {
			s[++top] = line[i].y;
		}
		else {
			while(top > 1 && s[top-1] <= line[i].y) {
				s[top-1] = s[top];
				top--;
			}
		}
	}
	printf("%d", top);
	return 0;
}
