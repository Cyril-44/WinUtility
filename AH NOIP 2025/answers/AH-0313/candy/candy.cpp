#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long mnab=0x3f3f3f3f3f3f3f3f,a[100005];
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		long long u,v; cin>>u>>v;
		mnab=min(mnab,u+v);
		a[i]=u;
	}
	sort(a+1,a+1+n);
	long long ans=0,sum=0;
	ans=max(ans,(m-sum)/mnab*2);
	for(long long i=1;i<=n;i++){
		sum+=a[i];
		if(sum>m) break;
		ans=max(ans,(m-sum)/mnab*2+i);
	}
	cout<<ans;
	return 0;
}