#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define pii pair<int,int>
typedef long long ll;
typedef unsigned long long ull;
template <class Miaowu>
inline void in(Miaowu &x){
	char c;x=0;bool f=0;
	for(c=getchar();c<'0'||c>'9';c=getchar())f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=5e4+5;
int n,m;
ll a[N],pre[N];
vector<ll>add[3005],del[3005];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	in(n);
	for(int i=1;i<=n;i++)in(a[i]),pre[i]=pre[i-1]+a[i];
	in(m);while(m--){
		int l,r;in(l),in(r);
		ull ans=0;
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
			if(j-i+1>=l&&j-i+1<=r)add[i].push_back(pre[j]-pre[i-1]),del[j].push_back(pre[j]-pre[i-1]);
		}
		set<ll>S;
		for(int i=1;i<=n;i++){
			for(ll xx:add[i])S.insert(xx);
			ull x=(*--S.end()),y=i;
			ans^=(x*y);
			for(ll xx:del[i])S.erase(xx);
		}
		printf("%llu\n",ans);
	}
	return 0;
}