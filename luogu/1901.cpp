#include<cstdio>
const int N = 1e6+10;
int sta[N], h[N], val[N], ans[N], top, n;
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d %d", &h[i], &val[i]);//h第i个塔高度 val 第i个塔的能量
	}
	top = 0;
	for(int i=1; i<=n; i++) {//枚举1到n，处理第i个塔往左看的情况。
		while(top > 0 && h[sta[top]] <= h[i])top--;
		// 当栈不为空，且栈顶元素比第i个塔矮，说明：
		// 1. 栈顶在后续是看不见的：第i个塔挡住了
		// 2. 第i个塔不会将能量发给比它矮的。
		// top--：出栈
		if(top>0) // 当栈内有元素说明
				  // 1. 栈顶元素比第i个塔高
				  // 2. 第i个塔的能量会给第一个离他近的塔。栈顶的塔
			ans[sta[top]] += val[i];
		sta[++top] = i;//将第i个塔入栈
	}
	top = 0;//栈初始化，清空。
	for(int i=n; i>=1; i--) {//枚举n到1，处理第i个塔往右看的情况。
		while(top > 0 && h[sta[top]] <= h[i])top--;
		if(top>0)
			ans[sta[top]] += val[i];
		sta[++top] = i;
	}
	int mx = 0;
	for(int i=1; i<=n; i++) //在ans中求最大值。
		if(mx < ans[i])mx = ans[i];
	printf("%d", mx);
	return 0;
}
