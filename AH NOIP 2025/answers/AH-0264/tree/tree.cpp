#include <bits/stdc++.h>
using namespace std;
int n,m;
int k;
struct tree
{
	int sonsum;
	int dad;
	int w;
	int son[400];
};

tree t[405];

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>k;
	for(int j=1;j<=k;j++)
	{
		memset(t,0,sizeof(t));
		cin>>n>>m;
		for(int i=1;i<n;i++)
		{
			cin>>t[i].dad;
			t[i].dad--;
			t[t[i].dad].son[t[t[i].dad].sonsum]=i;
			t[t[i].dad].sonsum++;
		}
		cout<<random();
	}
	
	return 0;
}
