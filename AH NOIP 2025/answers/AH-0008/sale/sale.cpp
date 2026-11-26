#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005,Mod=998244353;
int C[N][N],mi2[N];
int mod(int x){
    if(x>=Mod) return x-Mod;
    return x;
}
void init(){
    mi2[0]=1;
    for(int i=0;i<N;i++){
        if(i) mi2[i]=mod(mi2[i-1]<<1);
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=mod(C[i-1][j-1]+C[i-1][j]);
    }
}
int binom(int n,int m){
    if(n<0||m<0||n<m) return 0;
    return C[n][m];
}
int n,m,a[N],b[N];//,cnt[N<<1];
int cnt(int x){
    return upper_bound(b+1,b+n+1,x)-b-1;
}
void work(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),b[i]=a[i];
    sort(a+1,a+n+1,greater<int>());
    sort(b+1,b+n+1);
    int ans=mi2[n];
    for(int p=1;p<=n-1;p++){
        int q=n;
        for(int i=p+1;i<=n;i++)
            if(a[i]<=a[p]/2){
                q=i-1;
                break;
            }
        for(int i=p+1;i<=q;i++){
            if(a[p]-a[i]>0){
                ans=mod(ans+Mod-mi2[cnt(a[p]-a[i]-1)]*(ll)binom(i-2,m-p-1)%Mod);
            }
        }
    }
    printf("%d\n",ans);
}
int c,t;
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    init();
    scanf("%d%d",&c,&t);
    while(t--){
        work();
    }
    return 0;
}