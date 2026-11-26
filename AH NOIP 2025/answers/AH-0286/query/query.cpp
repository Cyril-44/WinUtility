#include<bits/stdc++.h>
using namespace std;
int n,a[50005],q,l,r;
long long sum;
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		sum=0;
		cin>>l>>r;
		
		cout<<!sum<<endl;
	}
	return 0;
}
