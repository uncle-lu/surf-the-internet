#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e6+10;
int heap[N], n;

void insert(int val) {
	n++;
	heap[n] = val;
	int x = n;
	while(x > 1 && heap[x] < heap[x/2]) {
		swap(heap[x], heap[x/2]);
		x /= 2;
	}
	return ;
}

void del() {
	swap(heap[n], heap[1]);
	n--;
	int x = 1, son = 2;
	while(x <= n && son <= n) {
		if(son < n && heap[son] > heap[son+1])
			son++;
		if(heap[son] < heap[x]) {
			swap(heap[son], heap[x]);
			x = son;
			son = x * 2;
		}
		else
			break ;
	}
	return ;
}

int main() {
	int op, temp, t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d", &temp);
			insert(temp);
		}
		else if(op == 2) {
			printf("%d\n", heap[1]);
		}
		else if(op == 3) {
			del();
		}
	}
	return 0;
}
