#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll mol=998244353;
struct node{
	ll x,y;
}b[100004];
ll n,m,a[10005],maxnum=0,tot=0;
ll w[10005][5];
bool cmp(node g,node h){
	if(g.x==h.x)return g.y>h.y;
	return g.x>h.x;
}
void solve(){
	ll money=m*2,num=0;
	sort(b+1,b+1+n,cmp);
	for(ll i=1;i<=n;i++){
		if(money>=b[i].x){
			money-=b[i].x;
			num+=b[i].y;
		}
	}
	if(num>maxnum){
		maxnum=num;
		tot=0;
	}
	tot=(tot+1)%mol;
	return ;
}
void find(ll num){
    if(num>n){
        solve();
        return ;
    }
    b[num].y=a[num];
    b[num].x=w[num][1];
    find(num+1);
    b[num].x=w[num][2];
    find(num+1);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
		maxnum=0;
		tot=0;
		memset(b,0,sizeof(b));
        scanf("%lld%lld",&n,&m);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            w[i][1]=a[i]*2;
            w[i][2]=a[i];
        }
        find(1);
        cout<<tot<<endl;
    }
    return 0;
}
