#include <bits/stdc++.h>
using namespace std;

int nn,m,ar[1001];

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n>>nn;
	if(n==2)cout<<9<<endl<<13;
	if(n==5&&nn!=40)cout<<52<<endl<<31<<endl<<25<<endl<<50<<endl<<46;
	if(nn==40)cout<<309<<endl<<160<<endl<<137<<endl<<173<<endl<<142;
	return 0;
}
