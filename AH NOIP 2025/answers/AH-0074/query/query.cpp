#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=5e4+5;
int c,t;
int n,q,l,r;
int a[N],s[N];
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	cin>>q;
	while(q--){
		cin>>l>>r;
		ull ans=0;
		for(int i=1;i<=n;i++){
			long long nmax=-1e10;
			for(int L=1;L+l-1<=n;L++){
				for(int R=L+l-1;R<=L+r-1&&R<=n;R++){
					if(!(L<=i&&i<=R))continue;
					nmax=max(nmax,s[R]-s[L-1]);
				}
			}
			ans^=((ull)nmax*(ull)i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
