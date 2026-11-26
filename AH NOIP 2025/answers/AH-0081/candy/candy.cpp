#include<bits/stdc++.h>
using namespace std;
long long n,m,c,ans,a[100005],b[100005],t=0x3f3f3f3f3f3f3f3f;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&a[i],&b[i]);
		t=min(t,a[i]+b[i]);
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++){
		c=c+a[i];
		if(c>m)break;
		ans=max(ans,i+(m-c)/t*2);
	}
	cout<<ans;
	return 0;
}
