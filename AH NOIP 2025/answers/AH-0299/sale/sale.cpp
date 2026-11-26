# include <bits/stdc++.h>
using namespace std;
int a[5100];
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	long long c,t,n,m,sum;
	cin >>c>>t;
	while(t--){
		cin >>n>>m;
		sum=1;
		for (long long i=1;i<=n;i++){
			cin >>a[i];
			sum=sum*2%998244353;
		}
		cout <<sum<<endl;
	}
	return 0;
}
