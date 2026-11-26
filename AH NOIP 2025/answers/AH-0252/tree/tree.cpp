#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdin);
    int t,p[114514];
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<n;i++)
        {
            cin>>p[i];
        }
        cout<<n+1<<endl;
    }
    return 0;
}
