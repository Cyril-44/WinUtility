#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e4;
typedef long long ll;
typedef unsigned long long ull;
int n,q;
ll a[N+5],ans[3005][3005];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ans[i][j]=-1e12;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			for (int k=i;k<=j;k++)
				ans[k][j-i+1]=max(ans[k][j-i+1],a[j]-a[i-1]);
		}
	}
	cin>>q;
	while (q--){
		int l,r; ull sum=0;
		cin>>l>>r;
		for (int i=1;i<=n;i++){
			ll mx=-1e12;
			for (int j=l;j<=r;j++)
				mx=max(mx,ans[i][j]);
			mx*=i;
			sum^=(1<<64)+mx;
		}
		cout<<sum<<'\n';
	}
}
