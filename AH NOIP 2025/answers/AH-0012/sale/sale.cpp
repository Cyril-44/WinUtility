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
const int N=5e3+5;
const int mod=998244353;
int cas,T,n,m,a[N],C[N][N],P2[N];
inline int add(int x,int y){
	return (x+y>=mod?x+y-mod:x+y);
}
inline void Add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	for(int i=C[0][0]=1;i<N;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
		}
	}
	for(int i=P2[0]=1;i<N;i++){
		P2[i]=add(P2[i-1],P2[i-1]);
	}
	for(cin>>cas>>T;T;T--){
		in(n),in(m);
		for(int i=1;i<=n;i++)in(a[i]);
		stable_sort(a+1,a+n+1,greater<int>());
		int ans=0;
		for(int i=1,jm=2;i<=n;i++){
			while(jm<=n&&a[jm]>(a[i]>>1))jm++;
			int nw=jm-1;
			for(int j=jm-1;j>i&&a[i]>a[j];j--){
				while(nw<n&&a[nw+1]+a[j]>=a[i])nw++;
				if(j-2>=m-i-1&&j>=2&&m>=i-1)Add(ans,1ll*C[j-2][m-i-1]*P2[n-nw]%mod);
			}
		}
		printf("%d\n",add(P2[n],mod-ans));
	}
	return 0;
}