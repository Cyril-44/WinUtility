#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+5;
const int inf=1e18;
const unsigned long long _1=1;
int n,q,a[N],L,R,w[N],s[N],A[N];
unordered_map<int,int>p;
set<int>X;
void sub1(){
	p.clear();X.clear();
	int sum=0;
	for(int i=1;i<=L;i++)sum+=a[i];
	p[sum]++;X.insert(sum);
	A[1]=*X.rbegin();s[1]=sum;
	for(int i=2;i<=L&&i+L-1<=n;i++){
		sum-=a[i-1];sum+=a[i+L-1];
		p[sum]++;if(p.count(sum)==1)X.insert(sum);
		A[i]=*X.rbegin();s[i]=sum;
	}
	for(int i=L+1;i+L-1<=n;i++){
		sum-=a[i-1];sum+=a[i+L-1];
		p[sum]++;if(p.count(sum)==1)X.insert(sum);
		if(--p[s[i-L]]==0)X.erase(s[i-L]);
		A[i]=*X.rbegin();s[i]=sum;
	}
	for(int i=n-L+2;i<=n;i++){
		if(--p[s[i-L]]==0)X.erase(s[i-L]);
		A[i]=*X.rbegin();
	}
	unsigned long long ans=0;
	for(int i=1;i<=n;i++)ans^=_1*A[i]*i;
	printf("%llu\n",ans);
}
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	while(q--){
		scanf("%lld %lld",&L,&R);
		if(L==R){
			sub1();
			continue;
		}

	}
	return 0;
}