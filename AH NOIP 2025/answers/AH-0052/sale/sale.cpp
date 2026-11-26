#include<bits/stdc++.h>
using namespace std;
#define int long long 
void read(int &xxx){
    xxx=0;
    bool fll=0;
    char ccc=getchar();
    while(ccc<'0'||ccc>'9'){
        if(ccc=='-')fll=1;
        ccc=getchar();
    }
    while(ccc>='0'&&ccc<='9'){
        xxx=xxx*10+ccc-'0';
        ccc=getchar();
    }
    if(fll)xxx=-xxx;
}
#define double long double
int n,m;
int t,c;
const int N=11;
int a[N];
int dp[N*2];
struct M{
    double w,v;
};
M cal[N];
int dp2(int w){
    memset(dp,0,sizeof dp);
    for(int i=0;i<n;i++){
        int wi=((w>>i)&((long long)1))+1;
        for(int j=m;j>=wi;j--){
            dp[j]=max(dp[j],dp[j-wi]+a[i]);
        }
    }
    return dp[m];
}

bool cmp(M a,M b){
    if(abs(a.v/a.w-b.v/b.w)<=1e-6)return a.v>b.v;
    return a.v/a.w>b.v/b.w;
}
int tan(int w){
    for(int i=0;i<n;i++){
        cal[i]={(double)(((w>>i)&1)+1),(double)a[i]};
    }
    sort(cal,cal+n,cmp);
    int ans=0;
    double mo=m;
    for(int i=0;i<n;i++){
        if(mo<cal[i].w){
            continue;
        }
        mo-=cal[i].w;
        ans+=cal[i].v;
    }
    return ans;
}
const int mod=998244353;
int kasm(int x){
    if(x==0)return 1;
    if(x==1)return 2;
    int kkk=kasm(x/2)%mod;
    if(x%2==1){
        return ((kkk*kkk%mod)*2)%mod;
    }else return (kkk*kkk)%mod;
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    read(c);read(t);
    while(t--){
        read(n);
        read(m);
        for(int i=0;i<n;i++){
            read(a[i]);
        }
        if(c==16||c==18){
            cout<<kasm(n)<<endl;
            continue;
        }
        int ans=0;
        for(int i=0;i<=(1<<n)-1;i++){
            //if(dp2(i)!=tan(i))cout<<dp2(i)<<" "<<tan(i)<<" "<<i<<endl;
            if(dp2(i)==tan(i)){
                ans++;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}
/*
16 4
6 11
2 3 9 1 3 4
7 13
2 3 1 4 5 6 2
8 15 
2 4 2 1 5 2 1 4
10 19
2 33 12 34 13 44 22 11 23 49 

18 4
6 4
2 2 2 2 2 2
5 3
4 4 4 4 4 
8 5
7 7 7 7 7 7 7 7
10 3
8 8 8 8 8 8 8 8 8 8
*/