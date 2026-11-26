#include<bits/stdc++.h>
using namespace std;
const int N = 8005;
int t;
int n,m,a[N],c[N],d[N];//a[i]表示第i个节点的根节点，c[i]表示第i个节点的子结点数量
//d[i]表示第i个节点的最大子结点数量
bool f[N] = {0};
struct f{
	int m = 0;//m为自己的价值
	int child[N];//child[i]为第i个子节点的价值
	int ad = 1;//ad为计算的子结点序号
}b[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++)b[i].child[j] = 0;
			d[i] = 0;c[i] = 0;b[i].m = 0;b[i].ad = 1;f[i] = 0;
		}
		for(int i = 2;i<=n;i++){
			cin >> a[i];
			c[a[i]]++;
		}
		for(int i = n;i>=2;i--){
			c[a[i]] += c[i];
		}
		for(int i = n;i>=2;i--){
			d[a[i]] = max(d[a[i]],c[i]);
		}
		for(int i = n;i>=1;i--){
			if(c[i] == 0){
				if(c[a[i]]==1){
					b[i].m = 1;
					b[a[i]].child[b[a[i]].ad] = 1;
					b[a[i]].ad++;
				}else{
					if(f[i] == 0){
						b[i].m = 1;
						b[a[i]].child[b[a[i]].ad] += 1;
						b[a[i]].ad++;
					}else{
						b[i].m = 0;
						b[a[i]].ad++;
					}
					for(int j = 1;j<=n;j++){
						if(a[i] == a[j])f[j] = 1;
					}
				}
			}else{
				int count = 0;
				for(int j = 1;j<=c[i];j++){
					count+=b[i].child[j];
				}
				if(d[i] == 0)b[i].m = c[i]+1+count;
				else b[i].m = d[i]+2+count;
				if(i!=1){
					b[a[i]].child[b[a[i]].ad] = b[i].m;
					b[a[i]].ad++;
				}
			}
		}
		cout << b[1].m << endl;
	}
	return 0; 
}
