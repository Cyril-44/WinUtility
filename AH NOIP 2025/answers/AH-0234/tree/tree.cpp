#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[114514];
int main(){
freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>t;
while(t--){
    cin>>n>>m;
    int ss=0;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
        ss+=a[i];
    }
    cout<<ss+m<<endl;
}
return 0;
}
