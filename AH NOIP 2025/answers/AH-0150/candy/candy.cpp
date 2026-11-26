#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 200005
using namespace std;
typedef long long ll;
int n,cnt;
ll m,ans,last,ans2,sum;
struct node{
    ll x,y;
    int pos;
    bool operator > (const node &b)const{
        return x>b.x;
    }
}a[MAXN],b[MAXN];
bool cmp(node a,node b){
    if(a.x+a.y!=b.x+b.y)
        return a.x+a.y<b.x+b.y;
    return a.x<b.x;
}
bool cmp2(node a,node b){
    if(a.x!=b.x) return a.x<b.x;
    return a.x+a.y<b.x+b.y;
}
priority_queue<node,vector<node>,greater<node> > p,q;
int vis[MAXN];
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].pos=i;
        b[i]=a[i];
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp2);
    //for(int i=1;i<=n;i++) cout<<a[i].x<<" "<<a[i].y<<endl;
    last=m%(a[1].x+a[1].y);
    ans+=(m/(a[1].x+a[1].y))*2;
    cnt=1;
    for(int i=1;i<=n;i++){
        q.push(a[i]);
        if(cnt==i-1&&i>=2){
            if(a[i].x+a[i].y==a[i-1].x+a[i-1].y)
                cnt++;
        }
    }
    while(!q.empty()){
        node h=q.top(); q.pop();
        //cout<<h.x<<" "<<h.y<<endl;
        if(h.x<=last){
           last-=h.x;
            ans++;
        }
    }
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++) q.push(a[i]);
    while(!q.empty()){
        node h=q.top(); q.pop();
        if(h.x>=a[1].x+a[1].y) break;
        if(h.x<=m){
            m-=h.x;
            ans2++;
            vis[h.pos]++;
            if(vis[a[1].pos]){
                ll tmp=1+((m-a[1].y)/(a[1].x+a[1].y))*2+ans2;
                last=(m-a[1].y)%(a[1].x+a[1].y);
                for(int i=1;i<=n;i++){
                    if(last-b[i].x<0) break;
                    if(!vis[b[i].pos]&&b[i].x<=last){
                        tmp++;
                        last-=b[i].x;
                    }
                }
                sum=max(sum,tmp);
            }else{
                ll tmp=(m/(a[1].x+a[1].y))*2+ans2;
                last=m%(a[1].x+a[1].y);
                for(int i=1;i<=n;i++){
                    if(last-b[i].x<0) break;
                    if(!vis[b[i].pos]&&b[i].x<=last){
                        tmp++;
                        last-=b[i].x;
                    }
                }
                sum=max(sum,tmp);
            }
            //cout<<h.x<<" "<<h.y<<"   :"<<sum<<endl;
        }
    }
    //cout<<ans<<" "<<sum<<endl;
    cout<<max(ans,sum)<<endl;
    return 0;
}
