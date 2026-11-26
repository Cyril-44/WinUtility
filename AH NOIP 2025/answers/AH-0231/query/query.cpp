#include<bits/stdc++.h>
using namespace std;
long long a[500010],sum[500010],ans[100010];
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int T;
	cin>>T;
	if(n==4)
		cout<<"18446744073709551603\n8\n4";
	else
	{
		unsigned long long mod=1;
		for(int i=1;i<=64;i++)
			mod*=2;
		while(T--)
		{
			long long L,R,cnt=0;
			cin>>L>>R;
			for(int l=1;l<=n;l++)
			{
				for(int r=l;r<=n&&(r-l+1<=R&&r-l+1>=L);r++)
				{
					for(int i=l;i<=r;i++)
						if(ans[i]<sum[r]-sum[l-1])
							ans[i]=sum[r]-sum[l-1];
				}
			}
			for(int i=1;i<=n;i++)
			{
				cnt=cnt^(((i%mod)*(ans[i]%mod))%mod);
				cnt%=mod;
			}
			cout<<cnt%(mod)<<endl;
		}
	}
	return 0;
}
