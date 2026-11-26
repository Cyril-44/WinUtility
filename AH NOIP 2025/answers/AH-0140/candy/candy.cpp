#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long m,cnt[N];
struct ruanwentao{
    int x,y;
    long long sum;
}a[N];
bool cmp1(ruanwentao u,ruanwentao v){
    if(u.sum!=v.sum)return u.sum<v.sum;
    return u.y>v.y;
}
bool cmp2(ruanwentao u,ruanwentao v){
    return u.x<v.x;
}
int work1(long long h){
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i].x;
        if(sum>h)return i-1;
    }
    return n-1;
}
int work2(long long h){
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i].x;
        if(sum>h)return i-2;
    }
    return n-1;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].sum=a[i].x+a[i].y;
    }
    sort(a+1,a+n+1,cmp1);
    long long ans=0,kpi;
    ans+=(m/a[1].sum)*2;
    kpi=ans;
    long long t1=m%a[1].sum;
    long long k1=a[1].sum,l=a[1].y;
    sort(a+1,a+n+1,cmp2);
    for(int i=1;i<=n;i++){
        cnt[i]=cnt[i-1]+a[i].x;
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]<=t1){
            ans=max(ans,kpi+i);
        }else{
            long long p=cnt[i]-t1;
            if(p%k1==0){
                long long k2=p/k1;
                if(kpi<2*k2)continue;
                ans=max(ans,kpi-2*k2+i);
            }else{
                long long k2=p/k1;
                if(p%k1<=l){
                    if(kpi<2*k2+1)continue;
                    ans=max(ans,kpi-2*k2-1+i);
                }else{
                    if(kpi<2*k2+2)continue;
                    ans=max(ans,kpi-2*(k2+1)+i);
                }
            }
        }
    }
    cout<<ans;
    /*
    long long d=a[1].sum,maxn=-1;
    int idx=-1;
    for(int i=1;i<=n;i++){
        if(a[i].sum==d){
            if(a[i].y>maxn){
                maxn=a[i].y;
                idx=i;
            }
        }
    }
    t2+=a[idx].y;
    if(idx!=1){
        ruanwentao p=a[1];
        a[1]=a[idx];
        a[idx]=p;
    }
    sort(a+2,a+n+1,cmp2);
    */
    //ans+=max(work(t1),work(t2)-1);
    /*
    ans=max(k1,k2);
    cout<<ans<<"\n";
    sort(a+1,a+n+1,cmp1);
    long long d=a[1].sum;
    for(int i=1;i<=n;i++){
        if(a[i].sum==d){
            cout<<a[i].x<<" "<<a[i].y<<"\n";
        }
    }
    cout<<k1<<" "<<k2<<"\n";
    */
    fclose(stdin);
    fclose(stdout);
    return 0;
}
