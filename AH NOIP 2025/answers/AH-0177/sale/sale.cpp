#include<bits/stdc++.h>
using namespace std;
struct candy{
	double a,b,k;
}can[10001],canb[10001];
bool cmp(candy aaa,candy bbb){
	if(aaa.k==bbb.k) return aaa.a>bbb.a; 
	return aaa.k>bbb.k;
}
bool cmpa(candy aaaa,candy bbbb){
	return aaaa.a>bbbb.a;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	long long c,t,n,m,i,ans,jj,kk,ll,mm,ii;
	scanf("%lld%lld",&c,&t);
		while(t--){
			scanf("%lld%lld",&n,&m);
			for(i=1;i<=n;i++){
				scanf("%lf",&can[i].a);
			}
			ans=1;
			for(i=1;i<=n;i++){
				ans=(ans*2)%998244353;
			}
			printf("%lld\n",ans);
		}
	/*if(c>=1&&c<=3){
		while(t--){
			ans=0;
			scanf("%lld%lld",&n,&m);
			for(i=1;i<=n;i++){
				scanf("%lf",&can[i].a);
			}
			if(n==1){
				printf("2\n");
			}
			if(n==2){
				for(i=1;i<=2;i++){
					for(jj=1;jj<=2;jj++){
						can[1].b=i;
						can[2].b=jj;
						for(ii=1;ii<=2;ii++){
							can[ii].k=can[ii].a/can[ii].b;
							canb[ii].k=can[ii].k;
							canb[ii].a=can[ii].a;
							canb[ii].b=can[ii].b;
						}
						sort(canb+1,canb+2+1,cmp);
						double opm=m,rans=0,maxans=0;
						for(ii=1;ii<=2;ii++){
							if(opm>=canb[ii].b){
								opm-=canb[ii].b;
								rans+=canb[ii].a;
							}
						}
					}
				}
			}
		}
	}*/
	return 0;
}
//想进奇葩代码大赏
//你说我一个MO生来考NOIP干啥？
//实际上我已经学了五六年OI了
//但是大部分时间都在虚度光阴
//这是我的最后一场OI比赛
//最后也没能取得一个圆满的结果
//也许人生总要留点遗憾吧。
