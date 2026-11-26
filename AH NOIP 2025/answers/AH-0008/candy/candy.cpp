#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;
int n;ll m;
struct Node{
    int a,b,sum;
    bool operator<(const Node &x){
        return sum==x.sum?a<x.a:sum<x.sum;
    }
}x[N];
int a[N],b[N],c[N],alen,blen,clen;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i].a,&x[i].b);
        x[i].sum=x[i].a+x[i].b;
    }
    ll ans=0;
    sort(x+1,x+n+1);
    for(int i=2;i<=n;i++){
        if(x[i].a<min(x[1].a,x[1].b)){
            a[++alen]=x[i].a;
        }else if(x[i].a<=(x[1].a+x[1].b)/2){
            b[++blen]=x[i].a;
        }else if(x[i].a<max(x[1].a,x[1].b)){
            c[++clen]=x[i].a;
        }
    }
    sort(a+1,a+alen+1); sort(b+1,b+blen+1); sort(c+1,c+clen+1);
    // printf("%d %d %d %d %d\n",x[1].a,x[1].b,alen,blen,clen);
    for(int i=1;i<=alen;i++){
        if(m>=a[i]){
            m-=a[i];
            ans++;
        }else break;
    }
    if(x[1].a<x[1].b){
        if(m>=x[1].a){
            m-=x[1].a;
            ans++;
        }
        swap(x[1].a,x[1].b);
        // printf("swap\n");
    }
    for(int i=1;i<=blen/2*2;i++)
        if(m>=b[i]){
            m-=b[i];
            ans++;
        }
    // printf("%lld %lld\n",m,ans);
    ans+=m/(x[1].a+x[1].b)*2;
    m%=(x[1].a+x[1].b);
    // printf("%lld %lld\n",m,ans);
    if(blen&1){
        if(m>=b[blen]){
            m-=b[blen];
            ans++;
        }
    }
    for(int i=1;i<=clen;i++){
        // printf("%d ",c[i]);
        if(m>=c[i]){
            m-=c[i];
            ans++;
        }
    }
    if(m>=x[1].a){
        m-=x[1].a;
        ans++;
    }
    printf("%lld",ans);
    return 0;
}