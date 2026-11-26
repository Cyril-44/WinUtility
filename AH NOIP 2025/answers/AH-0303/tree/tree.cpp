#include<bits/stdc++.h>
using namespace std;
long long i,n,m;
long long maxn[100100];
long long h,t=0;
long long p[100100]={0};
void dfs(){
}
long long cmp(long long a,long long b){
    return a>b;
}
int main(){
freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);
cin>>t;
while(t--){
    cin>>n>>m;
    for(i=0;i<n-1;i++){
        cin>>p[i];
    }
    sort(p+0,p+n-1,cmp);
    for(i=0;i<n-1;i++){
        maxn[i]=p[i]+p[i+1];
    }
    cout<<max(maxn[t],maxn[t+1])<<endl;
}
return 0;
}

