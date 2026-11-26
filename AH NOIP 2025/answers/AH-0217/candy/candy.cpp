#include <bits/stdc++.h>
using namespace std;
unsigned long long n,m,ma=LLONG_MAX,ans,sum,mark;
struct node{
    unsigned long long x;
    unsigned long long y;
}a[100005];
bool cmp(node u,node v){
    return u.x<v.x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        if((a[i].x+a[i].y)<ma){
            ma=a[i].x+a[i].y;
        }
    }
    ans=floor(m/ma)*2;
    sum=ans;
    m=m-ans/2*ma;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(m>=a[i].x){
            ans++;
            m-=a[i].x;
            mark=i;
        }else if(mark!=i-1&&a[i-1].x>m&&(a[i].x+a[i-1].x)<ma&&sum-2>=0){
            m=m+ma-a[i].x-a[i-1].x;
            sum-=2;
            mark=i;
        }else if(mark!=i-1) break;
    }
    cout<<ans;
}
