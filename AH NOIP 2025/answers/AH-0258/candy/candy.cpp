#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N = 1e5+11;
struct nod{
    int f,s;
}a[N];
bool cmp(nod x,nod y){
    return x.f<y.f;
}
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    int n,m,small=0x7fffffffffffffff,smallx=0,re;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a[i].f=x,a[i].s=y;
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i<=n;i++){
        int x=a[i].f,y=a[i].s;
        if(small>x+y||(small==x+y&&x<smallx))small=x+y,smallx=x,re=i;
    }
    int sum=0;
    for(int i = 1;i<=2;i++){
        sum+=a[i].f;
    }
    int cnt=0,ans=0;
    cnt+=m/small;
    ans+=2*cnt;
    m-=cnt*small;
    while(1){
        if(a[1].f<=m)ans++,m-=a[1].f,swap(a[1].f,a[1].s),sort(a+1,a+1+n,cmp);
        else break;
    }
    while(1){
        int anss=ans;
        ans-=2;
        m+=small;
        while(1){
            if(a[1].f<=m)ans++,m-=a[1].f,swap(a[1].f,a[1].s),sort(a+1,a+1+n,cmp);
            else break;
        }
        if(ans<=anss){ans=anss;break;}
    }
    cout<<ans;
    return 0;
}
