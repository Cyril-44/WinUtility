#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m,x,y,p=1234562345673456789ll,ans=0;
	priority_queue<int,vector<int>,greater<int> > r;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		p=min(p,x+y);
		r.push(x);
	}
	ans=m/p*2;
	for(int i=1;i<=n;i++)
	{
		m-=r.top();
		r.pop();
		ans=max(ans,m/p*2+i);
	}
	cout<<ans<<endl;
	return 0;
}
// 08:30 - 08:40, samples passed (36 ms), 100 points
