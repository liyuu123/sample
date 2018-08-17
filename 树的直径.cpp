#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n,m,x,y,l,sign;
int tot=0;
int next[100005],to[100005],len[100005];
int first[50005];
ll dis[50005],maxx; 
char c;
void inser(int x,int y,int w){
	next[++tot]=first[x];
	first[x]=tot;
	to[tot]=y;
	len[tot]=w;
}
void find(int x)
{
	for(int i=1;i<=n;i++)dis[i]=1e+18;
	priority_queue<pair<int,int> >q;
	dis[x]=0;
	q.push(make_pair(0,x));
	while(!q.empty()){
		int s=q.top().second;q.pop();
		for(int u=first[s];u;u=next[u]){
			if(dis[to[u]]>dis[s]+len[u]){
				dis[to[u]]=dis[s]+len[u];
				q.push(make_pair(-dis[to[u]],to[u]));
			}
		}
	}
}
int main()
{
//	freopen("x.in","r",stdin);
	n=read();m=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();l=read();c=getchar();
		inser(x,y,l);inser(y,x,l);
	}
	find(1);maxx=-1;sign=0;
	for(int i=2;i<=n;i++){
		if(dis[i]>maxx){
			maxx=dis[i];
			sign=i;
		}
	}
	find(sign);maxx=-1;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,dis[i]);
	}
	cout<<maxx;
}
