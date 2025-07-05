#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n,root,a[1005],v[1005],f[1005];
long long ans,tmp;
vector <int> edge[1005];
struct node{
	long long val,num;
	friend bool operator <(const node A,const node B){
		return A.val>B.val;
	}
};
priority_queue <node> q;
void dfs(int x){
	v[x]=a[x];
	for(int i=0;i<(int)edge[x].size();i++){
		if(edge[x][i]==f[x])continue;
		dfs(edge[x][i]);
		v[x]+=v[edge[x][i]];
	}
}
int main(){
	while(cin>>n>>root&&n){
		ans=0,tmp=0;
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) edge[i].clear();
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			edge[x].push_back(y);
			f[y]=x;
		}
		dfs(root);
		for(int i=1; i<=n; i++)
			cout << v[i] << ' ';
		cout << endl;
		q.push((node){a[root],root});
		int cnt = 0;
		while(!q.empty()){
			int val=q.top().val,x=q.top().num;
			cout << "#" << ++cnt <<  " x: " << x << endl;
			q.pop();
			ans+=v[root]-tmp;
			tmp+=a[x];
			for(int i=0;i<(int)edge[x].size();i++){
				int to=edge[x][i];
				if(to==f[x]) continue;
				q.push((node){v[root]-tmp-v[to],to});
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
