#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,t=2000000000;
struct st{
	long long x,y;
}a[100010];
bool cmp(st a,st b){
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		t=min(t,a[i].x+a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	a[n+1].x=2000000000;
	for(int i=1;i<=n;i++){
		if(m<min(a[i].x,t))break;
		if(a[i+1].x+a[i].x<=t)m-=a[i].x,ans++;
		else{
			if(a[i].x<t&&m<t)m-=a[i].x,ans++;
			else{
				ans+=(m-m%t)/t*2,m%=t;
				if(m>=a[i].x)m-=a[i].x,ans++;
			}
		}
	}
	if(m>=t)ans+=(m-m%t)/t*2;
	cout<<ans;
	return 0;
}
