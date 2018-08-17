#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long x=0;char c;
	for(c=getchar();c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x;
}
long long n,m,q;long long fa[5000005];
inline int get_fa(int x){return fa[x]==x?x:get_fa(fa[x]);}
inline void unionn(int a,int b)
{
	int al=get_fa(a),bl=get_fa(b);
	if(al!=bl)fa[al]=bl;
}
inline void find(int a,int b)
{
	int al=get_fa(a),bl=get_fa(b);
	if(al==bl)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main()
{
	long long a,b,x,y;
	n=read();m=read();
	for(int i=1;i<=m;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		a=read();b=read();
		unionn(a,b);
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		x=read();y=read();
		find(x,y);
	}
}
