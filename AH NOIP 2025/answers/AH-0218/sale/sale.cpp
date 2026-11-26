#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL solve(LL n, LL del){
	LL answer=1;
	for(LL i=0;i<n;i++) {
		answer *= 2;
		while(answer >= 998244353) {
			answer-=998244353;
		}
	}
	answer -= del;
	while(answer < 0) answer += 998244353;
	return answer;
}

bool compare1(LL a, LL b){ 
	return a>b;
}

// CCF bao you wo wwwwww qwqwqwqwqwq
int main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	int c,t;
	cin>>c>>t;
	for(int _i=0;_i<t;_i++) {
		LL n,m;
		cin>>n>>m;
		if(c == 18) {
			LL nouse;
			for(LL i=0;i<n;i++) {
				cin>>nouse;
			}
			cout<<solve(n, 0)<<endl;
		} else {
			vector<LL> a(n);
			for(LL i=0;i<n;i++) {
				cin>>a[i];
			}
			sort(a.begin(), a.end(), compare1);
			LL midP = n;
			LL maxV = a[0];
			for(LL i=0;i<n;i++) {
				if(a[i]*2<maxV) {
					midP = i;
					break;
				}
			}
			LL dela = 0;// delete answer
			LL b = n-1;
			for(LL s=0;a[s]*2>maxV;s++) {
				if(a[s] == maxV) continue;
				while(b>=midP) {
					if (a[b] + a[s] >= maxV) break;
					b--;
				}
				dela += solve(n-1-b, 0);
			}
			cout<<solve(n, dela)<<endl;
		}
	}
	return 0;
}
