#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
int t,n,m,p[100010];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=2;i<=n;i++)cin>>p[i];
        cout<<n+1<<endl;
    }
    return 0;
}
