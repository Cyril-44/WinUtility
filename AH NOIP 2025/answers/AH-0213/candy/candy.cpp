#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll x,y,z;
}a[100005];
bool cmp(node h,node g){
    return h.x<g.x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ll n,m;
    ll minz=1e18,miny=0,minx=0;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;++i){
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].z=a[i].x+a[i].y;
        if(a[i].z<=minz){
            if(a[i].z==minz){
                if(a[i].y>miny){
                    minz=a[i].z;
                    miny=a[i].y;
                    minx=a[i].x;
                }
            }
            minz=a[i].z;
            miny=a[i].y;
            minx=a[i].x;
        }
    }
   // cout<<minx<<" "<<miny<<" "<<minz<<endl;
    sort(a+1,a+1+n,cmp);
    ll ans=0,leave=0;
    ans=m/minz;
    leave=m-ans*minz;
    ans*=2;
    ll flag=1,num=ans;
    ll i=0;
    //cout<<ans<<" "<<leave<<" "<<i<<endl;
    for(i=1;i<=n;i++){
        if(leave>=a[i].x){
            ans++;
            leave-=a[i].x;
        }
        else break;
    }
    ll num2=leave,num1=ans;
	//cout<<ans<<" "<<leave<<" "<<i<<endl;
    while(i<=n&&num>0){
		num1--;
		num=num-1;
		//cout<<num1<<" ";
		if(flag==1)num2+=miny;
		else num2+=minx;
		for(;i<=n;i++){
			num2-=a[i].x;
			if(num2>=0){
				num1++;
			}
			else{
				num2+=a[i].x;
				break;
			}
		}
		if(num1>ans)ans=num1;
		//cout<<num1<<endl;
		flag*=-1;
	}
    printf("%lld\n",ans);
    return 0;
}
//----by sudajones 2025-11-29 09:49 T1......AFO
