#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int o[N];
int ST[N][20],sum[N],a[N];
int que(int l,int r){
	return max(ST[r][o[r-l+1]],ST[l+(1<<o[r-l+1])][o[r-l+1]]);
}
int main(){
freopen("query.in","r",stdin);
freopen("query.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		o[i]=o[i>>1]+1;
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ST[i][0]=sum[i];
		for(int j=1;(1<<j)<=i;j++){
			ST[i][j]=max(ST[i][j-1],ST[i-(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=q;i++){
		int L,R;
		int Ans=0;
		cin>>L>>R;
		for(int j=1;j<=n;j++){
			int ans=-1e9;
			for(int l=j;l>=1;l--){
				int rl=max(j,l+L-1),rr=j+R-1;
				if(rl>rr)continue;
				ans=max(ans,-sum[l-1]+que(rl,rr));
			}
			Ans^=(1LL*ans*i);
		}
		cout<<Ans<<endl;
	}
	return 0;
}
