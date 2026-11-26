# include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n,m,a[10000];
	cin >>n;
	for (int i=1;i<=n;i++)
		cin >>a[i];
	cin >>m;
	while(m--){
		int l,r;
		cin >>l>>r;
		cout<<l*r<<endl;
	}
	return 0;
}
