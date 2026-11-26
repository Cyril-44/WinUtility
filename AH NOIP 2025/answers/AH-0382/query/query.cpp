#include<bits/stdc++.h>
using namespace std;
const unsigned long long wlz=-1;
long long n,q,a[50005],s[50005],L,R;
unsigned long long mod(long long x){
	if(x>0) return x;
	else return x+wlz+1;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	cin>>q;
	while(q--){
		cin>>L>>R;
		unsigned long long ans=0;
		for(int i=1;i<=n;i++){
			long long res=-1e18;
			for(long long len=L;len<=R;len++){
				for(long long l=i-len+1;l<=i;l++){
					long long r=l+len-1;
					if(l<1||r>n) continue;
					res=max(res,s[r]-s[l-1]);
				}
			}
			ans^=mod(i*res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
