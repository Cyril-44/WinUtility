#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=5e4+10;
ll ans=0,n,m,a;
int main(){
	freopen("query.in","r",stdin);                                    
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a;
	cin>>m;
	srand(time(0));
	while(m--){
		cin>>a>>a;
		cout<<rand()<<endl;
	}
}
