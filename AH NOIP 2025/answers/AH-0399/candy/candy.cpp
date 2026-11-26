#include <bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,op;
}s[100005];
bool cmp(node p,node q){
	if (p.x==q.x)
		return p.y<q.y;
	return p.x<q.x;
}
long long n,m,sum=1e15,mn=1e15,ans,fx;
int main(){
	freopen ("candy.in","r",stdin);
	freopen ("candy.out","w",stdout);
	scanf ("%lld%lld",&n,&m);
	for (long long i=1;i<=n;i++){
		scanf ("%lld%lld",&s[i].x,&s[i].y);
		if ((s[i].x+s[i].y)<sum)
			sum=s[i].x+s[i].y;
	}
	sort(s+1,s+n+1,cmp);
	for (long long i=1;i<=n;i++){
		if ((s[i].x*2)<sum&&s[i].x<=m)
			m-=s[i].x,ans++,s[i].op=1;
	}
	if (sum<=m){
		fx=m/sum;
		m-=fx*sum;
		ans+=fx*2;
	}
	long long i=1;
	while (m){
		if (s[i].x>m)
			break;
		if (s[i].op==0){
			m-=s[i].x;
			ans++;
		}
		i++;
	}
	printf ("%lld",ans);
	return 0;
}
