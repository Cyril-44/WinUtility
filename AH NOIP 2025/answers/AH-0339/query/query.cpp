#include<bits/stdc++.h>
using namespace std;
int st[50005][30];
int a[50005];
unsigned ans=0;
long long s[50005];
int n,q;
int loggg[50005];
void init(){
	for(int i=2;i<=n;i++)loggg[i]=loggg[i>>1]+1;
	for(int i=1;i<=n;i++)st[i][0]=s[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int x,int y){
	int k=loggg[y-x+1],s=1<<k;
	return max(st[x][k],st[y-s+1][k]);
}
unsigned long long getyu(long long x){
	if(x>=0)return x;
	return getyu((1ll<<63)+x);
}
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	cin>>q;
	init();
	while(q--){
		int l,r;
		cin>>l>>r;
		ans=0;
		long long maxx=-10000000000000000;
		for(int i=1;i<=n;i++){
			for(int j=max(1,i-l+1);j<=i;j++){
				maxx=max(maxx,query(j+l-1,min(n,j+r-1))-s[j-1]);
			}
			ans^=maxx*i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
