#include<bits/stdc++.h>
#define LL long long
using namespace std;

bool compare1(LL a, LL b){
	return a<b;
}

LL LMax(LL a, LL b){
	return a>b?a:b;
}

int main() {
	
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	
	LL n;
	LL m;
	cin>>n>>m;
	LL x[n];
	LL lessY = -1;
	
	LL _targetY;
	for (LL i=0;i<n;i++) {
		cin>>x[i]>>_targetY;
		if (_targetY + x[i] < lessY || lessY == -1) lessY = _targetY + x[i];
	}
	
	sort(x, x+n, compare1);
	
	LL lingqian = m;
	LL numbers = 0;
	while(lingqian >= lessY) {
		lingqian -= lessY;
		numbers++;
	}
	LL answer = numbers << 1;
	for(LL i=0;i<=numbers;i++) {
		LL curAns = i*2; // dang qian de tang guo shu liang
		LL curLQ = m - i*lessY; // mu qian hai you de qian
		for(LL j=0;j<n;j++) {
			if(curLQ < x[j]) break;
			curLQ -= x[j];
			curAns++;
		}
		answer = LMax(answer, curAns);
	}
	cout<<answer;
	
	return 0;
}
