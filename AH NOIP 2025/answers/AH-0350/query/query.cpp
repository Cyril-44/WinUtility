#include <bits/stdc++.h>
using namespace std;
#define int long long
#define exl __int128
#define gc getchar_unlocked
#define rt 1,n,1
int read(){
    int x=0;bool f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c))x=x*10+c-'0',c=gc();
    return f?-x:x;
}
const int dd=3e3+5;
int a[dd];int n;
int pre[dd];
exl M=1;
int ans[dd];
signed main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    n=read();M<<=64;pre[0]=0;
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    int q=read();
    while(q--){
        int L=read(),R=read();
        for(int i=1;i<=n;i++){
            ans[i]=-1e18;
            for(int len=L;len<=R;len++){
                for(int l=max(i+1-len,1ll);l<=i;l++){
                    int r=l+len-1;
                    ans[i]=max(ans[i],pre[r]-pre[l-1]);
                }
            }
        }
        unsigned int out=0;
        for(int i=1;i<=n;i++){
            exl t=ans[i];
            t=((t*i)+M)%M;
            out^=t;
        }
        printf("%llu\n",out);
    }
    return 0;
}
