#include<bits/stdc++.h>
using namespace std;
long long n,m,x[100005],y,sum=2e18,cnt,ans;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y);
		sum=min(sum,x[i]+y);
	}
	sort(x+1,x+n+1);
	for(int i=0;i<=n;i++){
		cnt+=x[i];
		if(m<cnt) break;
		ans=max(ans,i+(m-cnt)/sum*2);
	}
	cout<<ans;
	return 0;
}
