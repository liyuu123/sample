#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int getint()
{
	int i=0,f=1;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if(c=='-')f=-1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())i=(i<<3)+(i<<1)+c-'0';
	return i*f;
}

const int N=1e4+5,M=2e5+5,INF=0x3f3f3f3f;
int n,m,tot,st;
int dis[N];
int first[N],next[M],to[M],w[M];
priority_queue<pair<int,int> >q;

void add(int x,int y,int z)
{
	next[++tot]=first[x],first[x]=tot,to[tot]=y,w[tot]=z;
}

void dijstrar()
{
	memset(dis,INF,sizeof(dis));
	dis[st]=0;
	q.push(make_pair(0,st));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(int e=first[u];e;e=next[e])
		{
			int v=to[e];
			if(dis[u]+w[e]<dis[v])
			{
				dis[v]=dis[u]+w[e];
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}

int main()
{
	//freopen("lx.in","r",stdin);
	int x,y,z;
	n=getint(),m=getint(),st=getint();
	for(int i=1;i<=m;i++)
	{
		x=getint(),y=getint(),z=getint();
		add(x,y,z),add(y,x,z);
	}
	dijstrar();
	cout<<dis[n];
	return 0;
}
