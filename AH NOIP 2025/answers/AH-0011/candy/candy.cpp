#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define mk make_pair
using namespace std;
template<typename T>void in(T &x){
    char c=getchar();int f=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-'){c=getchar();f=-1;}
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    x*=f;
}
template<typename T>T mn(T a,T b){return a<b?a:b;}
template<typename T>T mx(T a,T b){return a>b?a:b;}
const int N=1e5+5;
int n;ll m;
struct h{int x,y;}a[N];
ll ans;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    in(n),in(m);
    int x=2e9+7;
    for(int i=1;i<=n;++i){
        in(a[i].x),in(a[i].y);
        x=mn(x,a[i].x+a[i].y);
    }
    sort(a+1,a+1+n,[](h a,h b){return a.x<b.x;});
    ll sum=0,ans=m/x*2;
    for(int i=1;i<=n;++i){
        sum+=a[i].x;
        if(sum>m) break;
        ans=mx(ans,i+(m-sum)/x*2);
    }
    printf("%lld\n",ans);
    return 0;
}