#include<bits/stdc++.h>
using namespace std;
int a[100001];
int n,m;
int t;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int s=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
		cout<<s<<endl;
	}
}

