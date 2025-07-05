#include<iostream>
#include<algorithm>
using namespace std;

int heap[10010], cnt;

void up(int x)
{
	while(x != 1 && heap[x] < heap[x/2])
	{
		swap(heap[x], heap[x/2]);
		x /= 2;
	}
	return ;
}

void down(int x)
{
	while( x*2<=cnt )
	{
		int temp = x * 2;
		if(temp+1 <= cnt && heap[temp+1]  < heap[temp])
			temp++;
		if(heap[x] < heap[temp])
			break;
		swap(heap[x], heap[temp]);
		x = temp;
	}
	return ;
}

void add(int x)
{
	heap[++cnt] = x;
	up(cnt);
	return ;
}

void del()
{
	swap(heap[1], heap[cnt]);
	cnt--;
	down(1);
	return ;
}

int main()
{
	int n, temp, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		add(temp);
	}

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		a = heap[1];
		del();
		b = heap[1];
		del();
		ans += a + b;
		add(a+b);
	}

	cout << ans;
	return 0;
}
