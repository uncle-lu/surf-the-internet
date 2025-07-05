#include<iostream>
using namespace std;
typedef long long ll;
ll T,p,f[100005];
ll mi(ll a,ll k){
	ll ans=1;
	while(k){
		if(k&1){ans*=a;ans%=p;}
		a=a*a%p;
		k/=2;
	}
	return ans;
}
ll C(ll n,ll m){
	if(m>n)return 0;
	return ((f[n]*mi(f[m],p-2))%p*mi(f[n-m],p-2)%p);
}
ll Lucas(ll n,ll m){
	if(!m)return 1;
	return C(n%p,m%p)*Lucas(n/p,m/p)%p;
}
int main(){
	freopen("in","r",stdin);
	cin>>T;
	while(T--){
		ll n,m;
		cin>>n>>m>>p;
		f[1]=1;
		for(int i=2;i<=p;i++) {f[i]=f[i-1]*i;f[i]%=p;}
		cout<<Lucas(n+m,n)<<endl;
	}
	return 0;
}
