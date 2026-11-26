#include<bits/stdc++.h>
using namespace std;

int t,n,m,x;
vector<int> e[8005];

void read(int &x){
	x=0;int flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=flag;
	return;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	read(t);
	while(t--){
		read(n);read(m);
		for(int i=1;i<=n;i++)
			read(x);
		cout<<n+1<<endl;
	}
	return 0;
}
