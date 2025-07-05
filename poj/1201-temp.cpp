#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int T,n,d[50005];
struct node{
	int num,val;
};
vector <node> edge[50005];
bool vis[50005];
int main(){
	cin>>n;
	for(int i=0;i<=50001;i++) edge[i].clear();
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		edge[x].push_back((node){y+1,z});
	}
	for(int i=0;i<=50000;i++){
		edge[i].push_back((node){i+1,0});
		edge[i+1].push_back((node){i,-1});
	}
	memset(d,-0x7f7f7f7f,sizeof(d));
	memset(vis,0,sizeof(vis));
	queue <node> q;
	q.push((node){0,0});
	d[0]=0;
	vis[0]=true;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		vis[now.num]=true;
		for(int i=0;i<(int)edge[now.num].size();i++){
			node to=edge[now.num][i];
			if(to.val+d[now.num]>d[to.num]){
				d[to.num]=to.val+d[now.num];
				if(vis[to.num])continue;
				q.push((node){to.num,d[to.num]});
				vis[to.num]=true;
			}
		}
	}
	cout<<d[50001]<<endl;
	return 0;
}
