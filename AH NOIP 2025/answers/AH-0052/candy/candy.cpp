#include<bits/stdc++.h>
using namespace std;
#define int long long 
void read(int &xxx){
    xxx=0;
    bool fll=0;
    char ccc=getchar();
    while(ccc<'0'||ccc>'9'){
        if(ccc=='-')fll=1;
        ccc=getchar();
    }
    while(ccc>='0'&&ccc<='9'){
        xxx=xxx*10+ccc-'0';
        ccc=getchar();
    }
    if(fll)xxx=-xxx;
}
int n,m;
const int N=1e5+5;
struct M{
    int a,b;
};
M a[N];
int co=1e15;
int locx=0,locy=0;
struct cmp{
    bool operator()(M a,M b){
        if(a.a==b.b)return a.a+a.b>b.a+b.b;
        return a.a>b.a;
    }
};
priority_queue<M,vector<M>,cmp>q;
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    read(n);
    read(m);
    for(int i=1;i<=n;i++){
        read(a[i].a);
        read(a[i].b);
        if(co>a[i].a+a[i].b){
            co=a[i].a+a[i].b;
            locx=a[i].a;
	    locy=a[i].b;
        }
    }    
    int ans=(m/co)*2;
    m%=co;
    int res=0;
    for(int i=1;i<=n;i++){
        q.push(a[i]);
    }
    res=max(ans,res);
    for(int i=1;i<=100;i++){
        bool fin=0;
        while(m>=q.top().a){
            ans++;
            m-=q.top().a;
            q.push({q.top().b,q.top().a});
	    q.pop();
        }
	res=max(ans,res);
        while(m<q.top().a){
            ans--;
            m+=locy;
	    swap(locx,locy);
        }
    }
    cout<<res;
    return 0;
}