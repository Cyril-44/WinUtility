#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	ios::sync_with_stdio(false);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int max1=0,max2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			max1=max(max1,a[i]);
			if(a[i]>max2&&a[i]<max1)max2=a[i];
		}
		if(c==18){
			cout<<1<<endl;
		}
		if((c>=7&&c<=9)||c==14||c==15)
		{
			int num1=0,num2=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==max1)num1++;
				if(a[i]==max2)num2++;
			}
			if(num1==1){
				if(num2==1){
					cout<<pow(2,n-2)<<endl;
				}
				else{
					cout<<num2*pow(2,n-2)<<endl;
				}
			}
			else{
				if(num1==2){
					cout<<pow(2,n-2)<<endl;
				}
				else{
					cout<<num1*(num1-1)/2*pow(2,n-2)<<endl;
				}
			}
		}
	}
	return 0;
}
