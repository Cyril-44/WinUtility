#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    long long w,x;
}a[5005],b[5005];
long long c,t,n,m,f[10005],ans,mod=998244353;
bool cmp(node a,node b){
    if(a.x*1.0/a.w!=b.x*1.0/b.w)return a.x*1.0/a.w>b.x*1.0/b.w;
    return a.x>b.x;
}
bool cmp1(node a,node b){
    return a.x<b.x;
}
long long qw(long long x,int y){
    long long res=1;
    while(y){
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res%mod;
}
bool check(){
    long long mx=0,sum=0,p=m;
    for(int i=0;i<=m;i++)f[i]=0;
    for(int i=1;i<=n;i++)b[i]=a[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i].w;j--)f[j]=max(f[j],f[j-b[i].w]+b[i].x);
    }
    for(int i=0;i<=m;i++)mx=max(mx,f[i]);
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(p>=b[i].w){
            p-=b[i].w;
            sum+=b[i].x;
        }
    }
    return (mx==sum);
}
void dfs(int x){
    if(x==n+1){
        if(check())ans++,ans%=mod;
        return ;
    }
    a[x].w=1;
    dfs(x+1);
    a[x].w=2;
    dfs(x+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
        ans=0;
        memset(f,0,sizeof(f));
	    cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i].x;
            a[i].w=0;
            b[i].x=b[i].w=0;
        }
        sort(a+1,a+1+n,cmp1);
        if(a[1].x==a[n].x){
            cout<<qw(2LL,n)<<endl;
        }else{
            dfs(1);
            cout<<ans<<endl;
        }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
