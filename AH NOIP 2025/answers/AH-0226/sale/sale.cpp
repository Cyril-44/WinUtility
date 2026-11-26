#include<bits/stdc++.h>
#define _ 5005
#define M 998244353
using namespace std;
int n,m,T,val,C,bag[_];long long ans=0;bool f;
struct node{
    int id,ori,w;
    void input(int i){scanf("%d",&ori);id=i;w=1;}
}b[_],c[_],B[2*_];
bool cmp(node x,node y){
    if(x.ori*2/x.w!=y.ori*2/y.w)return x.ori*2/x.w>y.ori*2/y.w;
    if(x.ori!=y.ori)return x.ori>y.ori;
    return x.id<y.id;
}bool cmp0(node x,node y){
    if(x.ori!=y.ori)return x.ori>y.ori;
    if(x.w!=y.w)return x.w<y.w;
    return x.id<y.id;
}
void dfs(int d){
    if(d>n){
        for(int i=1;i<=n;i++)B[i]=c[i]=b[i];
        sort(c+1,c+n+1,cmp);
        sort(B+1,B+n+1,cmp0);
        int v1=0,cnt1=0;
        for(int i=1;i<=n;i++){
            cnt1+=c[i].w;
            if(cnt1>m)break;
            v1+=c[i].ori;
        }for(int j=1;j<=n;j++){
            for(int i=1;i<=m;i++){
                if(i>=B[j].w)bag[i]=max(bag[i],max(bag[i-1],bag[i-B[j].w]+B[j].ori));
                else bag[i]=max(bag[i],bag[i-1]);
            }
        }
        if(bag[m]<=v1)ans=(ans+1)%M;
    }
    b[d].w=1;dfs(d+1);b[d].w=2;dfs(d+1);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        memset(bag,0,sizeof(bag));
        val=ans=0;f=1;scanf("%d%d",&n,&m);for(int i=1;i<=n;i++)
        {b[i].input(i);B[i]=c[i]=b[i];f=(f&&b[i].ori==b[i-1].ori);}
        if(m==2){
            sort(c+1,c+n+1,cmp0);
            long long p=ans=1,mm=1;
            while(2*c[p].ori>c[1].ori)p++;
            for(int i=1;i<n;i++)ans=(ans*2)%M;
            for(int i=1;i<=n-p+1;i++)mm=(mm*2)%M;
            ans+=mm;printf("%lld\n",ans%M);
            continue;
        }
        if(f||m==2*n-1){
            ans=1;
            for(int i=1;i<=n;i++)ans=(ans*2)%M;
            printf("%lld\n",ans);
            continue;
        }
        dfs(1);printf("%lld\n",ans);
    }
    return 0;
}
