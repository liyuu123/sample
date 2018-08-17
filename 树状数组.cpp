//HDU1166-树状数组模板（区间和）：曾贵胜
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define N 50005
using namespace std;
int n,tree[N];
int Lowbit(int i)       //计算2^k(k为i在二进制下0的个数) 
{
    return i & (-i);
}
void Update(int i,int x)  //修改 
{
    while(i<=n)
    {
        tree[i]=tree[i]+x;
        i=i+Lowbit(i);
    }   
}
int Query(int n)  //查询 
{
    int sum=0;
    while(n>0)
    {
        sum=sum+tree[n];
        n=n-Lowbit(n);
    }   
    return sum;
}
int main()
{
    //freopen("hdu1166.in","r",stdin);
    //freopen("hdu1166.out","w",stdout);    
    
    int T;
    scanf("%d", &T);
    for(int cas=1;cas<=T;cas++) 
    {
        memset(tree,0,sizeof(tree));
        printf("Case %d:\n",cas);
        scanf("%d", &n);
        for(int i=1;i<=n;i++) 
        {
            int x;
            scanf("%d", &x);    //在i点的兵力数量 
            Update(i,x);
        }
        
        char str[10];
        while(scanf("%s",str),strcmp(str,"End"))
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(str[0]=='Q')
                printf("%d\n",Query(b)-Query(a-1));   //输出查询结果 
            else if(str[0]=='S') Update(a,-b);        //减少 
            else  Update(a,b);                        //增加
        } 
    }     
    return 0;
}
