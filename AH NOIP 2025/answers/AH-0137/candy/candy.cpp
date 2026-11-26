#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=100010;
ll n,m,ans,sum;
ll x[N],y[N];
priority_queue<ll> q1;
stack<ll> q;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    ll minn=1e9+10;
    ll maxn=0,cnt;
    for(ll i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        ll t=x[i]+y[i];
        if(t<minn||(t==minn&&x[i]>maxn)){
            maxn=x[i]; minn=t;
            cnt=i;
        }
    }
    //cout<<x[cnt]+y[cnt]<<endl;
    for(ll i=1;i<=n;i++){
        if(i==cnt) continue;
        if(x[i]<=y[cnt]){
            q1.push(x[i]);
        }
    }
    while(q1.size()){
		q.push(q1.top());
		q1.pop();
	}
    ans=max(ans,sum+(m/(x[cnt]+y[cnt]))*2);
    while(q.size()){
        ll t=q.top();
        q.pop();
        if(m<t){
            ans=max(ans,sum+(ll)(m/(x[cnt]+y[cnt]))*2+m%(x[cnt]+y[cnt])/x[cnt]);
            break;
        }else{
            m-=t;
            sum++;
            //cout<<t<<" "<<sum+(int)(m/(x[cnt]+y[cnt]))*2+m%(x[cnt]+y[cnt])/x[cnt]<<endl;
            ans=max(ans,sum+(ll)(m/(x[cnt]+y[cnt]))*2+m%(x[cnt]+y[cnt])/x[cnt]);
        }
    }
    cout<<ans;
    return 0;
}
