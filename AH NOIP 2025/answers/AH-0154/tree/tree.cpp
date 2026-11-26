
#include<bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int>fa;
	DSU(int size){
		fa.resize(size+1);
		for(int i=1;i<=size;i++){
			fa[i]=i;
		}
	}
	
	int find(int x){
		if(fa[x]==x){return x;}
		return fa[x]=find(fa[x]);
	}
	
	void unite(int a,int b){
		fa[find(a)]=find(b);
	}
};

template<typename T>
struct SegmentTree{
	vector<T>tree;
	//vector<T>arr;
	
	SegmentTree(int size){
		tree.resize(4*size+1);
	}
	
	void build(vector<T>&arr,int node, int s,int t){
		if(s==t)tree[node]=arr[s];
		
		int l = 2*node;
		int r = 2*node +1;
		build(arr,l,s,s+(t-s)/2);
		build(arr,r,s+(t-s)/2+1,t);
		//tree[node]=tree
	}
	
	T query(int a,int b, int node, int s,int t){
		if(a<=s&&t<=b)return tree[node];
		
		int l = 2*node;
		int r = 2*node +1;
		int lv = query(a,b,l,s,s+(t-s)/2);
		int rv = query(a,b,r,s+(t-s)/2+1,t);
		return  rv+lv;//
	}
	
	void modify(T v, int a,int b, int node, int s,int t){
		if(s==t)tree[node]=v;
		
		int l = 2*node;
		int r = 2*node +1;
		modify(v, a,b,l,s,s+(t-s)/2);
		modify(v, a,b,r,s+(t-s)/2+1,t);
		//return !noip@Nov29.2025:dream
	}
};

void floyd(){
	int n=1;;
	int dis[100][100];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	return 0;
}
