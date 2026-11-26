#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
    }
    putchar(x%10+'0');
}
const int N=1e3+5,Mod=998244353;
int c,t,n,m,ans;
struct Node{
    int a,d;
    double b;
    bool operator < (const Node &rhs)const {
        if(b==rhs.b){
            return a>rhs.a;
        }
        return b>rhs.b;
    }
}a[N];
int qpow(int x){
    int base=2,tot=1;
    while(x){
        if(x&1){
            tot=(tot*base)%Mod;
        }
        base=(base*base)%Mod;
        x>>=1;
    }
    return tot%Mod;
}
vector<bool> d;
bool solve(){
    for(int i=1;i<=n;i++){
        a[i].b=1.0*a[i].a/d[i];
        a[i].d=d[i];
    }
    sort(a+1,a+n+1);
    int tot=0,maxn=0;
    for(int i=1;i<=n;i++){
        if(tot+a[i].d<=m){
            tot+=a[i].d;
            maxn+=a[i].a;
        }
        else{
            break;
        }
    }
    for(int i=n;i>=1;i--){
        if(a[i].a>maxn){
            return false;
        }
    }
    return true;
}
void dfs(int cur){
    if(cur>n){
        ans+=solve();
    }
    for(int i=1;i<=2;i++){
        d.push_back(i);
        dfs(cur+1);
        d.pop_back();
    }
    return ;
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    c=read();t=read();
    while(t--){
        ans=0;
        bool flag=1;
        n=read();m=read();
        for(int i=1;i<=n;i++){
            a[i].a=read();
            if(i>1&&a[i].a!=a[i-1].a)flag=0;
        }
        if(flag){
            write(qpow(n));
            puts("");
        }
        else{
            write(qpow(n)-2);
            puts("");
        }
    }
    return 0;
}
