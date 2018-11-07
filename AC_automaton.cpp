//luogu P3808 AC×Ô¶¯»ú EZ edition
#include<bits/stdc++.h>
#define ll long long
#define iv inline void
using namespace std;
int read(){
    int x=0,f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
struct node{
    int son[35];
    int fail;
    bool end;
}tr[2000005];
int vis[2000005];
char s[2000005];
int n;
int tot=0,ans=0;
iv build_tr(){
    int pos=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(!tr[pos].son[s[i]-'a']){
            tr[pos].son[s[i]-'a']=++tot;
        }
        pos=tr[pos].son[s[i]-'a'];
    }tr[pos].end=1;vis[pos]++;
}
iv build_fail(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(tr[0].son[i])q.push(tr[0].son[i]);
    }
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=0;i<26;i++){
            if(tr[x].son[i]){
                int v=tr[x].fail;
                do{
                    if(tr[v].son[i]){
                        tr[tr[x].son[i]].fail=tr[v].son[i];break;
                    }v=tr[v].fail;
                }while(v);
                q.push(tr[x].son[i]);
            }
        }
    }
}
iv do_it(){
    int len=strlen(s);
    int pos=0;
    for(int i=0;i<len;i++){
        while(!tr[pos].son[s[i]-'a']&&pos){
            pos=tr[pos].fail;
        }
        pos=tr[pos].son[s[i]-'a'];if(tr[pos].end)while(vis[pos])vis[pos]--,ans++/*,cout<<pos<<endl*/;
    }cout<<ans;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        build_tr();
    }
    build_fail();
    scanf("%s",s);
    do_it();
}
