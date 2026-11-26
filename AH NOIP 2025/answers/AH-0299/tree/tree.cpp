# include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		int n,m,sum=0,a[10000]={},num,maxx=-1;
		cin >>n>>m;
		for (int i=1;i<n;i++){
			 cin >>num;
			 a[num]++;
		}
		for (int i=2;i<=n;i++){
			if (a[i]!=0)
				sum+=a[i]+1;
			maxx=max(maxx,a[i]+2);
		}
		sum+=a[1];
		sum+=maxx;
		cout <<sum<<endl;
	}
	return 0;
}
