#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,num,sum,qes;
struct node{
    ll x,y,ans;
}a[1*100005];
struct tre{
    ll chh;
    int kon;
}tree[1*100005];
int check[1*100005];
bool cmp(node p,node q){
    return p.ans<q.ans;
}
bool cmp1(tre p,tre q){
    return p.chh<q.chh;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(n==1){
        scanf("%lld%lld",&a[1].x,&a[1].y);
        a[1].ans=a[1].x+a[1].y;
        num=m/a[1].ans;
        sum+=a[1].ans*num;
        qes+=num*2;
        m-=sum;
        if(m>=a[1].x)
            printf("%lld",qes+1);
        return 0;
    }
    for(int i=1;i<=n;++i){
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].ans=a[i].x+a[i].y;
        tree[i].chh=a[i].x;
        tree[i].kon=i;
    }
    sort(a+1,a+n+1,cmp);
    num=m/a[1].ans;
    qes+=num*2;
    m-=num*a[1].ans;
    sort(tree+1,tree+n+1,cmp1);
    for(int i=1;i<=n;++i){
		if(tree[i].chh>m){
			printf("%lld",qes);
			return 0;
		}
		m-=tree[i].chh;
		qes++;
	}
    printf("%lld",qes);
    return 0;
}
