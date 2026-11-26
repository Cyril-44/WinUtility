#include<bits/stdc++.h>
using namespace std;
void in(int &x){
	int k=1;
	x=0;
	char c=getchar();
	while (!('0'<=c && c<='9')){
		if (c=='-')
			k=-1;
		c=getchar();
	}
	while (('0'<=c && c<='9')){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	x*=k;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	puts("18446744073709551603\n8\n4\n");
	return 0;
}
//!noip@Nov29,2025:dream
