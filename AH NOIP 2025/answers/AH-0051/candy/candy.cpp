#include<bits/stdc++.h>
#define up(i,l,r) for(int i=l,END##i=r;i<=END##i;i++)
#define dn(i,l,r) for(int i=l,END##i=r;i>=END##i;i--)
#define ve vector<i64>
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<i64,i64>
#define fi first
#define se second
#define great greater<int>
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
using namespace std;
const int INF=0x3f3f3f3f,N=1e5+7;
i64 n,m,s=1e18,ans;
pii a[N];
ve v;
bool f[N];
i64 mn1[N],mn2[N];
namespace sol{
	i64 read(){
		i64 f=0,x=0;
		char c=getchar();
		while(c<'0'||c>'9') f|=c=='-',c=getchar();
		while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
		return f?-x:x;
	}
	void write(i64 x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	void Dianaqwq(){
		n=read(),m=read();
		up(i,1,n) a[i].fi=read(),a[i].se=read();
		sort(a+1,a+n+1,[](pii x,pii y){
			return x.fi+x.se==y.fi+y.se?x.fi<y.fi:x.fi+x.se<y.fi+y.se;
		});
		i64 s=0,ss=a[1].se+a[1].fi,id=ss;
		sort(a+1,a+n+1);
		memset(mn2,63,sizeof mn2),memset(mn1,63,sizeof mn1);
		dn(i,n,1) mn2[i]=min(mn2[i+1],a[i].fi);
		up(i,1,n) mn1[i]=min(mn1[i-1],a[i].se);
		up(i,0,n){
			s+=a[i].fi;
			i64 m1=m-s,m2=m1%id,mn=min(mn1[i],mn2[i+1]);
			//cout<<s<<' '<<m1<<' '<<id<<'\n';
			ans=max(ans,i+(m1/id)*2+((m2)>=mn));
			//cout<<ans<<' ';
		}
		/*ans+=m/id*2,m%=(id);
		up(i,1,n) {
			i64 x=(f[i]?a[i].se:a[i].fi);
			if(m>=x) ans++,m-=x;
		}*/
		write(ans);
	}
}
using namespace sol;
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	Dianaqwq();
	return 0;
}
