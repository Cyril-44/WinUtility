#include <bits/stdc++.h>
using namespace std;
int a1[100010],a2[100010],a3[100010];
long long t;
int main (){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m;
	bool pian=true;
	long long min=1145141919810;	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
		if (a1[i]!=a2[i]) pian=false;
	}
	for (int i=1;i<=n;i++){
		a3[i]=a1[i]+a2[i];
		if (min>a3[i]){
			min=a3[i];
		}
	}
	t=m/min*2;
	sort(a1+1,a1+n+1);
	int cnt=1;
	long long leftm=m%min;
	while(leftm-a1[cnt]>=0){
		leftm-=a1[cnt];
		cnt++;
	}
	if (pian) cout<<m/a1[1];
	else cout<<t+cnt-1;
	return 0;
}
//你说的对,但是巧克力确实好吃
