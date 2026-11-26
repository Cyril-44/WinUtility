#include<iostream>
#include<cstdio>
#define ll long long
#define ull unsigned long long
#define N 10005
using namespace std;
int n,q,l,r;
ll a[N],sum[N],c[N],s[4*N],tag[4*N];
ull ans,k[N];
void down(int p){
    if(tag[p]){
        tag[p*2]=max(tag[p*2],tag[p]);
        tag[p*2+1]=max(tag[p*2+1],tag[p]);
        s[p*2]=max(s[p*2],tag[p]);
        s[p*2+1]=max(s[p*2+1],tag[p]);
        tag[p]=0;
    }
}
void up(int p){
    s[p]=s[p*2]+s[p*2+1];
}
void update(int l,int r,int p,int x,int y,ll v){
    if(l>y||r<x) return ;
    if(x<=l&&r<=y){
        s[p]=max(s[p],v);
        tag[p]=max(tag[p],v);
        return ;
    }
    down(p);
    int mid=(l+r)/2;
    update(l,mid,p*2,x,y,v);
    update(mid+1,r,p*2+1,x,y,v);
    up(p);
}
int query(int l,int r,int p,int x){
    if(l>x||r<x) return 0;
    if(l==r) return s[p];
    down(p);
    int mid=(l+r)/2;
    if(x<=mid) return query(l,mid,p*2,x);
    return query(mid+1,r,p*2+1,x);
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    scanf("%d",&q);
    while(q--){
        for(int i=1;i<=4*n;i++) s[i]=-0x3f3f3f3f;
        ans=0;
        scanf("%d%d",&l,&r);
        for(int i=l;i<=r;i++){
            for(int j=1;j+i-1<=n;j++){
                // j->j+i-1
                ll ss=sum[j+i-1]-sum[j-1];
                update(1,n,1,j,j+i-1,ss);
            }
        }
        for(int i=1;i<=n;i++) k[i]=query(1,n,1,i);
        for(int i=1;i<=n;i++) k[i]*=i,ans^=k[i];
        cout<<ans<<endl;
    }
    return 0;
}
