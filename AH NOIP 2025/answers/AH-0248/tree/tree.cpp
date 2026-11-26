#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		int x;
		for(int i=1;i<a;i++) cin>>x;
		cout<<a*b-1<<endl;
	}
	return 0;
}
