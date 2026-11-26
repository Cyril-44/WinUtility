#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
const int N=5e4+10,INF=0x3f3f3f3f;
int n,q;
int a[N],s[N];
#define ULL unsigned long long
int f[N][33];
ULL v[N];
signed main(){
	ios::sync_with_stdio(0);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	forr(i,1,n)cin>>a[i],s[i]=s[i-1]+a[i];
	cin>>q;
	forr(i,1,n)forr(j,1,32)f[i][j]=-INF;
	forr(i,1,32){
		forr(j,1,n-i+1){
			int ss=s[i+j-1]-s[j-1];
			forr(k,j,j+i-1)f[k][i]=max(f[k][i],ss);
		}
	}
	forr(i,1,q){
		int l,r;cin>>l>>r;
		forr(k,1,n){int mx=-INF;
			forr(j,l,r){
				mx=max(mx,f[k][j]);
			}
			v[k]=1ull*mx*k;
		}
		forr(k,1,n)v[k]^=v[k-1];
		cout<<v[n]<<endl;
	}
	return 0;
}
