#include <bits/stdc++.h>
using namespace std;
int n;
int a[50005];
int T;
int l,r;
priority_queue <pair<long long,int>> q;
int ans[50005];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	cin>>T;
	while (T--)
	{
		cin>>l>>r;
		long long sum=0;
		for (int i=1;i<=l;i++)
		{
			sum+=a[i];
		}
		a[1]=sum;
		q.push({sum,1});
		for (int i=l+1;i<=n;i++)
		{
			sum+=a[i]-a[i-l];
			q.push({sum,i-l+1});
			pair<long long,int> X=q.top();
			q.pop();
			while (!q.empty())
			{
				if (X.second<i-l+1-l+1)
				{
					X=q.top();
					q.pop();
					continue;
				}
				ans[i-l+1]=X.first;
				q.push(X);
				break;
			}
		}
		for (int i=n-l+2;i<=n;i++)
		{
			pair<long long,int> X=q.top();
			q.pop();
			while (!q.empty())
			{
				if (X.second<i-l+1-l+1)
				{
					X=q.top();
					q.pop();
					continue;
				}
				ans[i-l+1]=X.first;
				q.push(X);
				break;
			}
		}
		long long A=0;
		for (int i=1;i<=n;i++)
		{
			A^=(i*ans[i]%(2^64));
		}
		cout<<A<<'\n';
	}
	return 0;
}
