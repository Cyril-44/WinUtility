#include<bits/stdc++.h>
using namespace std;
const int N=8010;
int t,n,m;
struct node{
    int f,q;
}p[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
        cin>>n>>m;
        for(int i=2;i<=n;i++)
            cin>>p[i].f;
        cout<<n*m-1;
	}
	return 0;
}
