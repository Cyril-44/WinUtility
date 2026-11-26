#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010,P=998244353;
int n,m;
int a[N];
int qpow(int a,int b){
int ans=1;
	while(b){
		if(b&1)
			ans=ans*a%P;
		a=a*a%P;
		b>>=1;
	}
	return ans;
}
void slove(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<qpow(2,n)<<endl;
	// for(int i=0;i<(1<<n);i++){
		
	// }
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
		slove();
	return 0;
}