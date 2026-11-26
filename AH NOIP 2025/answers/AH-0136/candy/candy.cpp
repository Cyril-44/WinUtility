#include<bits/stdc++.h>
#define ll long long
#define N 100010 
#define inf 10000000010
using namespace std;
ll n,m,x[N],y[N],minn1=inf,ans=0,t;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		minn1=min(minn1,x[i]+y[i]);
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		t=i;
		if(x[i]<minn1/2){
			m-=x[i],ans++;
		}
		else break;
	}
	ans+=(m/minn1)*2;
	m%=minn1;
	for(int i=t;i<=n&&m>0;i++){
		if(m>=x[i]) m-=x[i],ans++;
		else break;
	}
	cout<<ans;
	return 0;
}
