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
const int N=1e5+5;
int n;
ll m,a[N],b[N];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	in(n),in(m);ll mn=1e18,ans=0;
	for(int i=1;i<=n;i++)in(a[i]),in(b[i]),mn=min(mn,a[i]+b[i]);
	stable_sort(a+1,a+n+1);
	ll res=(m/mn)*2ll;
	for(int i=1;i<=n&&m>=a[i];i++){
		m-=a[i],ans++,res=max(res,ans+(m/mn)*2ll);
	}
	cout<<res<<endl;
	return 0;
}