/*

   * Happy Zenith Noises *

         2025.11.29

*/
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,int>P;
const int MAXN=50005;
const int LEN=100;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m;
ll s[MAXN],ans[MAXN];
ll fff[MAXN][35];
int f[10005][10005],ff[10005][105],a[MAXN];
P q[200005];int hd,tl;
signed main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
    if(n<=10000){
        memset(ff,-0x3f,sizeof(ff));long long t;
        for(int i=1;i<=n;i++){
            hd=100000,tl=100001;
            for(int j=1;j<=n;j++){
                if(j+i-1<=n){
                    t=s[j+i-1]-s[j-1];
                    while(hd>=tl&&q[tl].fi<=t)tl++;
                    q[--tl]={t,j};
                }
                while(j-q[hd].se>=i)hd--;
                //assert(!q.empty());
                f[j][i]=q[hd].fi;
                ff[j][i/LEN+1]=max(ff[j][i/LEN+1],f[j][i]);
            }
        }
        cin>>m;
        while(m--){
            int l,r;int ans;ull s=0;
            cin>>l>>r;
            for(ull i=1;i<=n;i++){
                ans=-(1e9+7);
                if(r-l+1<=300){
                    for(int j=l;j<=r;j++)ans=max(ans,f[i][j]);
                }
                else{
                    for(int j=l;j<=(l/100+1)*100-1;j++)ans=max(ans,f[i][j]);
                    for(int j=l/100+2;j<=r/100;j++)ans=max(ans,ff[i][j]);
                    for(int j=r/100*100;j<=r;j++)ans=max(ans,f[i][j]);
                }
                s^=(ull)(ans)*i;
            }
            cout<<s<<"\n";
        }
    }
    else{
        for(int i=1;i<=32;i++){
            hd=100000,tl=100001;ll t;
            for(int j=1;j<=n;j++){
                if(j+i-1<=n){
                    t=s[j+i-1]-s[j-1];
                    while(hd>=tl&&q[tl].fi<=t)tl++;
                    q[--tl]={t,j};
                }
                while(j-q[hd].se>=i)hd--;
                fff[j][i]=q[hd].fi;
            }
        }
        cin>>m;
        while(m--){
            int l,r;cin>>l>>r;
            long long t;
            memset(ans,-0x3f,sizeof(ans));
            if(r<=32){
                for(int i=l;i<=r;i++){
                    for(int j=1;j<=n;j++){
                        ans[j]=max(ans[j],fff[j][i]);
                    }
                }
            }
            else{
                for(int i=l;i<=r;i++){
                hd=100000,tl=100001;
                for(int j=1;j<=n;j++){
                    if(j+i-1<=n){
                        t=s[j+i-1]-s[j-1];
                        while(hd>=tl&&q[tl].fi<=t)tl++;
                        q[--tl]={t,j};
                    }
                    while(j-q[hd].se>=i)hd--;
                    ans[j]=max(ans[j],q[hd].fi);
                }
                }
            }
            ull s=0;
            for(ull i=1;i<=n;i++)s^=(ull)(ans[i])*i;
            cout<<s<<'\n';
        }
    }
    return 0;
}
