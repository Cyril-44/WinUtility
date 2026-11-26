#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005],b[100005],c[100005],minn=10000000000,d[100005],zy=0,ans=0,pf=0,sc=10000000000;
int main(){
		ll n,m;
		freopen("candy.in","r",stdin);
		freopen("candy.out","w",stdout);
		
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			if(a[i]==b[i]) pf++;
			c[i]=b[i]+a[i];
		}
		if(pf==n){
			sort(c+1,c+n+1);
			c[1]/=2;
			ll k=m/c[1];
			cout<<k<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(c[i]<=minn){
				minn=c[i];
				if(sc>=a[i]) sc=a[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]==minn) d[i]++;
		}
		for(int i=1;i<=n;i++){
			if(a[i]*2<=minn && a[i]+b[i]!=minn){
				m-=a[i];
				if(a[i]>=zy) zy=a[i];
				ans++;
			}
		}
		while(m>=minn){
			ans+=2;
			m-=minn;
		}
		if(m+zy>=minn || sc<=m) ans++;
		cout<<ans<<endl;
		return 0;
}
