#include<bits/stdc++.h>
#define _ 100005
using namespace std;
struct candy{
    int id;long long x,p,y,s;
    void input(int i){scanf("%lld%lld",&x,&y);p=x;s=x+y;id=i;}
}a[_],b;
bool cmp(candy x,candy y){
    if(x.s!=y.s)return x.s<y.s;
    return x.x<y.x;
}
bool cmp0(candy x,candy y){
    if(x.x!=y.x)return x.x<y.x;
    return x.s<y.s;
}
long long m,val,sum=0,ans,n,k,t,v=1,p;bool flag=0;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){a[i].input(i);}
    sort(a+1,a+n+1,cmp);b=a[1];
    sort(a+1,a+n+1,cmp0);a[0].x=0;
    for(;t+a[v].x<=m;t+=a[v].x,v++){
        sum+=a[v].x;if(a[v].id==k)flag=1;
    }
    ans=--v;
    for(int i=v;i>=0;i--){
        p=i;val=sum;
        if(flag&&sum+b.y<=m){
            val+=b.y;p++;
        }
        int cnt=(m-val)/b.s;
        val+=b.s*cnt;p+=cnt*2;
        if(val+b.x<=m){
            val+=b.x;p++;
        }
        ans=max(ans,p);sum-=a[i].x;
        if(a[i].id==k)flag=0;
    }
    printf("%lld",ans);
    return 0;
}
