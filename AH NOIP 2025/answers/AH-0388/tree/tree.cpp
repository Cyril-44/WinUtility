#include<bits/stdc++.h>
using namespace std;
long long t;
int main(void)
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        if(m==n-1)cout<<(1+n)*n/2<<"\n";
    }
    return 0;
}
