#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define mid ((l+r)/2)
#define lson t*2,l,mid
#define rson t*2+1,mid+1,r
const int N = 205; 
int n,cnt;
double ans,raw[N],val[N*4];
int ti[N*4];
map <double,int> num;
struct node{
	double x,y,z;
	int k;
	friend bool operator<(const node &A,const node &B){
		return A.x<B.x;
	}
}a[N];
void Pushup(int t, int l, int r){
	if(ti[t]) val[t]=(raw[r+1]-raw[l]);
	else val[t]=val[t*2]+val[t*2+1];
}
void Build(int t,int l,int r){
	if(l==r){
		val[t]=0,ti[t]=0;
		return ;
	}
	Build(lson);
	Build(rson);
	Pushup(t, l, r);
}
void Add(int x,int y,int k,int t,int l,int r){
	if(r<x||l>y)return ;
	if(l>=x&&r<=y){
		ti[t]+=k;
		Pushup(t, l, r);
		return ;
	}
	Add(x,y,k,lson);
	Add(x,y,k,rson);
	Pushup(t, l, r);
}

int main(){
	while(cin>>n&&n){
		memset(a,0,sizeof(a));
		memset(raw,0,sizeof(raw));
		num.clear();
		memset(val,0,sizeof(val));
		memset(ti,0,sizeof(ti));
		cnt++;
		ans=0;
		for(int i=1;i<=n;i++){
			int k=i*2;
			double y,z;
			cin>>a[k-1].x>>y>>a[k].x>>z;
			raw[k-1]=a[k-1].y=a[k].y=y;
			raw[k]=a[k-1].z=a[k].z=z;
			a[k-1].k=1,a[k].k=-1;
		}
		n*=2;
		sort(raw+1,raw+n+1);
		int m=unique(raw+1,raw+n+1)-(raw+1);
		for(int i=1;i<=m;i++)num[raw[i]]=i;
		sort(a+1,a+n+1);
		Build(1,1,m-1);
		for(int i=1;i<n;i++){
			int y=num[a[i].y],z=num[a[i].z]-1;
			Add(y,z,a[i].k,1,1,m-1);
			ans+=val[1]*(a[i+1].x-a[i].x);
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n",cnt,ans);
	}
	return 0;
}
