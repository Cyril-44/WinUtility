#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	srand(time(0));
	while(t--) cout<<rand()*rand();
	return 0;
}
