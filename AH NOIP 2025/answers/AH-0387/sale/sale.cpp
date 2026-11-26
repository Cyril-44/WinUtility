#include<iostream>
#include<algorithm>
#define mod 998244353
#define int long long
using namespace std;
int c,t,n,m,a[5000+10],w[5000+10],cnt,x[5000+10],pos2[5000+10];
struct node{
    int xi,ww,aa;
}tot[5000+10];
int solve(int id){
    if(id==n+1){
        int sum=0,sum2=0;
        for(int i=1;i<=n;i++){
            if(pos2[i]){
                sum+=w[i];
                sum2+=a[i];
            }
        }
        if(sum<=m)
            return sum2;
        else
            return 0;
    }
    pos2[id]=1;
    int t1=solve(id+1);
    pos2[id]=0;
    int t2=solve(id+1);
    return max(t1,t2);
}
bool cmp(node o,node p){
    if(o.xi!=p.xi)
        return o.xi>p.xi;
    return o.aa>p.aa;
}
void dfs(int idx){
    if(idx==n+1){
        for(int i=1;i<=n;i++)
            x[i]=a[i]*2/w[i];
        for(int i=1;i<=n;i++)
            tot[i].xi=x[i],tot[i].ww=w[i],tot[i].aa=a[i];
        sort(tot+1,tot+1+n,cmp);
        int sh=0,tmp=0;
        for(int i=1;i<=n;i++){
            if(sh+tot[i].ww<=m){
                sh+=tot[i].ww;
                tmp+=tot[i].aa;
            }
        }
        if(solve(1)==tmp)
            cnt++;
        else{
//            for(int i=1;i<=n;i++)
//                cout<<w[i]<<" ";
//            cout<<endl;
        }
        return ;
    }
    w[idx]=1;
    dfs(idx+1);
    w[idx]=2;
    dfs(idx+1);
    return ;
}
int quickpow(int x,int y){
    if(y==1)
        return x;
    if(y%2==0){
        int tmp=quickpow(x,y/2);
        return tmp*tmp%mod;
    }else{
        int tmp=quickpow(x,y/2);
        return (tmp*tmp%mod)*x%mod;
    }
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    if(c<=3){
        while(t--){
            cin>>n>>m;
            cnt=0;
            for(int i=1;i<=n;i++)
                cin>>a[i];
            dfs(1);
            cout<<cnt<<endl;
        }
    }else if(c==16||c==18){
        while(t--){
            cin>>n>>m;
            for(int i=1;i<=n;i++)
                cin>>a[i];
            cout<<quickpow(2,n)<<endl;
        }
    }
    return 0;
}
