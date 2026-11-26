#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll a,b,sum;
}p[100001];
ll m;
ll Now[100001]={0};
ll ans=0,minsum=1e18;
bool cmp(node x,node y){
    return x.a<y.a;
}
int n;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i].a>>p[i].b;
        p[i].sum=p[i].a+p[i].b;
        minsum=min(minsum,p[i].sum);
    }
    ans+=(m/minsum)*2;
    m%=minsum;
    sort(p+1,p+n+1,cmp);
    for(ll i=1;i<=n;i++){
        if(m-p[i].a<0){
            break;
        }
        m-=p[i].a;
        swap(p[i].a,p[i].b);
        ans++;
    }
    ll t=m,cnt=0;
    while(true){
        sort(p+1,p+n+1,cmp);
        cnt=0;
        t+=minsum;
        for(cnt=0;cnt<=n;cnt++){
            if(t-p[cnt].a<0){
                cnt--;
                break;
            }
            t-=p[cnt].a;
        }
        if(cnt>=2){
            ans-=2;
            ans+=cnt;
            for(int i=1;i<=cnt;i++){
                swap(p[i].a,p[i].b);
            }
        }
        else break;
    }

    cout<<ans;
    return 0;
}



