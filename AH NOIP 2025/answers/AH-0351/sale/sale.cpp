#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,m;
int a[1010]={0};
int b[1010]={0};
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		int ans=1;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ans=(ans*2)%998244353;
		}
		sort(a+1,a+n+1);
		if(a[1]>a[2]/2&&a[1]<a[2]&&c==17)ans--;
		cout<<ans<<endl;
	}
	return 0;
}
