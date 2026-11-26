#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
struct sj{
	int x,y,sum,bj;
};
sj a[100005];
bool cmp(sj aaa,sj bbb){
	return aaa.x<bbb.x;
}
bool cmp2(sj aaa,sj bbb){
	int fa=aaa.x,fb=bbb.x;
	if(aaa.bj==1) fa=aaa.y;
	if(bbb.bj==1) fb=bbb.y;
	return fa<fb;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	int minsum=2000000000;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].sum=a[i].x+a[i].y;
		minsum=min(minsum,a[i].sum);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(2*a[i].x>minsum || m<a[i].x) break;
		m-=a[i].x;
		a[i].bj=1;
		ans++;
	}
	ans=ans+(m/minsum)*2;
	m=m%minsum;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		int ffa=a[i].x;
		if(a[i].bj==1) ffa=a[i].y;
		if(m<ffa) break;
		m-=ffa;
		ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
