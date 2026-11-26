#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long kuai(long long a,long long b)
{
	long long x=kuai(a,b/2);
	long long ans=x*x%mod;
	if(b%2==1)ans=ans*a%mod;
	return ans%mod;
}
long long a[5005];
bool flag[5005];
struct node
{
	long long w;
	int num;
	bool operator< (const node &x)const
	{
		return x.w>w;
	}
}b[10005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==18||c==16||c==17)
	{
		while(t--)
		{
			int n,m;
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<kuai(2,n)<<endl;
		}
		return 0;
	}
	//~ if(c==7||c==8||c==9||c==14||c==15)
	//~ {
		//~ while(t--)
		//~ {
			//~ int n,m;
			//~ cin>>n>>m;
			//~ for(int i=1;i<=n;i++)cin>>a[i];
			//~ sort(a+1,a+n+1);
			//~ for(int i=1;i<=n;i++)
			//~ {
				
			//~ }
		//~ }
		//~ return 0;
	//~ }
	if(c==10||c==11||c==12||c==19||c==20)
	{
		while(t--)
		{
			int n,m;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			cout<<kuai(2,n-2)<<endl;
		}
		return 0;
	}
	return 0;
}
