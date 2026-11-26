#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll m;
ll x[100050],y[100050];
struct node {
    ll w,st,id;
};
priority_queue<node>q;
bool operator < (node a,node b){
	if(a.w==b.w){
		return a.st<b.st;
	}
    return a.w>b.w;
};
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		q.push({x[i]*2,0,i}),q.push({x[i]+y[i],2,i});
    }
    ll ans=0;
    while(!q.empty()){
        ll w=q.top().w,st=q.top().st,id=q.top().id;
        q.pop();
        if(st==0){
            w/=2;
            if(m>=w)ans++,m-=w,q.push({y[id]*2,1,id});
        }
        else if(st==2){
            ans+=m/w*2;
            m-=m/w*w;
        }
        else if(st==1){
			w/=2;
            if(m>=w)ans++,m-=w,q.push({x[id]*2,0,id});
        }
    }
    printf("%lld\n",ans);

}
