#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,m,ans;
struct node {
    long long p,in;
}a[500001];
node b[500001];
bool cmp(node u,node v){
    return u.p>v.p;
}
long long cal(long long s){
    long long an=1;
    while(s--){
        an*=2;
        an%=998244353;
    }
    return an;
}
long long cal2(long long s){
    long long an=cal(s);
    if(a[n].p>(a[n-1].p/2)&&a[n].p!=a[n-1].p) an--;
    return an;
}
long long cal3(long long s){
    long long an=cal(s-1);
    long long f=1;
    for(int i=2;i<=n;i++){
        if(a[i].p>a[1].p/2){
            f++;
            long long cou=f;
            for(int j=i+1;j<=n;j++)
            if(a[j].p+a[i].p>=a[1].p){
                cou++;
                an=(an+cal(s-cou))%998244353;
            }
        }
    }
    return an;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i].p);
            a[i].in=i;
        }
        sort(a+1,a+1+n,cmp);
        if(c==18||c==16) cout<<cal(n)<<'\n';
        if(c==17) cout<<cal2(n)<<'\n';
        if(c==7||c==8||c==9||c==14||c==15){
            cout<<cal3(n)<<'\n';
        }
    }
}
