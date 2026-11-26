#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int inf=2e9+10;
struct node{
    int a,b,sum,pos;
}t[N];
bool cmp1(node x,node y){
    if(x.a==y.a)return x.sum>y.sum;
    return x.a<y.a;
}
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int minn=inf,p=0,pa=0,pb=0;
    for(int i=1;i<=n;i++){
        cin>>t[i].a>>t[i].b;
        t[i].sum=t[i].a+t[i].b;
        t[i].pos=i;
        if(minn==t[i].sum&&t[i].a>pa){
            minn=t[i].sum;
            p=t[i].pos;
            pa=t[i].a;
            pb=t[i].b;
        }
        else if(minn>t[i].sum){
            minn=t[i].sum;
            p=t[i].pos;
            pa=t[i].a;
            pb=t[i].b;
        }
    }
    sort(t+1,t+1+n,cmp1);
    int ans=0;
    ans=ans+m/minn*2;
    m=m%minn;
    for(int i=1;i<=n;i++){
        if(pa<=t[i].a&&pb<=t[i].a)break;
        if(m>=t[i].a){
            m-=t[i].a;
            ans++;
        }
    }
    cout<<ans<<"\n";
    /*int n,m;
    cin>>n>>m;
    int minn=inf,p=0,pa=0,pb=0;
    for(int i=1;i<=n;i++){
        cin>>t[i].a>>t[i].b;
        t[i].sum=t[i].a+t[i].b;
        t[i].pos=i;
        if(minn==t[i].sum&&t[i].a>pa){
            minn=t[i].sum;
            p=t[i].pos;
            pa=t[i].a;
            pb=t[i].b;
        }
        else if(minn>t[i].sum){
            minn=t[i].sum;
            p=t[i].pos;
            pa=t[i].a;
            pb=t[i].b;
        }
    }
    sort(t+1,t+1+n,cmp1);
    for(int i=1;i<=20;i++){
        cout<<t[i].a<<"\n";
    }
    int ans=0;
    cout<<minn<<' '<<pa<<' '<<pb<<"\n";
    int pq;
    for(int i=1;i<=n;i++){
        if(pa<t[i].a)break;
        if(m>=t[i].a){
            m-=t[i].a;
            ans++;
            pq=i;
        }
    }
    cout<<ans<<"\n";
    ans=ans+m/minn*2;
    cout<<ans<<"\n";
    m=m%minn;
    for(int i=pq+1;i<=n;i++){
        if(pb>t[i].a&&m-t[i].a>=0){
            m-=t[i].a;
            ans++;
        }
        else if(pb<t[i].a&&m-pb>=0){
            m-=pb;
            pb=pa;
            ans++;
        }
    }
    cout<<ans<<"\n";*/
    return 0;
}
