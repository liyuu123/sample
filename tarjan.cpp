#include<bits/stdc++.h>
#define maxn 10005
#define maxm 100005
using namespace std;
int n,m;
int tot=0,top=0,t=0,k=0;
int first[maxn],next[maxm],en[maxn],to[maxm],id[maxn],outdegree[maxn],dfn[maxn],low[maxn],sta[maxn],num[maxn];
bool insta[maxn];
inline void inser(int x,int y)
{
	next[++tot]=first[x];
	first[x]=tot;
	to[tot]=y;
	en[tot]=x;
}
inline void dfs(int x)
{
	t++;top++;
	low[x]=t;dfn[x]=t;
	sta[top]=x;insta[x]=1;
	for(int u=first[x];u;u=next[u])
	{
		int v=to[u];
		if(!dfn[v]){
			dfs(v);
			low[x]=min(low[x],low[v]);
		}
		else if(insta[v]){
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(low[x]==dfn[x])
	{
		k++;
		int f=-1;
		while(f!=x)
		{
			f=sta[top--];
			id[f]=k;
			num[k]++;
			insta[f]=0;
		}
	}
}/*
void dfs(int x){
	dfn[x]=low[x]=++t;
	insta[x]=true;
	sta[++top]=x;
	for(int u=first[x];u;u=next[u]){
		int v=to[u];
		if(!dfn[v]) dfs(v),low[x]=min(low[x],low[v]);
		else  if(insta[v])
			low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		k++;
		int a=-1;
		while(a!=x){
			a=sta[top--];
			id[a]=k;
			num[k]++;
			insta[a]=false;
		}
	}
}*/
int main()
{
	int a,b;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		inser(a,b);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])dfs(i);
	}
	for(int i=1;i<=m;i++)
	{
		if(id[en[i]]!=id[to[i]])
		{
			outdegree[id[en[i]]]++;
		}
	}
	int sum=0,sign;
	for(int i=1;i<=k;i++)
	{
		if(!outdegree[i]){
			sum++;
			sign=i;
		}
	}
	if(sum==1)cout<<num[sign]<<endl;
	else cout<<0<<endl;
}
