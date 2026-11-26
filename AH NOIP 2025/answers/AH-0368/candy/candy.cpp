#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n; bool vis[N];
long long cnt=0,m,d[N],q[N];
struct node {long long x,y,d; int p;} c[N];
bool cmp1(node a,node b) {return a.d<b.d;}
bool cmp2(node a,node b) {return a.x<b.x;}
int main() {
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld %lld",&c[i].x,&c[i].y),c[i].d=c[i].x+c[i].y,c[i].p=i;
    sort(c+1,c+n+1,cmp1);
    long long minn=c[1].d,p=c[1].x,q=c[1].y;
    long long k=m/minn; m-=k*minn; long long maxn=k*2;
    long long cnt=k*2; bool flag=true;
    sort(c+1,c+n+1,cmp2);
    for(int i=1;i<=n;i++) {
	    if(m>=c[i].x) {cnt++,m-=c[i].x; maxn=max(maxn,cnt);continue;}
	    long long tmp=(c[i].x-m)/minn;
	    m+=tmp*minn,cnt-=tmp;
	    if(m<c[i].x) {
		    if(flag==true) cnt--,m+=q,flag=false;
		    else cnt--,m+=p,flag=true;
		}
		if(cnt<0) break;
		m-=c[i].x;
		cnt++; maxn=max(maxn,cnt);
	}
	cout<<maxn;
    return 0;
}
