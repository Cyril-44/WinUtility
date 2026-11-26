#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll n,q,a[50010],lx,rx,f[50010],d;
bool fl;
ll t[50010];
void add(ll lf,ll rt,ll k){
    for(int i=lf;i<=rt;i++)t[i]=max(t[i],k);
}
unsigned ll pa(){
    unsigned ll su=1;
    for(int j=1;j<=63;j++)su*=2;
    su-=1;
    su*=2;
    su+=1;
    return su;
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=a[i]+f[i-1];
    }
    unsigned ll aaa=pa();
    cin>>q;
    while(q!=0){
        q--;
        cin>>lx>>rx;
        int l=1,r=lx;
        while(1){
            while(a[r+1]>=0&&r-l+1<rx&&r<n){
                r++;
            }
            add(l,r,f[r]-f[l-1]);
            while(a[l]<0&&r-l+1>lx){
                l++;
            }
            if(r==n&&r-l+1==lx)break;
            if(r-l+1==rx||r==n)l++;
            else if(r!=n)r++;
        }
        l=n-lx+1,r=n;
        while(1){
            while(a[l-1]>=0&&r-l+1<rx&&l>1){
                l--;
            }
            add(l,r,f[r]-f[l-1]);
            while(a[r]<0&&r-l+1>lx){
                r--;
            }
            if(l==1&&r-l+1==lx)break;
            if(r-l+1==rx||l==1)r--;
            else if(l!=1)l--;
        }
        unsigned ll cnt=0;
        for(unsigned ll i=1;i<=(unsigned ll)n;i++){
            if(i*t[i]>0)
            cnt^=(i*(unsigned ll)t[i]);
            else
            cnt^=aaa-(-((unsigned ll)i*(unsigned ll)t[i]))+1;
        }
        cout<<cnt<<endl;
        for(int i=1;i<=n;i++)t[i]=0;
    }
    return 0;
}
