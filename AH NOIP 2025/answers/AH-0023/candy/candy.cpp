#include <cstdio>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;
const int N=100000;
int n,mn,cur;
pair<int,int>a[N+5];
long long m,ans,sum;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);mn=INT_MAX;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].first,&a[i].second);
		mn=min(mn,a[i].first+a[i].second);
	}
	sort(a+1,a+n+1);ans=m/mn*2;
	for(int i=1;i<=n;++i){
		sum+=a[i].first;
		if(m<sum)break;
		ans=max(ans,i+(m-sum)/mn*2);
	}
	printf("%lld\n",ans);
	return 0;
}

