#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m,k,maxt;
struct node{
	int num,val;
};
bool vis[1005];
vector <node> edge[1005];
bool check(int x){
	memset(vis,0,sizeof(vis));
	deque <node> q;
	q.push_back((node){1,0});
	while(!q.empty()){
		node now=q.front();
		q.pop_front();
		if(vis[now.num])continue;
		vis[now.num] = true;
		if(now.num==n){
			if(now.val<=k)return true;
			else return false;
		}
		for(int i=0;i<(int)edge[now.num].size();i++){
			node to=edge[now.num][i];
			if(to.val<=x) q.push_front((node){to.num,now.val});
			else q.push_back((node){to.num,now.val+1});
		}
	}
	return false;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		maxt=max(maxt,z);
		edge[x].push_back((node){y,z});
		edge[y].push_back((node){x,z});
	}
	int l=1,r=maxt+1;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	if(l>maxt)cout<<-1;
	else cout<<l;
	return 0;
}
