#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int fg=1;fg<=t;fg++)
	{
		int n,m;
		cin>>n>>m;
		int a[n+10];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n==1)
		{
			cout<<"2";
			continue;
		}
			int k=1;
			for(int i=1;i<=n;i++)
			{
				k*=2;
				k%=998244353;
			}
			cout<<k;
	}
	return 0;
}
