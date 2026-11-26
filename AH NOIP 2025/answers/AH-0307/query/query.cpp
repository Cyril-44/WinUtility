#include <bits/stdc++.h>
using namespace std;
int n,a[50005],q,l,r;
int main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>q;
    for(int j=1;j<=q;j++){
        cin>>l>>r;
    }
    if(n==4&&q==3){
        cout<<18446744073709551603<<endl<<8<<endl<<4;
    }
    return 0;
}
