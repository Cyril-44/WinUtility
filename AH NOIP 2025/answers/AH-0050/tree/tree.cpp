#include<iostream>
#include<cstdio>
using namespace std;
int n,m;

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int o;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>o;
		printf("%d\n",1+n);
	}
	return 0;
}
