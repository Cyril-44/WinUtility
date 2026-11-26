#include <bits/stdc++.h>
using namespace std;
#define maxn 200000+10
#define LL long long
LL n,m;
LL minn=-1;
int a[maxn];
int size=0;
LL ans=0;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		if(i==1) minn=x+y;
		minn=min(minn,x+y);
		if(x<minn) a[++size]=x;
	}
	sort(a+1,a+1+size);
	int h=1;
	while(h<=size && a[h]<=((minn-1)/2)){
		m-=a[h];
		h++;
		ans++;
	}
	ans+=(m/minn)*2;
	m%=minn;
	if(a[h]<=m){ans++;m-=a[h];}
	if(a[h-1]+m>=minn) ans++;
	printf("%lld",ans);
	return 0;
}
