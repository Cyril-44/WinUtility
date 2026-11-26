#include<bits/stdc++.h>
using namespace std;
#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define fi first
#define se second
typedef long long LL;
const int M=100010;
//~ #define int long long

pair<LL,LL> x[M];
int n,ti;
LL m,t;
LL ans=0;
int f=1;
inline LL read(){
	LL ans=0,f=1;
	char c=getchar_unlocked();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>=48&&c<=57){
		ans=ans*10+c-48;
		c=getchar_unlocked();
	}
	return ans*f;
}

signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n=read(),m=read();
	For(i,1,n) x[i]={read(),read()};
	sort(x+1,x+1+n);
	x[n+1]={2e18,2e18};
	t=2e18;
	For(i,1,n){
		if(t>x[i].fi+x[i].se){
			t=x[i].fi+x[i].se;
			ti=i;
		}
	}
	int ii=1;
	while( x[ii].fi+x[ii+1].fi<=t && x[ii].fi+x[ii].se<=m &&ii+1<=n){
		ans+=2;
		m-=(x[ii].fi+x[ii+1].fi);
		if(ii==ti||ii+1==ti) f=2;
		ii+=2;
	}
	ans+=(m/t)*2ll;
	m=m%t;
	if(f==1){
		if(m>=x[ii].fi+x[ti].fi) ans+=2;
		else if(m>=min(x[ii].fi,x[ti].fi) ) ans++;
	}
	else if(f==2){
		if(m>=x[ii].fi+x[ti].se) ans+=2;
		else if(m>=min(x[ii].fi,x[ti].se) ) ans++;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
