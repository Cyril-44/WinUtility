#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+10;
const int mod=998244353;
int a[N];
int qmi(int a,int b){
	int ans=1;
	for(int i=1;i<=b;i++)ans=(ans*a)%mod;
	return ans;
}
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		cout<<(long long)qmi(2,n)%998244353<<'\n';
	}
}
