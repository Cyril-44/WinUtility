#include<bits/stdc++.h>
#define lol long long
//!noip@Nov29,2025:dream
using namespace std;
const int M=1e5+10;
int n;
lol m,a[10][M],mi=1e18,ans,sum,tot;
lol h[M],hd;
int main(){
	//检查freopen!!!!!!!!
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int i;
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i++){
		 scanf("%lld%lld",&a[1][i],&a[2][i]);
		 a[2][i]+=a[1][i];
		 mi=min(mi,a[2][i]);
	}
	for(i=1;i<=n;i++){
		if(a[1][i]>mi) continue;
		tot++;sum+=a[1][i];
		h[++hd]=a[1][i];
	}
	sort(h+1,h+hd+1);
	ans=tot+(lol)((m-sum)/mi)*2;
	for(i=hd;i>=1;i--){
		sum-=h[i],tot--;
		ans=max(ans,tot+(lol)((m-sum)/mi)*2);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
