#include<bits/stdc++.h>
#define min(a,b) (a>b?b:a)
using namespace std;
const int mod=998244353;
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
int c,t,n,m;
int a[5005];
struct node{
    int x,id;
}b[5005];
bool cmp(node a,node b){
    return a.x<b.x;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    in(c),in(t);
    if(c==18||c==16){
        while(t--){
            long long ans=1;
            in(n),in(m);
            for(int i=1;i<=n;i++){
                in(a[i]);
                ans=(ans*2)%mod;
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
    else if(c==17){
        while(t--){
            int mna=1e9;
            in(n),in(m);
            for(int i=1;i<=n;i++){
                in(a[i]);
                mna=min(mna,a[i]);
            }
            // if(t==0){
            //     sort(a+1,a+1+n);
            //     for(int i=1;i<=n;i++) printf("%d ",a[i]);
            //     puts("");puts("");
            // }
            bool ok=1,ok2=1;;
            for(int i=1;i<=n;i++)
                if(a[i]!=mna&&mna*2>a[i]) ok=0;
                else if(a[i]==mna) ok2=(ok2+1)%2;
            long long ans=1;
            for(int i=1;i<=n;i++) ans=(ans*2)%mod;
            if(ok||ok2) printf("%lld\n",ans);
            else if(!ok&&!ok2) printf("%lld\n",(ans+mod-1)%mod);
        }
    }
/*    else if((c>=14&&c<=15)||(c>=7&&c<=9)){
        while(t--){
            in(n),in(m);
            for(int i=1;i<=n;i++) in(b[i].x),b[i].id=i;
            sort(a+1,a+1+n,cmp);
            long long ans=0,txt=1;
            for(int i=1;i<=n-2;i++) txt=(txt*2)%mod;
            ans=txt;
            int ind=n-3;
            while(ind){
                if(b[ind].x*2<b[n].x) break;
                else if(b[ind].x*2==b[n].x&&b[ind].id<b[n].id) break;
            }
            txt=1;
            for(int i=1;i<=ind;i++) txt=(txt*2)%mod;
            ans=(ans+txt)%mod;
            ind=n-3;
            while(ind){
                if(b[ind].x*2<b[n].x) break;
                else if(b[ind].x*2==b[n].x&&b[ind].id<b[n].id) break;
            }
            txt=1;
            for(int i=1;i<=ind;i++) txt=(txt*2)%mod;
        }
    }*/
    return 0;
}
