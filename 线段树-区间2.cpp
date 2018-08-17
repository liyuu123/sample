#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n,m,x,y,k;
struct node{
	int l,r;
	int lz;
	int sz;
	long long sum;
}tr[800005];
int a[100005];
inline void build_tr(int x,int l,int r){
	tr[x].l=l;tr[x].r=r;
	if(l==r){
		tr[x].sz=1;
		tr[x].sum=a[l];
		return;
	}
	int mid=l+r>>1;
	build_tr(x<<1,l,mid);
	build_tr(x<<1|1,mid+1,r);
	tr[x].sz=tr[x<<1].sz+tr[x<<1|1].sz;
	tr[x].sum=tr[x<<1].sum+tr[x<<1|1].sum;
}
inline void pushd(int x){
	tr[x].sum+=tr[x].sz*tr[x].lz;
	tr[x<<1].lz+=tr[x].lz;
	tr[x<<1|1].lz+=tr[x].lz;
	tr[x].lz=0;
}
inline void add(int x,int l,int r,int w){
	if(tr[x].l>=l&&tr[x].r<=r){
		tr[x].lz+=w;return;
	}
	if(tr[x].lz)pushd(x);
	int mid=tr[x].l+tr[x].r>>1;
	if(l<=mid)add(x<<1,l,r,w);
	if(r>mid)add(x<<1|1,l,r,w);
	if(tr[x<<1].lz)pushd(x<<1);
	if(tr[x<<1|1].lz)pushd(x<<1|1);
	tr[x].sum=tr[x<<1].sum+tr[x<<1|1].sum;
}
long long query(int x,int l,int r){
	if(tr[x].lz)pushd(x);
	if(tr[x].l>=l&&tr[x].r<=r){
		return tr[x].sum;
	}
	int mid=tr[x].l+tr[x].r>>1;
	long long x1=0,x2=0;
	if(l<=mid)x1=query(x<<1,l,r);
	if(r>mid)x2=query(x<<1|1,l,r);
	return x1+x2;
}
int main(){
//	freopen("123.in","r",stdin);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}build_tr(1,1,n);
	for(int i=1;i<=m;i++){
		x=read();
		if(x==1){
			x=read();y=read();k=read();
			add(1,x,y,k);
		}
		else {
			x=read();y=read();
			cout<<query(1,x,y)<<endl;
		}
	}
}
