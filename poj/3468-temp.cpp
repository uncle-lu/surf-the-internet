#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+10;
long long n,m,a[N],c[3][N];
int lowbit(int x){
	return x&(-x);
}
void up(long long id,long long x,long long t){
	while(x<=n){
		c[id][x]+=t;
		x+=lowbit(x);
	}
	return ;
}
long long sum(long long id,long long x){
	long long ans=0;
	while(x>0){
		ans+=c[id][x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	while(m--){
		char op[2];
		long long r,l,k;
		scanf("%s", op);
		if(op[0]=='C'){
			scanf("%lld%lld%lld",&l,&r,&k);
			up(1,l,k);
			up(1,r+1,-k);
			up(2,l,k*l);
			up(2,r+1,-k*(r+1));
		}else{
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",a[r]-a[l-1]+(r+1)*sum(1,r)-l*sum(1,l-1)+sum(2,l-1)-sum(2,r));
		}
	}
	return 0;
}
