#include<bits/stdc++.h>
using namespace std;
const long long N=5e4+10;
long long n,q,a[N],l,r,s[N],k[N];
unsigned long long x,ans;
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	cin>>q;
	while(q--){
		ans=0;
		cin>>l>>r;
		for(long long i=1;i<=n;i++){
			k[i]=INT_MIN;
			for(long long len=l;len<=r;len++){
				for(long long p=max(1ll,i-len+1);p<=min(n,i+len-1);p++){
					k[i]=max(k[i],s[p+len-1]-s[p-1]);
				}
			}
			x=k[i];
			x=x*i;
			ans^=x;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
