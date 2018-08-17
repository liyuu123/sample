#include<bits/stdc++.h>
using namespace std;
struct node{
	int next,to,len;
}e[300005];
int n,m;
int tot=0;
long long dis[100005];
int first[100005],dep[100005],f[100005][20];
bool vis[100005];

inline void inser(int x,int y,int z)
{
	e[++tot].next=first[x];
	first[x]=tot;
	e[tot].to=y;
	e[tot].len=z;
}
inline void dfs(int s)
{
	vis[s]=1;
	for(int u=first[s];u;u=e[u].next)
	{
		if(!vis[e[u].to]){
			dep[e[u].to]=dep[s]+1;
			dis[e[u].to]=dis[s]+e[u].len;
			f[e[u].to][0]=s;
			dfs(e[u].to);
		}
	}
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int len=dep[x]-dep[y];
	for(int top=0;len;len>>=1,top++)
	{
		if(len&1)x=f[x][top];
	}
	if(x==y)return x;
	for(int i=1;i<=18;i++)
	{
		if(f[x][0]!=f[y][0])
		x=f[x][0],y=f[y][0];
	}
	return f[x][0];
}
int main()
{
	int x,y,z;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>z;
		inser(x,y,z);inser(y,x,z);
	}
	dis[1]=0;dep[1]=0;
	dfs(1);
	for(int i=1;i<=18;i++)
		for(int j=1;j<=n;j++)
			if(f[j][i-1])
				f[j][i]=f[f[j][i-1]][i-1];
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		long long ans=dis[x]+dis[y]-2*dis[lca(x,y)];
		cout<<ans<<endl;
	}
}
