#include<iostream>
#include<vector>
using namespace std;
int n,m;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> p(n+1);
        for(int i=2;i<=n;i++){
            cin>>p[i];
        }
        cout<<m*n-1<<endl;
    }
}
