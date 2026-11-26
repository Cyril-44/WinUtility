#include<bits/stdc++.h>
using namespace std;
int q;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	return 0;
	cin>>q;
	for(int i=1;i<=q;i++) cin>>q;
	cin>>q;
	srand(time(0));
	while(q--) cout<<rand()*rand();
}
