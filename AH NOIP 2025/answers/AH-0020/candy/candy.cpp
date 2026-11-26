#include "bits/stdc++.h"
using namespace std;
typedef long long ll1;
const int N=2e5+5;
//给定你 2n 种糖果，前 n 种最多买一颗，
//后 n 种无限购物
//问最大权值和
//枚举前 n 种买了 k 个，即前 k 大和
//很容易计算得到后 n 种，因为我们只买最小的
ll1 a[N],b[N];
int n;ll1 m,Ans=0;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		b[i]+=a[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	ll1 sm=0;
	for(ll1 k=0;k<=n&&sm<=m;sm+=a[++k]){
		ll1 res=((m-sm)/b[1]);
		res=res*2ll+k;
		Ans=max(Ans,res);
	}
	printf("%lld\n",Ans);
	return 0;
}