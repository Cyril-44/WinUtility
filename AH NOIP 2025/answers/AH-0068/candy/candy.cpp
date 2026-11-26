#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=100005;
ll n,m,ans,s[maxn];
ll sumx,sumy;
struct candy{
    ll x,y;
}c[maxn];
bool cmp(candy a,candy b){
    return a.x<b.x;
}
ll cal(ll x){
        ll mm=m-s[x];
        ll cnt=mm/(sumx+sumy)*2;
        mm-=(sumx+sumy)*(mm/(sumx+sumy));
        if(mm>=sumx) cnt++;
        return cnt+x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll loc=0;
    for(int i=1;i<=n;i++){
        cin>>c[i].x>>c[i].y;
        if(loc==0||c[i].x+c[i].y<c[loc].x+c[loc].y)
            loc=i;
    }
    sumx=c[loc].x,sumy=c[loc].y;
    //cout<<sumx<<' '<<sumy<<endl;
    ll newn=n-1;
    for(int i=loc;i<=newn;i++)
        c[i]=c[i+1];
    sort(c+1,c+newn+1,cmp);
    for(int i=1;i<=newn;i++)
        s[i]=s[i-1]+c[i].x;
    //for(int i=1;i<=newn;i++)
     //   cout<<c[i].x<<' '<<c[i].y<<endl;
    //cout<<endl;
    /*ll i;
    bool flag=0;
    for(i=1;i<=newn;i+=2){
        if(i==newn) break;
        if(c[i].x+c[i+1].x<sumx+sumy){
            if(m>=c[i].x+c[i+1].x){
                ans+=2;
                m-=c[i].x+c[i+1].x;
            }
            else if(m>=c[i].x){
                ans++;
                m-=c[i].x;
                flag=1;
                break;
            }
            else {
                flag=1;
                break;
            }
        }
        else
            break;
    }*/
    ll l=0,r=newn,ans=0;
    for(int i=0;i<=newn;i++){
        if(s[i]>m) break;
        ans=max(ans,cal(i));
        }
    //cout<<cal(13)<<endl;
    cout<<ans;
    /*(cout<<ans<<endl;
    //cout<<i<<endl;
    if(flag==1){
        cout<<ans;
        //cout<<"!!!";
        return 0;
    }
    //cout<<ans<<endl;
    //cout<<m<<endl;
    if(i>newn||m<c[i].x){
    //    cout<<m<<endl;
    //cout<<ans<<endl;
    //cout<<sumx<<' '<<sumy<<endl;
        ans+=m/(sumx+sumy)*2;
    //cout<<"!!!";
        if(m-(sumx+sumy)*(m/(sumx+sumy))>=sumx) ans++;
    }
    else{
        //cout<<m<<endl;
        cout<<sumx<<' '<<sumy<<endl;
        cout<<c[i].x<<endl;

        ll mm=m;
        mm-=c[i].x;
        ll cnt1=1+mm/(sumx+sumy)*2;
        mm-=(sumx+sumy)*(mm/(sumx+sumy));
        if(mm>=sumx) cnt1++;

        mm=m;
        ll cnt2=mm/(sumx+sumy)*2;
        mm-=(sumx+sumy)*(mm/(sumx+sumy));
        if(mm>=sumx||mm>=c[i].x) cnt2++;
        //cout<<mm<<endl;
        ans+=max(cnt1,cnt2);
    //cout<<cnt1<<' '<<cnt2<<endl;
    }
    cout<<ans;*/
    return 0;
}
