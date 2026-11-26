#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
unsigned int m;
int x[100005],y[100005];
struct node{
    int num;
    bool flag;
    bool operator < (node a) const{
        if(num==a.num) return flag<a.flag;
        return num<a.num;
    }
}a[200005];
inline bool check(int mid){
    int la=0;
    unsigned int tot=0,tmp=LONG_LONG_MAX;
    for(int i=1;i<=n;i++){
        if(a[i].flag==false){
            la=i;
            mid--;
            tot+=a[i].num;
        }else{
            tot+=a[i].num*((mid>>1)<<1);
            mid&=1;
            if(mid&&la) tmp=tot+(a[i].num<<1)-a[la].num;
        }
        if(min(tot,tmp)>(m<<1)) return false;
//        cout<<i<<' '<<tot<<' '<<mid<<'\n';
        if(!mid) return min(tot,tmp)<=(m<<1);
    }
    return false;
}
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        a[i].num=x[i]+y[i],a[i].flag=true;
        a[i+n].num=(x[i]<<1),a[i+n].flag=false;
    }
    n<<=1;
    sort(a+1,a+1+n);
//    for(int i=1;i<=n;i++) cout<<a[i].num<<' '<<a[i].flag<<'\n';
    int l=0,r=(m<<1)/a[1].num+1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    return 0;
}
