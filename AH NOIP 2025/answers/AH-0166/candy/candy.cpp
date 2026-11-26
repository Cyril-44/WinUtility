#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
pair<int,int>a[100010];
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    sort(a+1,a+1+n,[](pair<int,int>a,pair<int,int>b){
         if(a.first+a.second!=b.first+b.second)return a.first+a.second<b.first+b.second;
         return a.first<b.first;
    });
    long long t=m,q=a[1].first+a[1].second,anst,ans,maxx=0,ysum;
    sum=m/q*2;
    ysum=sum;
    t-=sum/2*q;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(t>=a[i].first){sum++;t-=a[i].first;}
        else break;
    }
    maxx=sum;
    for(int j=1;j<=min(min(n,ysum)/2,100ll);j++){
        anst=m;
        ans=ysum-j*2;
        anst-=ans/2*q;
        for(int i=1;i<=n;i++){
            if(anst>=a[i].first){ans++;anst-=a[i].first;}
            else break;
        }
        maxx=max(ans,maxx);
    }
    cout<<maxx;
    return 0;
}
