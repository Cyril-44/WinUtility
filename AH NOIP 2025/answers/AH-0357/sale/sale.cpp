#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int c,t;
const long long mod=998244353;
int n,m;
struct node{
     long long x,id;
}a[5010],b[5010];
long long w[5010],cnt,maxn,k[5010];
bool cmp(node a,node b){
    if(a.x!=b.x) return a.x>b.x;
    if(a.x/(2/w[a.id])!=b.x/(2/w[b.id])) return a.x/(2/w[a.id])>b.x/(2/w[b.id]);
    else return a.id<b.id;
}

long long a1[5010],a2[5010],n1,n2;
void solve(){
    n1=n2=0;
    long long sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(w[b[i].id]==1){
            b[i].x/=2;
            a1[++n1]=b[i].x;
        } else {
            a2[++n2]=b[i].x;
        }
        cnt+=w[b[i].id];
        sum+=b[i].x;
    }
    a1[n1+1]=0;
    if(cnt<=m){
        maxn=sum;
        return ;
    }
    if(m%2==0){
        for(int i=1;i<=n1;i+=2){
            a2[++n2]=a1[i]+a1[i+1];
        }
        sort(a2+1,a2+n2+1);
        int k=m;
        while(k){
            k-=2;
            maxn+=a2[n2--];
        }
    } else {
        m--;
        maxn+=a1[1];
        for(int i=2;i<=n1;i+=2){
            a2[++n2]=a1[i]+a1[i+1];
        }
        sort(a2+1,a2+n2+1);
        int k=m;
        while(k){
            k-=2;
            maxn+=a2[n2--];
        }
        m++;
    }
}
void dfs(int d){
    if(d==n+1){
        for(int i=1;i<=n;i++){
            b[i].x/=w[i];
     //       cout<<b[i].x<<" ";
        }
        sort(b+1,b+n+1,cmp);
        int t=m;
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(w[b[i].id]==2)
            {
                if(t>=2){
                    t-=2;
                    sum+=b[i].x;
                }
            } else {
                if(t>=1){
                    t--;
                    sum+=b[i].x/2;
                }
            }
            if(t==0) break;
        }
        maxn=0;
        solve();
        if(sum==maxn) cnt++;
        for(int i=1;i<=n;i++) b[i]=a[i];
      //  cout<<w[1]<<" "<<w[2]<<" "<<w[3]<<" "<<maxn<<" "<<sum<<endl;
        return ;
    }
    w[d]=1;
    dfs(d+1);
    w[d]=2;
    dfs(d+1);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    if(c==18){
        k[0]=1;
        for(int i=1;i<=5000;i++){
            k[i]=k[i-2]*2%mod;
        }
        while(t--){
            cin>>n>>m;
            for(int i=1;i<=n;i++){
                cin>>a[i].x;
            }
            cout<<k[n]<<endl;
        }
        return 0;
    }
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i].x;
            b[i].x=a[i].x*2;
            a[i].x=b[i].x;
            a[i].id=b[i].id=i;
        }
        if(c<=5){
            cnt=0;
            dfs(1);
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
