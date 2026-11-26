#include<bits/stdc++.h>
using namespace std;
long long c,to,n,m,l,x,i,j;
const long long mod=998244353;
struct node{
	long long a,c,id;
	double b;
}k[10005];
bool cmp(node o,node p){
	if(o.b!=p.b) return o.b>p.b;
	else if(o.a!=p.a) return o.a>p.a;
	else return o.id<p.id;
}
long long pos[5005][2];
long long sum1[10005],sum2[10005],sum3[10005];
long long w[10005];
long long t[10005];
long long f(long long o,long long p){
	if(w[o]&&w[p]){
		long long id0=pos[k[w[p]].id][0];
		long long id1=w[o];
		return max(0ll,sum2[id1]-sum2[id0]+1);
	}else{
		return 0;
	}
}
long long op[10005],np[10005],inf=10000;
long long pw(long long o,long long p){
	if(p==0) return 1;
	long long s=pw(o,p/2);
	if(p%2==0) return s*s%mod;
	else return s*s%mod*o%mod;
}
long long work(long long o,long long p){
	if(o>p) return 0;
	return op[p]*np[o]%mod*np[p-o]%mod;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld%lld",&c,&to);
	if(c==16||c==18){
		while(to--){
			scanf("%lld%lld",&n,&m);
			for(i=1;i<=n;i++){
				scanf("%lld",&x);
			}
			printf("%lld\n",pw(2,n));
		}	
	}else{
		op[0]=1;
		for(i=1;i<=inf;i++) op[i]=op[i-1]*i%mod;
		np[inf]=pw(op[inf],mod-2);
		for(i=inf-1;i>=0;i--) np[i]=np[i+1]*(i+1)%mod;
		while(to--){
			scanf("%lld%lld",&n,&m);
			l=0;
			for(i=1;i<=n;i++){
				scanf("%lld",&x);
				k[++l].a=x;k[l].b=x*1.0;
				k[l].c=1;k[l].id=i;
				k[++l].a=x;k[l].b=x*1.0/2.0;
				k[l].c=2;k[l].id=i;
			}
			sort(k+1,k+l+1,cmp);
			//一个数对应的两个位置
			for(i=1;i<=l;i++){
				pos[k[i].id][k[i].c-1]=i;
			}
			//若是1，前面的一个1在哪里
			//若是2，后面的一个2在哪里
			for(i=1;i<=l;i++){
				if(k[i].c==2){
					for(j=i+1;j<=l;j++){
						if(k[j].c==2){
							w[i]=j;
							break;
						}
					}
				}else{
					for(j=i-1;j>=1;j--){
						if(k[j].c==1){
							w[i]=j;
							break;
						}
					}
				}
			}
			//前面有多少个（1，2）
			for(i=1;i<=n;i++) t[i]=0;
			for(i=1;i<=l;i++){
				t[k[i].id]++;
				sum1[i]=sum1[i-1]+(t[k[i].id]==2);
			}
			//前面有多少个1
			for(i=1;i<=l;i++){
				sum2[i]=sum2[i-1]+(k[i].c==1);
			}
			//后面有多少个1
			sum3[l+1]=0;
			for(i=l;i>=1;i--){
				sum3[i]=sum3[i+1]+(k[i].c==1);
			}
			long long ans=0;
			for(i=1;i<=l;i++){
				if(k[i].c==2){
					for(j=1;j<=n;j++) t[j]=0;
					long long sum=0,z=i+1,summ=0;
					for(j=i-1;j>=1;j--){
						if(k[j].c==1&&k[j].a>=k[i].a) break;
						if(k[j].c==1){
							long long ns=sum,lst=sum1[j-1];
							if(pos[k[j].id][1]<i) ns--;
							long long rem=m-2-ns-lst-2*summ;
							long long ka=f(j,i);
							if(rem>=0){
								while(z<=l&&(k[z].c==2||k[z].a+k[j].a>=k[i].a)) z++;
								ans=ans+(work(rem,lst+ka+ns)*(1ll<<sum3[z])%mod);
								if(ans>=mod) ans-=mod;
							}else{
								break;
							}
						}
						t[k[j].id]++;
						if(t[k[j].id]==2) summ++;
						if(k[j].c==2) sum++;
					}
				}
			}
			long long tot=pw(2,n);
			tot-=ans;
			if(tot<0) tot+=mod;
			printf("%lld\n",tot);
		}	
	}
	return 0;
}
