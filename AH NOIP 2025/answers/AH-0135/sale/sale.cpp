#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[100005];
int cnt=0;
long long ans=1;
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	for(int l=1;l<=t;l++)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			ans*=2;
			ans%=998244353;
		}
		cout<<ans%998244353<<endl;
	}
	return 0;
}
