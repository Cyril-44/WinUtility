#include<bits/stdc++.h>
#define up(i,l,r) for(int i=l,END##i=r;i<=END##i;i++)
#define dn(i,l,r) for(int i=l,END##i=r;i>=END##i;i--)
#define ve vector<int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define great greater<int>
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
using namespace std;
const int INF=0x3f3f3f3f,N=5e4+7;
int n,a[N],q;
i64 pre[N];
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
		//cout<<(sizeof(f)/1024.0/1024.0);
		n=read();
		up(i,1,n) a[i]=read(),pre[i]=pre[i-1]+a[i];
		q=read();
		while(q--){
			int l=read(),r=read();
			u64 ans=0;
			up(i,1,n){
				i64 s=-INF;
				up(L,1,i) up(R,max(i,L+l-1),min(n,r+L-1)){
					if(R-L+1>=l&&R-L+1<=r) s=max(s,pre[R]-pre[L-1]);
				} 
				u64 o=i*s;
				ans^=o;
			}
			
			cout<<ans,puts("");;
		}
	}
}
using namespace sol;
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	Dianaqwq();
	return 0;
}
