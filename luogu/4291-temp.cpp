#include<iostream>
#include<map>
using namespace std;
const int SIZE =3e5+10;
struct node{
	int l,r;
	int val,dat,ti,size;
	string name;
}tree[SIZE];
struct value{
	int val,ti;
};
map <string,value> mp;
int tot,root,n,INF=0x7fffffff;
int New(int val,int ti,string name){
	tree[++tot].val=val;
	tree[tot].dat=rand();
	tree[tot].size=1;
	tree[tot].ti=ti;
	tree[tot].name=name;
	return tot;
}
void update(int x){
	tree[x].size=tree[tree[x].l].size+tree[tree[x].r].size+1;
}
void build(){
	New(-INF,1,"minn");
	New(INF,1,"maxx");
	root=2;
	tree[2].r=1;
	update(root);
}
void zig(int &x){
	int temp = tree[x].l;
	tree[x].l=tree[temp].r;
	tree[temp].r=x;
	x=temp;
	update(tree[x].r),update(x);
	return ;
}
void zag(int &x){
	int temp=tree[x].r;
	tree[x].r=tree[temp].l;
	tree[temp].l=x;
	x=temp;
	update(tree[x].l),update(x);
	return ;
}
void Insert(int &x,int val,int ti,string name){
	if(x==0){
		x=New(val,ti,name);
		return ;
	}
	if( val>tree[x].val || (val==tree[x].val&&ti<tree[x].ti) ){
		Insert(tree[x].l,val,ti,name);
		if(tree[x].dat<tree[tree[x].l].dat){
			zig(x);
		}
	}else{
		Insert(tree[x].r,val,ti,name);
		if(tree[x].dat<tree[tree[x].r].dat){
			zag(x);
		}
	}
	update(x);
	return ;
}
void Remove(int &x,int val,int ti){
	if(x==0)return ;
	if(tree[x].val==val&&tree[x].ti==ti){
		if(tree[x].l||tree[x].r){
			if(tree[x].r==0||tree[tree[x].r].dat<tree[tree[x].l].dat)
				zig(x),Remove(tree[x].r,val,ti);
			else 
				zag(x),Remove(tree[x].l,val,ti);
			update(x);
		}
		else x=0;
		return ;
	}
	if( val>tree[x].val || (val==tree[x].val&&ti<tree[x].ti) )
		Remove(tree[x].l,val,ti);
	else 
		Remove(tree[x].r,val,ti);
	update(x);
	return ;
}
int GRBV(int x,int val,int ti){
	if(x==0)return 0;
	if(tree[x].val==val&&tree[x].ti==ti)return tree[tree[x].l].size+1;
	if( val>tree[x].val || (val==tree[x].val&&ti<tree[x].ti) )
		return GRBV(tree[x].l,val,ti);
	return GRBV(tree[x].r,val,ti)+tree[tree[x].l].size+1;
}
string GVBR(int x,int rank){
	if(x==0)return "maxx";
	if(tree[tree[x].l].size>=rank)
		return GVBR(tree[x].l,rank);
	if(tree[tree[x].l].size+1==rank)
		return tree[x].name;
	return GVBR(tree[x].r,rank-tree[tree[x].l].size-1);
}
int main(){
	srand(time(0));
	int x,tim;
	cin>>n;
	char opt;
	string nam;
	build();
	for(int t=1; t<=n; t++){
		cin>>opt;
		cin>>nam;
		if(opt=='+'){
			cin>>x;
			if(mp.find(nam) != mp.end())
				Remove(root,mp[nam].val,mp[nam].ti);
			tim=t;
			mp[nam]=(value){x,tim};
			Insert(root,x,tim,nam);
		}else if(nam[0]>='0'&&nam[0]<='9'){
			int temp=0;
			for(int i=0;i<(int)nam.size();i++)
				temp=temp*10+nam[i]-'0';
			for(int i=temp;i<=min(temp+9, tree[root].size-2);i++){
				string ans=GVBR(root,i+1);
				cout<<ans<<' ';
			}
			cout<<endl;
		}else{
			cout<<GRBV(root,mp[nam].val,mp[nam].ti)-1<<endl;
		}
	} 
	return 0;
}
