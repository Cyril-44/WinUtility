#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
long long a[N];
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		unsigned long long ans=a[1];
		for(long long i=2;i<=n;i++)
		{
			unsigned long long cnt=a[i]*i;
			ans=ans^cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}
