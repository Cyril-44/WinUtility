#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=8e3+5;
int t,n,m,p[N];
int read(){
	int num=0,fh=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')fh*=-1;
		ch=getchar();
	}while(isdigit(ch)){
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*fh;
}
struct node{
	int u,v,p;
}e[N];
int ecnt,h[N],c[N];
void add(int u,int v){
	e[++ecnt].p=h[u];
	h[u]=ecnt;
	c[u]++;
	e[ecnt].u=u,e[ecnt].v=v;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10){
		write(x/10);
		putchar((x%10)+'0');
	}else{
		putchar(x+'0');
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	t=read();
	while(t--){
		ecnt=0;
		memset(h,0,sizeof(h));
		memset(c,0,sizeof(c));
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			p[i]=read();
			add(p[i],i);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=c[i];
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
