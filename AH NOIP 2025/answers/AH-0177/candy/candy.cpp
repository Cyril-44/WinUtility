#include<bits/stdc++.h>
using namespace std;
struct candy{
	long long a,b,c;
	bool mi;
}k[100001];
bool cmp(candy aa,candy bb){
	if(aa.c==bb.c) return aa.a<bb.a;
	return aa.c<bb.c;
}
bool cmp2(candy aaa,candy bbb){
	return aaa.a<bbb.a;
}
long long n,m,i,op,maxans=-1,opb,kkm,nowans,mina;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&k[i].a,&k[i].b);
		k[i].mi=0;
	}
	for(i=1;i<=n;i++){
		k[i].c=k[i].a+k[i].b;
	}
	sort(k+1,k+n+1,cmp);
	k[1].mi=1;
	op=k[1].c;
	maxans=m/op*2;
	kkm=m;
	mina=k[1].a;
	if(m%op>=k[1].a) maxans++;
	sort(k+1,k+n+1,cmp2);
	for(i=1;i<=n;i++){
		nowans=0;
		if(k[i].mi==0){
			if(kkm>=k[i].a) {
				opb++;
				kkm-=k[i].a;
			}
			nowans=kkm/op*2;
			if(kkm%op>=mina) nowans++;
			nowans+=opb;
			maxans=max(maxans,nowans);
		}
	}
	printf("%lld",maxans);
	return 0;
}
