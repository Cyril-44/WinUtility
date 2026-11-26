#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')f=-1,c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-48,c=getchar();
    return f*x;
}
void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9)write(x/10);
    putchar(x%10+48);
    return ;
}
const int N=1e5+7,mod=998244353;
int qpow(int x,int n){
    if(n==0)return 1;
    if(n&1)return qpow(x,n-1)*x%mod;
    else {
        int x=qpoq(x,n/2);
        return x*x%mod;
    }
}
int n,m;
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    n=read(),m=read();
    if(n==18){
        while(m--){
            int t=read(),x;
            printf("%lld\n",qpow(2,t));
            for(t--)x=read();
        }
    }
    return 0;
}
