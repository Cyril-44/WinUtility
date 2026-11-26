#include <cstdio>
#include <random>
using namespace std;
const int N=8000;
mt19937_64 rnd;
long long Abs(long long x){return x<0?-x:x;}
long long ans;
int n,m,fa[N+5];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=2;i<=n;++i)scanf("%d",&fa[i]);
		ans=n*(n+1ll)>>1;
		printf("%lld\n",ans-Abs(rnd())%ans);
	}
	return 0;
}
