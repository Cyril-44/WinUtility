#include<bits/stdc++.h>
#define ll long long
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

const int MAXN=5000+10,MOD=998244353;

int c,T,n,m,rnk[MAXN],a[MAXN],pw[MAXN],C[MAXN][MAXN],st[MAXN];

int main() {
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	ffor(i,0,5000) {
		if(i) pw[i]=(pw[i-1]+pw[i-1])%MOD;
		else pw[i]=1;
		C[i][0]=1;
		ffor(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	while(T--) {
		cin>>n>>m;
		ffor(i,1,n) cin>>a[i],st[i]=a[i];
		sort(st+1,st+n+1);
		ll res=0;
		vector<pair<int,int>> vc;
		ffor(i,1,n) vc.push_back({-a[i],i});
		sort(vc.begin(),vc.end());
		ffor(i,1,n) rnk[vc[i-1].second]=i;
		reverse(vc.begin(),vc.end());
		ffor(i,1,n) {
			int lst=0;
			for(auto pr:vc) {
				int j=pr.second;
				if(i!=j&&2*a[i]>a[j]&&a[j]>a[i]) {
					while(st[lst+1]<=a[j]-a[i]-1) lst++;
					int x1=rnk[j]-1,x3=rnk[i]-rnk[j]-1,x5=lst;
					ll mul=pw[x5];
					if(x1<=m-2&&x1+x3>=m-2-x1) mul=mul*C[x1+x3][m-2-x1];
					else mul=0;
					res=(res-mul)%MOD;
				}
			}
		}
		res=(res+pw[n])%MOD;
		cout<<(res%MOD+MOD)%MOD<<'\n';
	}
	return 0;
}
