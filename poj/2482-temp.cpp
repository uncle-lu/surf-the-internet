#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define mid ((l+r)/2)
#define lson t*2,l,mid
#define rson t*2+1,mid+1,r
const int N = 20005; 
long long n,w,h;
long long raw[N];
long long ans,val[N*4],tag[N*4];
map <long long,long long> num;
struct node{
	long long x,y,z;
	long long k;
	friend bool operator<(const node &A,const node &B){
		if(A.x==B.x)return A.k<B.k;
		return A.x<B.x;
	}
}a[N];

void Pushup(int t){
	val[t]=max(val[t*2],val[t*2+1]);
}
void Pushdown(int t){
	tag[t*2]+=tag[t];
	tag[t*2+1]+=tag[t];
	val[t*2]+=tag[t];
	val[t*2+1]+=tag[t];
	tag[t]=0;
}
void Build(int t,int l,int r){
	if(l==r){
		val[t]=0;
		tag[t]=0;
		return ;
	}
	Build(lson);
	Build(rson);
	Pushup(t);
}
void Add(int x,int y,int k,int t,int l,int r){
	if(r<x||l>y)return ;
	if(l>=x&&r<=y){
		tag[t]+=k;
		val[t]+=k;
		return ;
	}
	Pushdown(t);
	Add(x,y,k,lson);
	Add(x,y,k,rson);
	Pushup(t);
}
int main(){
	while(cin>>n>>w>>h){
		ans=0;
		memset(raw,0,sizeof(raw));
		memset(a,0,sizeof(a));
		memset(tag, 0, sizeof(tag));
		num.clear();
		for(int i=1;i<=n;i++){
			int k=i*2;
			long long x,y,c;
			cin>>x>>y>>c;
			a[k-1].x=x; a[k-1].y=y; a[k-1].z=y+h-1; a[k-1].k=c;
			a[k].x=x+w; a[k].y=y; a[k].z=y+h-1; a[k].k=-c;
			raw[k-1]=y;
			raw[k]=y-1+h;
		}
		n*=2;
		sort(raw+1,raw+n+1);
		int m=unique(raw+1,raw+n+1)-(raw+1);
		for(int i=1;i<=m;i++) num[raw[i]]=i;
		sort(a+1,a+n+1);
		Build(1,1,m-1);
		for(int i=1;i<=n;i++){
			int y=num[a[i].y],z=num[a[i].z];
			Add(y,z,a[i].k,1,1,m-1);
			ans=max(ans,val[1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
