#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,ans,lst;
struct p{
    int x,y;
}a[100005];
bool cmp1(p a,p b){
    return a.x+a.y<b.x+b.y;
}
bool cmp2(p a,p b){
    return a.x<b.x;
}
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+n+1,cmp1);
    c=a[1].x+a[1].y;
    sort(a+1,a+n+1,cmp2);
    for(int i=1;i<=n;i++){
        if(a[i].x*2<=c&&m>=a[i].x){
            m-=a[i].x;
            lst=a[i].x;
            ans++;
        }else break;
    }
    if((m+lst)/c>m/c)ans--,m+=lst;
    ans+=m/c*2;
    cout<<ans<<endl;
    return 0;
}
