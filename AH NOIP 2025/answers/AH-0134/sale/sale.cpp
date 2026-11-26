#include<bits/stdc++.h>
using namespace std;
int c,t;
const long long mod=998244353;
int main()
{
	freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
		long long n,m,ans=0;
		cin>>n>>m;
		for(int i=1,x;i<=n;i++) scanf("%d",&x);
		ans=pow(2,n);
		ans%=mod;
		printf("%lld\n",ans);
    }
    return 0;
}
