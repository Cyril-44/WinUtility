#include<bits/stdc++.h>
using namespace std;
int b[100005],n,t;
long long minn=2000000007;
long long m,ans;
struct node{
	int num;
	int id;
}a[100005];
bool cmp(node x,node y){
	return x.num<y.num;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].num,&b[i]);
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		long long c=a[i].num+b[i];
		if(c<minn){
			minn=c;
			t=i;
		}
	}
	long long s=minn/2;
	long long sum=0;
	sort(a+1,a+n+1,cmp);
	int h=0;
	for(int i=1;i<=n;i++){
		if(a[i].num<=s){
			sum+=a[i].num;
			ans++;
		}
		if(a[i].num>s){
			h=i;
			break;
		}
	}
	if(sum>=m){
		long long sum2=0,ans2=0;
		for(int i=1;i<=n;i++){
		if(sum2+a[i].num<=m){
			sum+=a[i].num;
			ans2++;
		}
		else break;
		}
		printf("%lld",ans2);
	}
	if(sum<m){
		m-=sum;
	ans+=((m/minn)*2);
	m%=minn;
	if(h!=0&&a[h].num<=m){
		ans++;
		m-=a[h].num;
		h++;
	}
	if(h!=0&&h<=n&&a[h].num<=m){
		ans++;
	}
	}
	printf("%lld",ans);
	return 0;
}
