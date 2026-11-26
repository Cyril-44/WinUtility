#include<bits/stdc++.h>
#define ffor(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fford(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define inf 1e10
#define int unsigned long long
using namespace std;
const int N=8e3+5;
int t,n,m,p[N];

void spec2(){
    cout<<n<<endl;
}
void specmin(){

}

void solve(){
    cin>>n>>m;
    ffor(i,1,n-1) cin>>p[i];
    if(m<=2) spec2();
    specmin();
}

signed main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    ffor(i,1,t) solve();
    return 0;
}
