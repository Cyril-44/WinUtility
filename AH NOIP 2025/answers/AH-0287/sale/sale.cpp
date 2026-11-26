#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
long long n,m,mod=998244353;
long long a[1000005];
long long power(long long n,long long k){
	long long ans=1;
	while (n--) ans*=k,ans%=mod;
	return ans;
} 
int main (){
	freopen ("sale.in","r",stdin);
	freopen ("sale.out","w",stdout);
	int c,t;
	cin >>c>>t;
	while (t--){
		cin >>n>>m;
		for (int i=1;i<=n;i++)
			cin >>a[i];
		sort(a+1,a+1+n);
		cout <<power(2,n)%mod<<endl;
	}	
	return 0;
}
