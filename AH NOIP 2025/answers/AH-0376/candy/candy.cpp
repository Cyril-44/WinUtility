#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,mn=2e10,mni;
struct date{
    int a,b;
}a[100005];
bool cmp(date a,date b){
    if(a.a!=b.a) return a.a<b.a;
    return a.b<b.b;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
	if(mn>=a[i].a+a[i].b) mn=a[i].a+a[i].b,mni=i;
    } 
    int f=0,x=a[mni].a;
    stack<int>y;
    for(int i=1;i<=n;i++){
	if(a[i].a<=m&&a[i].a<=mn/2){
	    ans++,m-=a[i].a;
	    if(i==mni) f=1;
	    else y.push(a[i].a);
	} 
	else{
	    x=min(x,a[i].a);
	    break;
	}
    } 
    if(f){
	if(m<a[mni].b){
	    cout<<ans;
	    return 0;
	}
	m-=a[mni].b,ans++;
    }
    ans+=m/mn*2,m%=mn;
    while(!y.empty()&&m+y.top()>=mn) ans++,m=m+y.top()-mn,y.pop();
    if(m>=x) ans++;
    cout<<ans;
    return 0;
}
