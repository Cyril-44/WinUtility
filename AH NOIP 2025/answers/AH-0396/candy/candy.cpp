#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,MAX=0x3f3f3f3f3f3f3f3f;
ll n,m,minn=MAX,ans,f;
struct node{
    ll x,y,s;
} a[N];
bool flag;
bool cmp1(node a,node b){
    return a.x<b.x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].s=a[i].x+a[i].y;
        minn=min(minn,a[i].s);
        if(a[i].x<a[i].y) flag=1;
    }
    if(!flag){
        ans=m/minn*2;
        m=m%minn;
        minn=MAX;
        for(int i=1;i<=n;i++) minn=min(minn,a[i].x);
        if(m>=minn) ans++;
        cout<<ans;
        return 0;
    }else{
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++){
            if(a[i].x*2<=minn){
                m-=a[i].x;
                ans++;
            }else{
                f=i;
                break;
            }
        }
 //       cout<<f<<' '<<minn<<"\n";
        ans+=m/minn*2;
        m=m%minn;
        for(int i=f;i<=n;i++){
            if(m>=a[i].x){
                ans++;
                m-=a[i].x;
            }else break;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}


















