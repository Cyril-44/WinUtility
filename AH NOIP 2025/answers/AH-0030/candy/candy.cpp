#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long m,pm,ans,a[100005],b[100005];
int work(int ma){
	int tmp=0,k=0,i=1;
	while(i<=n) {
		if(tmp+a[i]<=ma) {
			tmp+=a[i];
			i++;
			k++;
		}
		else break;
	}
	if(tmp<=ma) {
		i=1;
		while(i<=n) {
			if(tmp+b[i]<=ma) {
				tmp+=b[i];
				i++;
				k++;
			}
			else break;
		}
	}
	return k;
}
void judge(){
	int k1=work(m),k2=work(m+pm*2);
	ans+=max(k1,k2-2);
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	m*=2;
	pm=1000000000000;
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld",a+i,b+i);
		a[i]*=2;
		b[i]*=2;
		long long p=(a[i]+b[i])/2;
		pm=min(pm,p);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	ans=m/pm;
	m-=pm*ans;
	if(ans%2==1) {ans--;m+=pm;}
	judge();
	printf("%lld",ans);
	return 0;
}
