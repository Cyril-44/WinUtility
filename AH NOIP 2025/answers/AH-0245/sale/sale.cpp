#include<bits/stdc++.h>
using namespace std;
long long const N=5e4+5,mod=998244353;
long long n,m,a[N],c,t;
long long num;

int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		num=1;
		if(m==2)
			cout<<((n%mod)*(m%mod)+mod)%mod<<"\n";
		else if(m==2*n-1){
			for(int i=1;i<n;i++)
				num*=2,num%=mod;
			cout<<num<<"\n";
		}
		else if(m==2*n-2){
			for(int i=1;i<n-1;i++)
				num*=2,num%=mod;
			cout<<num<<"\n";
		}
		else {
			for(int i=1;i<=n;i++)
				num*=2,num%=mod;
			cout<<num<<"\n";
		}
	}
}
