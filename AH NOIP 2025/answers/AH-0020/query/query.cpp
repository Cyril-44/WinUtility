#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll2;
typedef long long ll1;
const ll1 inf=1e16;
const int N=5e4+5;
ll1 a[N];
int n,q,Log2[N];
ll2 Ans=0;
ll1 ans[N];
//要求做到 nqlog，我不会做，无敌了。
int Lt[N],Rt[N];
namespace ST{
	ll1 mn[16][N];
	void build(){
		for(int i=1;i<=n;i++)mn[0][i]=a[i-1];
		for(int i=2;i<=n;i++){
			Log2[i]=Log2[i-1];
			if((1<<(Log2[i]+1))==i)Log2[i]++;
		}
		for(int k=1;(1<<k)<=n;k++)
		for(int i=1;i+(1<<k)-1<=n;i++)
			mn[k][i]=min(mn[k-1][i],mn[k-1][i+(1<<(k-1))]);
	}
	ll1 qrymn(int l,int r){
		if(l>r)return inf;
		int k=Log2[r-l+1];
		return min(mn[k][l],mn[k][r-(1<<k)+1]);
	}
}
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=a[i-1];
	ST::build();
	scanf("%d",&q);
	for(int i=1;i<=n;i++)scanf("%d%d",&Lt[i],&Rt[i]);
}
void work(){
	for(int id=1;id<=q;id++){
		Ans=0;
		for(int i=1;i<=n;i++){
			ans[i]=-inf;
			for(int r=i;r<=n&&r-i+1<=Rt[id];r++){
				int lt=max(1,r-Rt[id]+1),rt=min(i,r-Lt[id]+1);
				ans[i]=max(ans[i],a[r]-ST::qrymn(lt,rt));
			}
			ll2 tmp=ans[i],ti=i;
			Ans^=tmp*ti;
		}
		printf("%llu\n",Ans);
	}
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	init();
	work();
	return 0;
}