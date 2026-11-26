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
        putchar(x%10^'0');
    }
}
const int N=50005;
int n,a[N],s[N];
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        s[i]=s[i-1]+a[i];
    }
    int q=read();
    do{
        int l=read(),r=read();
        unsigned long long ans=0,res=0;
        for(int i=1;i<=n;++i){
            for(int len=l;len<=r;++len){
                for(int left=max(i-len+1,1);left<=i&&left+len-1<=n;++left){
                    ans+=s[left+len-1]-s[left-1];
                }
            }
            res^=ans;
        }
        print(res);
        putchar('\n');
    }while(--q);
    return 0;
}
