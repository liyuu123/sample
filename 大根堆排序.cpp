#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int n,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;q.push(-x);
	}
	while(!q.empty())
	{
		cout<<-q.top()<<" ";q.pop();
	}
	cout<<endl;
}
