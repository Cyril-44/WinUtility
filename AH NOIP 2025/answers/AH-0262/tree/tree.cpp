#include<bits/stdc++.h>
using namespace std;
const int N=8005;
struct node{
	vector<int> child;
	int value;
}t[N];
int f[N],d,is[N],mn;
bool ans[N];
void dfs(int root,int fa){
	if(t[root].child.empty()){
		t[root].value=f[fa]++;
		is[root]=1;
		return;
	}
	for(int i=0;i<t[root].child.size();i++)dfs(t[root].child[i],root);
}
void deep(int root,int tmp){
	d=max(d,tmp);
	if(!t[root].child.empty())
		for(int i=0;i<t[root].child.size();i++)deep(t[root].child[i],tmp+1);
	return;
}
void rk(int root){
	ans[t[root].value]=1;
	if(!t[root].child.empty())
		for(int i=0;i<t[root].child.size();i++)rk(t[root].child[i]);
	return;
}
int read(){
    int w=1,x=0;char c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar_unlocked();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar_unlocked();}
    return x*w;
}
void write(int x){
    if(x<0){putchar_unlocked('-');x=-x;}char c[1145];int len=0;while(x){c[++len]=(x%10)+'0';x/=10;}
    for(int i=len;i>=1;i--){putchar_unlocked(c[i]);}
}
int T,n,m;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    T=read();
    while(T--){
		memset(is,0,sizeof is);
		memset(f,0,sizeof f);
		n=read();m=read();
		for(int i=1;i<=n;i++)t[i].child.clear();
		for(int i=2;i<=n;i++)t[read()].child.push_back(i);
		dfs(1,1);
		for(int i=1;i<=n;i++){
			if(!is[i]){
				d=0;
				deep(i,1);
				if(t[i].child.size()<d-1)t[i].value=d-1;
				else t[i].value=t[i].child.size();
			}
		}
		for(int i=1;i<=n;i++)mn=max(mn,t[i].value);
		if(m>1)t[1].value=mn+1;
		int sum=0;
		for(int i=1;i<=n;i++){
			memset(ans,0,sizeof ans);
			rk(i);
			for(int j=0;j<=n;j++){
				if(!ans[j]){
					sum+=j;
					break;
				}
			}
		}
		write(sum);
		printf("\n");
	}
}
//!noip@Nov29,2025:dream
