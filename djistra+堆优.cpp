#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0;char c;
    for(c=getchar();!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
    return x;
    
}
int n,m,s;
int tot=0;
int x,y,z;
int nxt[500005],to[500005],it[500005],len[500005],fst[10005];
int dis[10005];
bool vis[10005];
void inser(int x,int y,int z){
    nxt[++tot]=fst[x];
    fst[x]=tot;
    len[tot]=z;
    to[tot]=y;
    it[tot]=x;
}
int main()
{
	memset(vis,0,sizeof(vis));
    n=read();m=read();s=read();
    for(int i=1;i<=m;i++){
        x=read();y=read();z=read();
        inser(x,y,z);
    }
    for(int i=1;i<=n;i++)dis[i]=2147483647;
    dis[s]=0;
    priority_queue<pair<int,int> >q;
    q.push(make_pair(0,s));
    while(!q.empty()){
        x=q.top().second;
        q.pop();vis[x]=0;
        for(int u=fst[x];u;u=nxt[u]){
            int v=to[u];
            if(dis[v]>dis[x]+len[u]){
                dis[v]=dis[x]+len[u];
                if(!vis[x])q.push(make_pair(-dis[v],v));
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    cout<<endl;
}
