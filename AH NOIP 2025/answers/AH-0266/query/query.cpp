#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int a[50010];
usigned main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int q;
	q=read();
	while(q--){
		int L,R;
		L=read();
		R=read();
		cout<<a[L]<<endl;
	}
	return 0;
}
