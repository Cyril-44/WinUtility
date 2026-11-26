#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int x[100010],y,tmi;
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	tmi=20000000000;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y;
		tmi=min(tmi,x[i]+y);
	}
	sort(x+1,x+n+1);
	int ans=0;
	for(int i=0;i<=n;i++){
		m-=x[i];
		if(m<0)break;
		ans=max(ans,i+(m/tmi)*2);
	}
	cout<<ans;
	return 0;
}
