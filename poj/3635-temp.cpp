#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct node{
	int x,f,v;
	friend bool operator<(const node a,const node b){
		return a.v>b.v;
	}
};
struct bian{
	int to,w;
};
int n,m,T,a[1005],sta,fin,c,d[1005][105];
vector <bian> s[1005];
bool vis[1005][105];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int u,v,p;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>p;
		s[u].push_back((bian){v,p});
		s[v].push_back((bian){u,p});
	}
	cin>>T;
	while(T--){
		cin>>c>>sta>>fin;
		memset(vis,0,sizeof(vis));
		memset(d,0x7f,sizeof(d));
		priority_queue <node> q;
		q.push((node){sta,0,0});
		d[sta][0] = 0;
		bool flag = true;
		while(!q.empty()){
			node now=q.top();
			q.pop();
			if(now.x==fin){
				cout<<now.v<<endl;
				flag = false;
				break;
			}
			if(vis[now.x][now.f])continue;
			vis[now.x][now.f]=1;
			if(now.f<c&&d[now.x][now.f+1]>d[now.x][now.f]+a[now.x]){
				d[now.x][now.f+1]=d[now.x][now.f]+a[now.x];
				q.push((node){now.x,now.f+1,d[now.x][now.f+1]});
			}
			for(int i=0;i<(int)s[now.x].size();i++){
				bian temp=s[now.x][i];
				if(temp.w<=now.f&&d[temp.to][now.f-temp.w]>d[now.x][now.f]){
					d[temp.to][now.f-temp.w]=d[now.x][now.f];
					q.push((node){temp.to,now.f-temp.w,d[temp.to][now.f-temp.w]});
				}
			}
		}
		if(flag)
			cout<<"impossible"<<endl;
	}
	return 0;
}
