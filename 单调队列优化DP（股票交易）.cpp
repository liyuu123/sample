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
	for(int i=0;i<t;i++)			//�������� 
		scanf("%d%d%d%d",ap+i,bp+i,as+i,bs+i);
	for(int i=0;i<=t;i++)			//��ʼ������״̬Ϊ������ 
		for(int j=0;j<=p;j++)
			dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=0;i<t;i++){
		//���˵�һ���״̬�⣬����״̬������ǰһ��ת�ƹ��� 
		if(i!=0)
			for(int j=0;j<=p;j++)
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
		d=i+w>t?t:i+w;
		q[tail=top=0]=0;
		//���������״̬ת�� 
		for(int j=1;j<=p;j++){
			while(q[tail]+as[i]<j)	//ɾ�������в���ת�Ƶ�j��״̬ 
				tail++;
			dp[d][j]=max(dp[d][j],dp[i][q[tail]]-ap[i]*(j-q[tail]));
			//�Ƴ�����ͷ��ת�Ʋ��ȴ�jת���ŵ�״̬ 
			while(dp[i][q[top]]-ap[i]*(j-q[top])<=dp[i][j]&&tail<=top)
				top--;
			q[++top]=j;
		}
		//����������״̬ת�� 
		q[tail=top=0]=p;
		for(int j=p-1;j>=0;j--){
			while(q[tail]>bs[i]+j)	//ɾ�������в���ת�Ƶ�j��״̬ 
				tail++;
			dp[d][j]=max(dp[d][j],dp[i][q[tail]]+bp[i]*(q[tail]-j));
			///�Ƴ�����ͷ��ת�Ʋ��ȴ�jת���ŵ�״̬ 
			while(dp[i][q[top]]+bp[i]*(q[top]-j)<=dp[i][j]&&tail<=top)
				top--;
			q[++top]=j;
		}
	}
	printf("%d\n",max(dp[t][0],dp[t-1][0]));
	return 0;
}
