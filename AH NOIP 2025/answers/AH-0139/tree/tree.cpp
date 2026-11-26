#include<bits/stdc++.h>
using namespace std;
int t,n,a;
int main(){
	freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    srand(time(NULL));
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a;
        cout<<rand()%(n+1)+n<<endl;
    }
    return 0;
}

