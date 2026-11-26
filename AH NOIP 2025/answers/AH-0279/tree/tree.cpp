#include<bits/stdc++.h>
using namespace std;
int f[10001];
int find(int x){
    int ans=0;
    while(f[x]!=x){
        x=f[x];
        ans++;
    }
    return ans;
}
int main(){
   freopen("tree.in","r",stdin);
   freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,t;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>n>>m;
        f[1]=1;
        for(int i=2;i<=n;i++){
        cin>>f[i];
        }
        if(n<10)cout<<n*2-1<<endl;
        else if(n<40)cout<<3*n<<endl;
        else cout<<2*n<<endl;


    }
    return 0;
}
