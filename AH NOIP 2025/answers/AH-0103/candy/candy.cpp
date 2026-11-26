#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Candy{
    int sum,a,b;
//  bool f;
//  Candy(){f=0;}
    bool operator<(const Candy &x)const{
        if(this->a==x.a)
            return this->b<x.b;
        return this->a<x.a;
    }
}a[100005];
int n,m,choice=0x7fffffffffffffff,ans;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b;
        a[i].sum=a[i].a+a[i].b;
        choice=min(choice,a[i].sum);
    }
    sort(a+1,a+1+n);
    int cnt=1;
    while(m>=a[cnt].a&&a[cnt].a<=choice/2&&cnt<=n){
        ans++;
        m-=a[cnt].a;
        swap(a[cnt].a,a[cnt].b);
        cnt++;
    }
    ans+=(m/choice*2);
    m%=choice;
    sort(a+1,a+1+n);
    cnt=1;
    while(m>=a[cnt].a&&cnt<=n){
        ans++;
        m-=a[cnt].a;
        cnt++;
    }
    cout<<ans<<endl;
    return 0;
}
