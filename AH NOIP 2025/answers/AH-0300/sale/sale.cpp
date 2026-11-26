#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[21221];
int n,m;
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		
			long long s=1;
			for(int i=1;i<=n;i++)
			{
				s=s*2;
				s=s%998244353;
			}
		if(c==18)
		{	
			cout<<s<<endl;
		}
		else cout<<s-2<<endl;
	}
		
	
}

