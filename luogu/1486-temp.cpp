#include<iostream>
using namespace std;
const int SIZE = 3e5 +10;
struct node{
	int l,r;
	int val,dat;
	int cnt,size;
}tree[SIZE];
int sum,tot,root,INF=0x7fffffff,dl,n,ansd;
#define lson tree[x].l
#define rson tree[x].r
void dfs(int x){
	if(lson)dfs(lson);
	cout<<"x:"<<x<<" l:"<<tree[x].l<<" r:"<<tree[x].r << " size:" << tree[x].size <<" val:"<<tree[x].val<<endl;
	if(rson)dfs(rson);
}
int New(int val){
	tree[++tot].val=val;
	tree[tot].dat=rand();
	tree[tot].cnt=tree[tot].size=1;
	return tot;
}
void update(int x){
	tree[x].size=tree[lson].size+tree[rson].size+tree[x].cnt;
}
void Build(){
	New(-INF);
	New(INF);
	root=2;
	tree[2].r=1;
	update(root);
}
void zig(int &x){
	int temp=lson;
	lson=tree[temp].r;
	tree[temp].r=x;
	x=temp;
	update(rson),update(x);
	return ;
}
void zag(int &x){
	int temp=rson;
	rson=tree[temp].l;
	tree[temp].l=x;
	x=temp;
	update(lson),update(x);
	return ;
}
void Insert(int &x,int val){
	if(x==0){
		x=New(val);
		return ;
	}
	if(val==tree[x].val){
		tree[x].cnt++;
		update(x);
		return ;
	}
	if(val>tree[x].val){
		Insert(lson,val);
		if(tree[x].dat<tree[lson].dat ){
			zig(x);
		}
	}else{
		Insert(rson,val);
		if(tree[x].dat<tree[rson].dat ){
			zag(x);
		}
	}
	update(x);
}
void Remove(int &x,int val){
	if(x==0)return ;
	if(tree[x].val==val){
		if(tree[x].cnt>1){
			tree[x].cnt--;
			update(x);
			return ;
		}
		if(lson||rson){
			if(rson==0||tree[rson].dat<tree[lson].dat )
				zig(x),Remove(rson,val);
			else 
				zag(x),Remove(lson,val);
			update(x);
		}
		else x=0;
		return ;
	}
	val>tree[x].val ? Remove(lson,val) : Remove(rson,val) ;
	update(x); 
	return ;
}
int GVBR(int x,int rank){
	if(x==0)return -INF;
	if(tree[lson].size>=rank)
		return GVBR(lson,rank);
	if(tree[lson].size+tree[x].cnt>=rank)
		return tree[x].val;
	return GVBR(rson,rank-tree[lson].size-tree[x].cnt);
}
int Nex(int val){
	int ans=1;
	int x=root;
	while(x){
		if(val==tree[x].val){
			if(rson>0){
				x=rson;
				while(lson)x=lson;
				ans=x;
			}
			break;
		}
		if(tree[x].val<val&&tree[x].val>tree[ans].val) ans=x;
		x=(val>tree[x].val ? tree[x].l : tree[x].r );
	}
	return tree[ans].val;
}
int main(){
	//freopen("in","r",stdin);
	srand(time(0));
	Build();
	cin>>n>>dl;
	while(n--){
		char opt;
		int k;
		cin>>opt>>k;
		if(opt=='I'){
			if(k<dl)continue;
			Insert(root,k-sum);
			/*
			cout << "*************** Insert Begin ************" << endl;
			cout << "sum :" << sum << endl;
			cout << "root :" << root << endl;
			dfs(root);
			cout << "*************** Insert End ************" << endl;
			*/
		}else if(opt=='A') sum+=k;
		else if(opt=='S'){
			sum-=k;
			int nex_v=Nex(dl-sum);
			while(nex_v!=-INF){
				//cout<<nex_v<<endl;
				ansd++;
				Remove(root,nex_v);
				//dfs(root);
				nex_v=Nex(dl-sum);
			}
		}
		else if(opt=='F'){
			if(k>tree[root].size-2)cout<<-1<<endl;
			else cout<<GVBR(root,k+1)+sum<<endl;
		}
	}
	cout<<ansd<<endl;
	return 0;
}
