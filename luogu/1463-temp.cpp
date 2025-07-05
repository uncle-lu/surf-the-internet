#include<iostream>
#include<algorithm>
using namespace std;
long long n,c[11],a[11]={1,2,3,5,7,11,13,17,19,23,29};
long long ans,mxx=1;
void dfs(long long x){
	long long temp=1;
	for(int i=1;i<=10;i++)temp*=c[i];
	if(temp>mxx) ans=x;
	else if(temp == mxx) 
		ans = min(ans, x);
	for(int i=1;i<=10;i++){
		if(x*a[i]<=n&&c[i]<c[i-1]){
			c[i]++;
			dfs(x*a[i]);
			c[i]--;
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=10;i++) c[i]=1;
	c[0]=100;
	dfs(1);
	cout<<ans;
	return 0;
}
