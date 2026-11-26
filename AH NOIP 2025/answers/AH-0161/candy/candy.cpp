#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n;
long long m,mn=0x7fffffffffffffff;
struct C{
    long long x,y;
}a[N];
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(register int i=1;i<=n;i++){
         scanf("%lld%lld",&a[i].x,&a[i].y);
         mn=min(mn,a[i].x+a[i].y);
    }
    long long ans=m/mn*2,r=m%mn,res=0,cnt=0;
    sort(a+1,a+1+n,[](C x,C y){
         return x.x<y.x;
    });
    for(register int i=1;i<=n;i++){
        res+=a[i].x;
        if(res>m||a[i].x>mn)
            break;
        cnt++;
        ans=max(ans,(m-res)/mn*2+cnt);
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
