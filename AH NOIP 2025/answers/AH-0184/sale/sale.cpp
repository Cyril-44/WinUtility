#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int c,t,n,m;
int a[5010];
int Fa = 1;

ull p(ull a,ull b)
{
	ull ans = 1;
	for(ull i = 1;i <= b;i++)
	{
		ans *= a;
		ans %= 998244353;
	}
	return ans;
}

int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
	
	cin>>c>>t;
	for(int i = 1;i <= t;i++)
	{
		cin>>n>>m;
		cout<<p(2,n)<<endl;
	}
		
    return 0;
}
