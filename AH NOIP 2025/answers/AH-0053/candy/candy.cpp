#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100010;
int x[maxn], y[maxn], n, m, sum = 1e15, idx, ans;
priority_queue<int> q;
priority_queue<int> q2;
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		if(x[i]+y[i]<sum || (x[i]+y[i]==sum && x[i]>x[idx]))
		{
			sum = x[i]+y[i];
			idx = i;
		}
	}
	for(int i=1;i<=n;i++)
		if(i!=idx)
			q.push(-x[i]);
	//cout<<sum<<" "<<x[idx]<<" "<<y[idx]<<endl;
	while(!q.empty())
	{
		if(q.size()==1) break;
		int u1 = -q.top();
		q.pop();
		int u2 = -q.top();
		q.pop();
		if(u1+u2<sum && m>=u1+u2)
		{
			m -= u1+u2;
			q2.push(u1);
			q2.push(u2);
			ans+=2;
		}
		else
		{
			q.push(-u1);
			q.push(-u2);
			break;
		}
	}
	int cnt = m/sum;
	ans += cnt*2;
	m -= cnt*sum;
	q.push(-x[idx]);
	//cout<<cnt<<endl<<m<<endl;
	while(!q.empty())
	{
		int u = -q.top();
		q.pop();
		if(m>=u)
		{
			ans++;
			m -= u;
		}
		else
			break;
	}
	while(!q2.empty())
	{
		int u = q2.top();
		q2.pop();
		if(m+u>=sum)
		{
			ans++;
			q.push(-u);
			m -= sum-u;
		}
	}
	cout<<ans<<endl;
	return 0;
}
