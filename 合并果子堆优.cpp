#include<bits/stdc++.h>;
using namespace std;
priority_queue<int>q;
int n,a;
long long ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		q.push(-a);
	}
	int tmp;
	while(q.size()!=1)
	{
		tmp=q.top();
		q.pop();
		tmp+=q.top();
		q.pop();
		ans-=tmp;
		q.push(tmp);
	}
	cout<<ans<<endl;
}
