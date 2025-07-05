#include <iostream>
using namespace std;
long long a,b,pri[20],c[20],sum,mod=9901;
long long ans=1;
long long mi(long long x,long long y){
	long long temp=1;
	while(y){
		if(y&1)temp=(temp*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return temp % mod;
}
long long solve(int x){
	if((pri[x]-1)%mod==0) return c[x]*b+1;
	return (mi(pri[x],b*c[x]+1) - 1 + mod)*mi(pri[x]-1,mod-2)%mod;
}
int main(){
	cin>>a>>b;
	if(a == 0 || b == 0) {
		cout << (a == 0 ? 0 : 1)<< endl;
		return 0;
	}
	for(int i=2;i*i<=a;i++){
		if(a%i==0)pri[++sum]=i;
		while(a%i==0)c[sum]++,a/=i;
	}
	if(a>1)pri[++sum]=a,c[sum]++;
	for(int i=1;i<=sum;i++){
		ans*=solve(i);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
