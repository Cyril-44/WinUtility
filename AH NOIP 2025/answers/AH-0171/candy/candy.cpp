#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAXN=100010;

struct node{
    ll bas,ext,idx,tx,ty;
};

struct edge{
    ll x,y,idx;
};

int n;
ll m;
node t[MAXN];
edge e[MAXN];
ll ans=0;

bool cmp(node n1,node n2){
    if(n1.bas!=n2.bas) return n1.bas<n2.bas;
    return n1.ext<n2.ext;
}

bool cmp2(edge e1,edge e2){
    if(e1.x!=e2.x) return e1.x<e2.x;
    return e1.y<e2.y;
}

ll calc(ll rest,ll st){
    ll pos=rest/t[1].bas;
    pos*=2;
    ll tt=rest-t[1].bas*pos;
    if(st==1&&tt>=t[1].ty) pos++;
    if(st==0&&tt>=t[1].tx) pos++;
    return pos;
}

int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>e[i].x>>e[i].y;
        t[i].bas=e[i].x+e[i].y,t[i].ext=e[i].x-e[i].y;
        t[i].idx=i;
        t[i].tx=e[i].x,t[i].ty=e[i].y;
    }
    sort(t+1,t+1+n,cmp);
    sort(e+1,e+1+n,cmp2);
    ll now=0,cnt=0,ans=calc(m,0),op=0;
    for(int i=1;i<=n;i++){
        if(now+e[i].x<=m){
            now+=e[i].x;
            if(e[i].idx==t[1].idx) op=1;
            ans=max(ans,calc(m-now,op)+i);
        }
    }
    cout<<ans<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
