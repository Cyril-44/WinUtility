#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=100005;
struct candy{
    ll pa,pb,id;
}a[N];
ll n,m,ans,c[N],f[N],last;

bool cmp(candy x,candy y){
    if(x.pa==y.pa)
        return x.pb<y.pb;
    return x.pa<y.pa;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].pa>>a[i].pb;
        c[i]=a[i].pa+a[i].pb;
    }
    sort(c+1,c+n+1);
    sort(a+1,a+n+1,cmp);
    int i=1;
    for(i=1;i<=n;i++){
        if(f[i]==0){
            if((a[i].pa)*2<c[1] && m>=a[i].pa){
                m-=a[i].pa;
                ans++;
                f[i]=1;
                last=i;
            }
        }
    }
    ans+=(m/c[1])*2;
    m%=c[1];
    for(int i=1;i<=n;i++)
        if(f[i]==1)
            f[i]=a[i].pb;
        else
            f[i]=a[i].pa;
    sort(f+1,f+n+1);
    if(a[last].pa+m>=c[1]){
        m+=a[last].pa;
        ans--;
        ans+=2;
        m-=c[1];
    }
    for(int i=1;i<=n;i++)
        if(m>=f[i]){
            m-=f[i];
            ans++;
        }
    cout<<ans;
    return 0;
}
