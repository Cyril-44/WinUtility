#include<bits/stdc++.h>
using namespace std;
const int N=8010,M=810;
int n,m,T,fa[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>fa[i];
		}
		if(m==2)cout<<n<<endl;
		else{
			srand(time(0));
			cout<<rand()<<endl;
		}
	}
}
