#include<bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;
int read(){
    int x=0,f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
int write[25];
#define m(a) memset(a,0,sizeof(a))
void wr(int x){
    m(write);int ctt=0;
    if(x<0)x=-x,putchar('-');
    for(;x;x/=10)write[++ctt]=x%10;
    if(!ctt)write[++ctt]=0;
    while(ctt)putchar(write[ctt--]+'0');
}
#define maxn 2005
#define maxm 1000005
int n,m,x,y,l;
int tot=0,ans=0;;
int fst[maxn],mtc[maxn],las[maxn];
bool vis[maxn];
struct node{
    int nxt;
    int to;
}e[maxm];
void inser(int x,int y){
    e[++tot].nxt=fst[x];
    fst[x]=tot;
    e[tot].to=y;
}
bool upt(int x){
    vis[x]=1;
    for(int u=e[las[x]].nxt;u;u=e[u].nxt){
        int v=e[u].to;
        if(mtc[v]){
            int cptr=mtc[v];
            if(vis[cptr])continue;
            if(upt(cptr)){
                mtc[v]=x;
                las[x]=u;
                return 1;
            }
        }
        else {
            mtc[v]=x;
            las[x]=u;
            return 1;
        }
    }return 0;
}
bool dfs(int x){
    vis[x]=1;
    for(int u=fst[x];u;u=e[u].nxt){
        int v=e[u].to;
        if(mtc[v]){
            int cptr=mtc[v];
            if(upt(cptr)){
                mtc[v]=x;
                las[x]=u;
                return 1;
            }
        }
        else {
            mtc[v]=x;
            las[x]=u;
            return 1;
        }
    }return 0;
}
int main(){
//	freopen("x.in","r",stdin);
    n=read();m=read();l=read();
    for(int i=1;i<=l;i++){
        x=read();y=read()+n;
        if(y>m+n)continue;
        inser(x,y);
    }
    for(int i=1;i<=n;i++){
        m(vis);
        if(dfs(i))ans++;
    }wr(ans);
}
