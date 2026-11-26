#include<bits/stdc++.h>
using namespace std;
#define For(i,j,k) for(int i=(j);i<=(k);i++)
typedef long long LL;
typedef unsigned long long ull;
const int M=200010;
//~ #define int long long
int q,n;
LL a[M],sum[M];
inline int read(){
	int ans=0,f=1;
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
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=read();
	For(i,1,n){
		a[i]=read();
		sum[i]=sum[i-1]+a[i];
	}
	q=read();
	while(q--){
		int l=read(),r=read();
		ull ans=0;
		For(i,1,n){
			LL m=-2e18;
			For(j,l,r){
				For(k,i-j+1,i+j-1){
					if(k<=0||k>n) continue; 
					m=max(m,sum[k+j-1]-sum[k-1]);
				}
			}
			//~ printf("%lld\n",m);
			ans=ans^((ull)i*(ull)m);
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
