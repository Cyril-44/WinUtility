#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2;i -= s3)
#define INF 0x7f7f7f7f
#define ll long long
using namespace std;
ll n,m,sum = 0,minn = INF,ans,a[100010];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	ll i,y;
	rep(i,1,n,1){
		cin>>a[i]>>y;
		minn = min(minn,a[i] + y);
	}
	sort(a + 1,a + n + 1);
	ans = m / minn * 2;
	rep(i,1,n,1){
		if(sum + a[i] > m) break;
		sum += a[i];
		ans = max(ans,i + (m - sum) / minn * 2);
	}
	ans = max(ans,i - 1);
	cout<<ans;
	return 0;
}
