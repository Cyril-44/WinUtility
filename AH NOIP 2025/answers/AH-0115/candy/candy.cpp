#include<bits/stdc++.h>
using namespace std;
int n,x[100005],y[100005];
long long m,ans,sum;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		y[i]=x[i]+y[i];
	}
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	for(int i=0;i<=n;i++){
		sum+=x[i];
		ans=max((m-sum)/y[1]*2+i,ans);
	}
	printf("%lld",ans);
}
