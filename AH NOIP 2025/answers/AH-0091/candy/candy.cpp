#include<bits/stdc++.h>
using namespace std;
struct ccc{
	long long x;
}cn[100009];
bool cmp(ccc x,ccc y){ return x.x<y.x; }
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m,t1,t2,mn,ans=0;  scanf("%lld%lld",&n,&m);
	scanf("%lld%lld",&t1,&t2);
	cn[0].x=t1,mn=t1+t2;
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&t1,&t2);  cn[i].x=t1;
		if(t1+t2<mn)  mn=t1+t2;
	}sort(cn,cn+n,cmp);
	for(int i=0;i<n;i++){
		if(m<mn&&m<cn[i].x)  break;
		if(cn[i].x+cn[i+1].x>=mn){
			ans+=2*(m/mn),m%=mn;
			if(m>=cn[i].x)  m-=cn[i].x,ans++;
		}else  m-=cn[i].x,ans++;
	}printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
