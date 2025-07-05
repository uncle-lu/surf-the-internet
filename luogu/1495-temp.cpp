#include<iostream>
using namespace std;
#define ll long long
ll n,a[20],b[20],sum=1,m[20],t[20],ans;
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return ;
	}
	exgcd(b,a%b,x,y);
	ll temp=x;
	x=y;
	y=temp-(a/b)*y;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum*=a[i];
	}
	for(int i=1;i<=n;i++) m[i]=sum/a[i];
	for(int i=1;i<=n;i++){
		ll x,y;
		exgcd(m[i],a[i],x,y);
		t[i]=x;
	}
	for(int i=1;i<=n;i++){
		ans= (ans + (b[i]*m[i])%sum*t[i]%sum + sum) %sum ;
	}
	cout<<(ans + sum)%sum<<endl;
	return 0;
}
