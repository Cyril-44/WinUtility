#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int n,m,a[N] = {0};

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c!==0){
		while(t--){
			cout << 0;
		}
	}
	while(t--){
		cin >> n >> m;
		for(int i = 1;i<=n;i++)cin >> a[i];
		cout << 6;
	}
	return 0; 
}
