#include<cstdio>
#include<cstring>
char str[710];
int pre[710], back[710];
int main() {
	int n, mx = 0;
	scanf("%d\n", &n);
	scanf("%s", str);
	for(int i = 0; i < n; i++) 
		str[i+n] = str[i];
	n *= 2; 
	char w = 'w'; int wc = 0;
	pre[0] = 1; back[n-1] = 1;
	for (int i = 1; i < n; ++i) {
		if(str[i] == str[i-1] || str[i] == 'w') 
			pre[i] = pre[i-1] + 1;
		else if(str[i-1] == 'w')
			pre[i] = 1 + (w == str[i] ? pre[i-1] : wc);
		else
			pre[i] = 1;
		if(str[i] == 'w')
			wc++;
		else
			wc = 0, w = str[i];

	}
	w = 'w'; wc = 0;
	for (int i = n-2; i >= 0; --i) {
		if(str[i] == str[i+1] || str[i] == 'w') 
			back[i] = back[i+1] + 1;
		else if(str[i+1] == 'w')
			back[i] = 1 + (w == str[i] ? back[i+1] : wc);
		else
			back[i] = 1;
		if(str[i] == 'w')
			wc++;
		else
			wc = 0, w = str[i];
	}
	for(int i = 0; i < n-1; i++) 
		if(mx < pre[i] + back[i+1])
			mx = pre[i] + back[i+1];
	printf("%d", mx > n/2 ? n/2 : mx);
	return 0;
}
