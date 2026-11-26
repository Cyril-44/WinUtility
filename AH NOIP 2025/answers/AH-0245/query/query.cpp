#include<bits/stdc++.h>
using namespace std;
long long const N=1e6+6;
long long n,a[N];

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	long long q;
	cin>>q;
	for(int i=1;i<=q;i++)
		cout<<random(0,0x3f3f3f3f)<<"\n";
}
