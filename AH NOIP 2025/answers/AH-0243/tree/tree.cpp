#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
using namespace std;
int tt,n,m,a[8005];
bool mp[8005];
int t[8005],f[8005];
template <typename T>
inline void in(T &x){
    int f=1;x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
    return;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    in(tt);
    while(tt--){
        memset(f,0,sizeof(f));
        int cnt=0;
        in(n),in(m);
        for(int i=2;i<=n;i++) {
            in(a[i]);
            if(a[i]==1){
                t[++cnt]=i;
                mp[i]=1;
            }
        }
        if(m==1){
            printf("%d\n",n+1);
            continue;
        }
        else if(m==2){
            int ans=0,mx=0;
            for(int i=2;i<=n;i++)
                if(mp[a[i]]) f[a[i]]++;
            for(int i=1;i<=cnt;i++){
                if(f[t[i]]) ans=ans+1+f[t[i]]+1;
                else ans=ans+1;
                mx=max(mx,f[t[i]]);
            }
            ans+=mx+1;
            printf("%d\n",ans+1);
        }
    }
    return 0;
}
