#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long a[maxn],n,f[maxn],s[maxn];
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {cin>>a[i];s[i]=s[i-1]+a[i];}
	int q;
	cin>>q;
	while(q--)
	{
		int L,R;
		cin>>L>>R;
		for(int i=1;i<=n;i++) f[i]=-(0x7f7f7f7f);
		for(int len=L;len<=R;len++)
			for(int i=1;i+len-1<=n;i++)
			{
				for(int j=i;j<=i+len-1;j++)
				{
					f[j]=max(f[j],s[i+len-1]-s[i-1]);
				}
			}
		unsigned long long sum=0;
		for(int i=1;i<=n;i++) {
			sum=sum^(i*f[i]);
		}
		cout<<sum<<"\n";
	}
	return 0;
}
