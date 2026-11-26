#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll n,m,cnt,f[100010];
struct node{
    ll x,y;
}a[100010];
bool cmp1(node a,node b){
    return (a.x+a.y)<(b.x+b.y);
}
bool cmp2(node a,node b){
    return a.x<b.x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1,cmp2);
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+a[i].x;
    }
    sort(a+1,a+n+1,cmp1);
    for(int i=1;i<=n;i++){
        cnt=max(cnt,i+2*((m-f[i])/(a[1].x+a[1].y)));
    }
    cout<<cnt;
    return 0;
}
