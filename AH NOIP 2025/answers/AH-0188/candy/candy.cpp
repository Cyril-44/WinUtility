#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, m1;
struct candy{
    long long a;
    long long b;
    long long c;
    long long j;
}s[100005];
bool cmp1(candy p, candy q){
	if(p.c==q.c)
	    return p.a<=q.a;
    return p.c<q.c;
}
bool cmp2(candy p, candy q){
	if(p.j==q.j)
	    return p.c<=q.c;
    return p.j<q.j;
}
int main(){
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(long long i=1; i<=n; i++){
        scanf("%lld %lld", &s[i].a, &s[i].b);
        s[i].c=s[i].a+s[i].b;
        s[i].j=s[i].a;
    }
    sort(s+1, s+n+1, cmp1);
    for(long long i=0; i<=(m/s[1].c)*2; i++){
		s[1].j=s[1].a;
		sort(s+1, s+n+1, cmp1);
		long long m1=m;
		long long ans1=0;
        ans1+=(m/s[1].c)*2-i;
	    m1=m%s[1].c;
	    if(i%2==1){
		    s[1].j=s[1].b;
		    m1+=s[1].b+s[1].c*(i/2);
		}
		else
		    m1+=s[1].c*(i/2);
	    sort(s+1, s+n+1, cmp2);
	    long long k=1;
	    while(m1>=s[k].j && k<=n){
	         ans1++;
	         m1-=s[k].j;
	         k++;
	    }
	    if(ans1>ans)
	        ans=ans1;
    }
	printf("%lld\n", ans);
    return 0;
}
