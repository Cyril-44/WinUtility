#include<bits/stdc++.h>
using namespace std;
struct node{
	vector<long long> v;
	long long id,maxn,f;
}a[8010];
long long T,n,m,x;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		for(long long i=0;i<=8000;i++) a[i].v.clear(),a[i].id=a[i].maxn=0;
		scanf("%lld %lld",&n,&m);
		for(long long i=2;i<=n;i++){
			scanf("%lld",&a[i].f);
			a[a[i].f].v.push_back(i);
		}
		for(long long i=n;i>=1;i--){
			if(a[i].f==1) a[i].id=a[i].v.size(),a[i].maxn=a[i].id+2;
			else{
				for(long long j=0;j<(long long)a[i].v.size();j++)
					a[i].id=max(a[i].id,a[a[i].v[j]].id);
				a[i].id++;a[i].maxn=a[i].id+1;
			}
		}
		printf("%lld\n",a[1].id+1);
	}
	return 0;
}
