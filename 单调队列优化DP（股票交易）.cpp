#include<bits/stdc++.h>
#define maxn 2007
#define inf -1000000000
using namespace std;
int dp[maxn][maxn];
int q[maxn];
int ap[maxn],bp[maxn],as[maxn],bs[maxn];
int main(){
	int t,p,w,tail,top,d;
	scanf("%d%d%d",&t,&p,&w);
	w++;
	for(int i=0;i<t;i++)			//输入数据 
		scanf("%d%d%d%d",ap+i,bp+i,as+i,bs+i);
	for(int i=0;i<=t;i++)			//初始化所有状态为负无穷 
		for(int j=0;j<=p;j++)
			dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=0;i<t;i++){
		//除了第一天的状态外，其他状态可以由前一天转移过来 
		if(i!=0)
			for(int j=0;j<=p;j++)
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
		d=i+w>t?t:i+w;
		q[tail=top=0]=0;
		//买进操作的状态转移 
		for(int j=1;j<=p;j++){
			while(q[tail]+as[i]<j)	//删除队列中不能转移到j的状态 
				tail++;
			dp[d][j]=max(dp[d][j],dp[i][q[tail]]-ap[i]*(j-q[tail]));
			//移除堆列头部转移不比从j转移优的状态 
			while(dp[i][q[top]]-ap[i]*(j-q[top])<=dp[i][j]&&tail<=top)
				top--;
			q[++top]=j;
		}
		//卖出操作的状态转移 
		q[tail=top=0]=p;
		for(int j=p-1;j>=0;j--){
			while(q[tail]>bs[i]+j)	//删除队列中不能转移到j的状态 
				tail++;
			dp[d][j]=max(dp[d][j],dp[i][q[tail]]+bp[i]*(q[tail]-j));
			///移除堆列头部转移不比从j转移优的状态 
			while(dp[i][q[top]]+bp[i]*(q[top]-j)<=dp[i][j]&&tail<=top)
				top--;
			q[++top]=j;
		}
	}
	printf("%d\n",max(dp[t][0],dp[t-1][0]));
	return 0;
}
