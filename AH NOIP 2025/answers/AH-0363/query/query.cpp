#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+5,Mod=998242353;
int a[N],b[N],c[N],d[N],st[N][25],lg[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	int q;
	cin>>q;
	lg[0]=-1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i/2]+1;
	while(q--){
		for(int i=1;i<=n;i++)
			c[i]=-1e10;
		int l,r;
		cin>>l>>r;
		if(l==r){
			for(int i=1;i+l-1<=n;i++)
				st[i][0]=b[i+l-1]-b[i-1];
			for(int j=1;j<=lg[n];j++)
				for(int i=1;i+(1LL<<j)-1<=n;i++)
					st[i][j]=max(st[i][j-1],st[i+(1LL<<(j-1))][j-1]);
			for(int i=1;i<=n;i++){
				int L=max(1LL,i-l+1);
				int R=i;
				int k=lg[R-L+1];
				c[i]=max(st[L][k],st[R-(1<<k)+1][k]);
			}
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					int len=j-i+1;
					if(len<l||len>r)
						continue;
					cout<<i<<" "<<j<<" "<<b[j]-b[i-1]<<endl;
					for(int k=i;k<=j;k++)
						c[k]=max(c[k],b[j]-b[i-1]);
				}
			}
		}
		unsigned long long ans=0;
		for(int i=1;i<=n;i++)
			ans^=(unsigned long long)(c[i]*i);
		cout<<ans<<"\n";
	}
}
signed main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    while(t--)
		solve();
	return 0;
}
//分越少的部分分一般更好拿
//100+16+0+0=116
//没事，反正是来旅游的
