#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull p(ull a,ull b)
{
	ull ans = 1;
	for(ull i = 1;i <= b;i++)
	{
		ans *= a;
		cout<<ans<<endl;
	}
	return ans;
}


int main()
{
	int a=6;
	a = a^6*2^(-3)^4;
	cout<<p(2,64);
	return 0;
}
