#include<queue>
#include<iostream>
using namespace std;
const int N=1e5+10;
struct node {
	int num;
	long long int x;
	friend bool operator<(const node X,const node Y){
		return X.x> Y.x;
	}
};
priority_queue <node> q;
int a[N],b[N],l[N],r[N],n,k,t=0;
bool vis[N];
long long ans;
int main(){
	cin>>n>>k>>b[0];
	for(int i=1;i<n;i++){
		cin>>b[i];
		a[i]=b[i]-b[i-1];
		l[i]=i-1;
		r[i]=i+1;
		q.push((node){i,a[i]});
	}
	a[0]=a[n]=0x3f3f3f3f;
	while(t<k){
		node now=q.top();
		q.pop();
		if(vis[now.num]) continue;
		t++;
		ans+=now.x;
		a[now.num] = a[l[now.num]]+a[r[now.num]]-now.x;
		q.push((node){now.num,a[now.num]});
		vis[l[now.num]]=1;
		vis[r[now.num]]=1;
		l[now.num]=l[l[now.num]];
		r[l[now.num]]=now.num;
		r[now.num]=r[r[now.num]];
		l[r[now.num]]=now.num;
	}
	cout<<ans<<endl;
	return 0;
}
