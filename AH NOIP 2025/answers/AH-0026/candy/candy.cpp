#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
inline ll read(){
	ll a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
ll n,m;
struct node{
	ll x,y;
}a[N];
ll b[N];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n=read(),m=read();
	ll minn=INT_MAX;
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
		minn=min(minn,a[i].x+a[i].y);
		b[i]=a[i].x;
	}
	sort(b+1,b+1+n);
	ll ans=0;
	for(int i=0;i<=n;i++){
		if(i>=1)
			b[i]+=b[i-1];
		if(m<b[i])break;
		ans=max(ans,i+((m-b[i])/minn)*2);
	}
	printf("%lld\n",ans);
	return 0;
}