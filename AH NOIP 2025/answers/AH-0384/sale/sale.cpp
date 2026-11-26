#include<bits/stdc++.h>
using namespace std;
using ll=__int128;
ll read(){
    char cc=getchar();
    int f=1,x=0;
    while(!isdigit(cc)){
        if(cc=='-'){
            f=-f;
        }
        cc=getchar();
    }
    do{
        x=(x<<1)+(x<<3)+(cc^'0');
        cc=getchar();
    }while(isdigit(cc));
    return f*x;
}
void print(ll x){
    if(x<0){
        putchar('-');
        print(-x);
    }else if(x<10){
        putchar(x^'0');
    }else{
        print(x/10);
        putchar(a%10^'0');
    }
}
const int N=5005;
int n,f[10005];
struct candy{
    int a,w,id;
}a[N];
bool cmp(candy m,candy n){
    if(m.a*n.w!=m.w*n.a){
        return m.a*n.w>m.w*n.a;
    }else if(m.a!=n.a){
        return m.a>n.a;
    }else{
        return m.id<n.id;
    }
}
int ans=0;
void dfs(int x){
    if(x>n){
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;++i){
            for(int j=m;j>=a[i].a;--j){
                f[j]=max(f[j],f[j-a[i].w]+a[i].a);
            }
        }
        stable_sort(a+1,a+n+1,cmp);
        int res=0,tmp=m;
        for(int i=1;i<=n;++i){
            if(a[i].w>tmp){
                res+=a[i].a;
                tmp-=a[i].w;
            }
        }
        if(res==f[m]){
            ++ans;
        }
    }
    a[x].w=1;
    dfs(x+1);
    a[x].w=2;
    dfs(x+2);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        a[i].a=read();
        a[i].id=i;
    }
    dfs(1);
    print(ans);
    return 0;
}
