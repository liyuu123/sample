//区间修改线段树模板<query> 
#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();(c>'9'||c<'0')&&c!='-';c=getchar())if(c=='-')f=-1;
	for(;c<='9'&&c>='0';c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return x*f;
}
struct node {
	int num[8],add;
}tree[100005*4];

int a[100005];
int x,y,z,q,n;
string s;
inline void update(int k)										//更新父节点 
{
	for(int i=0;i<=6;++i) tree[k].num[i]=tree[k<<1].num[i]+tree[k<<1|1].num[i];
}
inline void build_tree(int root,int l,int r)					//建树 
{
	if(l==r)
	{
		++tree[root].num[a[l]%7];
		return;
	}
	int mid=(l+r)>>1;
	build_tree(root<<1,l,mid);
	build_tree(root<<1|1,mid+1,r);
	update(root);
	return;
}
inline void push(int k,int x)									//val的累加 
{
	int t[8];
	for(int i=0;i<=6;++i)t[i]=tree[k].num[i];
	for(int i=0;i<=6;++i)tree[k].num[(i+x)%7]=t[i];
	tree[k].add+=x;
}
inline void change(int k)										//顺带更新子节点 
{
	if(tree[k].add)
	{
	    push(k<<1,tree[k].add);
	    push(k<<1|1,tree[k].add);
		tree[k].add=0;
	}
}
inline void add(int root,int x,int y,int l,int r,int val){		//区间修改 
	if(l<=x&&y<=r)
	{
        push(root,val);
		return;
	}
	change(root);
	int mid=(x+y)>>1;
	if(mid>=l)add(root<<1,x,mid,l,r,val);
	if(r>mid)add(root<<1|1,mid+1,y,l,r,val);
    update(root);
	return;
}
int query(int root,int x,int y,int l,int r)						//区间的询问 
{
	if(l<=x&&y<=r)return tree[root].num[0];
	change(root);												//先更新子节点 
	int mid=(x+y)>>1,ret1=0,ret2=0;
	if(mid>=l)ret1+=query(root<<1,x,mid,l,r);
	if(r>mid)ret2+=query(root<<1|1,mid+1,y,l,r);
	return ret1+ret2;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	build_tree(1,1,n);
	
	q=read();
	while(q--)
	{
		cin>>s;
		if(s[0]=='c'){
			x=read();y=read();
			cout<<query(1,1,n,x,y)<<endl;
		}
		else {
			x=read();y=read();z=read()%7;
			add(1,1,n,x,y,z);
		}
	}
}
