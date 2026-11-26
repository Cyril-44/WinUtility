#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
struct node{
    int u,v;
}a[N];
int n,m,maxn;
bool f;
bool cmp(node x0,node y0){
    if(x0.u!=y0.u) return x0.u<y0.u;
    return x0.v<=y0.v;
}
void dfs(int num,int sum,int cnt){
    if(num>n){
        maxn=max(maxn,cnt);
        return;
    }
    while(sum>0){
        if(sum-a[num].u>=0){
            cnt++;
            sum-=a[num].u;
            swap(a[num].u,a[num].v);
            dfs(num+1,sum,cnt);
        }else return;
    }
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i].u>>a[i].v;
        if(a[i].u!=a[i].v) f=1;
	}
    if(f==0){
        sort(a+1,a+1+n,cmp);
        cout<<m/a[1].u;
        return 0;
	}
    dfs(1,m,0);
    cout<<maxn;
	return 0;
}
