#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1E5+5;
int n,m,p,ans,costnow,cur;
struct Node{
    int x,y,sum;
}a[N];
bool cmp(const Node &x,const Node &y){
    return x.sum<y.sum;
}
bool cmp2(const Node &x,const Node &y){
    return x.x<y.x;
}
inline int check(int p,int costnow){
    int sum=0;
    for(;p<=n;p++){
        if(a[p].x<=m-costnow){
            sum++;
            costnow+=a[p].x;
        }else{
            break;
        }
    }
    return sum;
}
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].sum=a[i].x+a[i].y;
    }
    sort(a+1,a+n+1,cmp);
    cur=a[1].x+a[1].y;
    ans=m/cur*2;
    costnow=ans/2*cur;
    sort(a+2,a+n+1,cmp2);
    for(p=2;p<=n;p++){
        if(a[p].x<=m-costnow){
            ans++;
            costnow+=a[p].x;
        }else{
            break;
        }
    }
    int flag=0,cnt1=0,cnt2=0;
    for(;p<=n;p++){
        if(cnt1+a[p].x<=a[1].y){
            cnt1+=a[p].x;
            cnt2++;
            flag=1;
        }else break;
    }
    if(flag){
        costnow=costnow-a[1].y+cnt1;
        ans=ans-flag+cnt2;
    }
    int lans=ans;
    for(;p+1<=n;p+=2){
        if(a[p].x+a[p+1].x>cur) break;
        int pos=costnow-cur+a[p].x+a[p+1].x;
        int value=check(p+1,pos);
        ans=max(lans+value,ans);
        costnow=pos;
    }
    printf("%lld",ans);

    return 0;
}
