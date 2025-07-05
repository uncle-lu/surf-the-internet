#include<iostream>
#include<queue>
using namespace std;
int n,m,f1[4]={0,0,-1,1},f2[4]={1,-1,0,0};
char a[305][305];
bool vis[305][305];
struct poi{
	int x,y,t;	
}sta, tong[30][2], now;
queue <poi> qw;
int main()
{
	freopen("P1825_2.in", "r", stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='@')sta=(poi){i,j,0};
			if(a[i][j]>='A'&&a[i][j]<='Z'){
				if(tong[a[i][j]-'A'][0].x){
					tong[a[i][j]-'A'][1].x=i;
					tong[a[i][j]-'A'][1].y=j;
				}else{
					tong[a[i][j]-'A'][0].x=i;
					tong[a[i][j]-'A'][0].y=j;
				}
			}
		}
	}
	qw.push(sta);
	vis[sta.x][sta.y] = true;
	while(!qw.empty()){
		now=qw.front();
//cout << now.x << ' ' << now.y << endl;
		qw.pop();
		for(int i=0;i<=3;i++){
			int tx=now.x+f1[i],ty=now.y+f2[i],tt=now.t+1;
			处理传送
			if(!vis[tx][ty]){
				if(a[tx][ty]=='.'){
					qw.push((poi){tx,ty,tt});
					vis[tx][ty]=1;
				}else if(a[tx][ty]>='A'&&a[tx][ty]<='Z'){
					int t = a[tx][ty] - 'A';
					if(tx==tong[t][0].x && ty==tong[t][0].y){
						tx=tong[t][1].x;
						ty=tong[t][1].y;
					}else{
						tx=tong[t][0].x;
						ty=tong[t][0].y;
					}
					cout << "S: " << (char)(t+'A') << ' ' << tx << ' ' << ty << endl;
					qw.push((poi){tx,ty,tt}); 
					vis[tx][ty] = true;
				}else if(a[tx][ty]=='='){
					cout<<tt;
					return 0;
				}
			}
		} 
	}
	cout<<0;
	return 0;
}

