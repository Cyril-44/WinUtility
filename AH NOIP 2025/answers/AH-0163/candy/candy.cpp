#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ci;
long long a,b,m,ans;
struct hh{int v,op;}x[N<<1];
bool cmp(hh a,hh b){return a.v<b.v;}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.ans","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        x[(i<<1)-1]={a*2,2};x[i<<1]={a+b,1};
    }
    sort(x+1,x+(n<<1)+1,cmp);
    while(true){
        ci++;
        if(x[ci].v/x[ci].op<=m){
            ans+=2/x[ci].op;
            m-=x[ci].v/x[ci].op;
        }
        else break;
    }
    cout<<ans;
    return 0;
}
