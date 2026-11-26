#include<bits/stdc++.h>
using namespace std;
long long int c,t,n,m,a[5009],ans;
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ans+=n;
		ans++;
		for(int i=1;i<=n;i++)
		{
			ans+=n-i;
		}
		cout<<2*ans%998244353<<"\n";
	}
	return 0;
}

