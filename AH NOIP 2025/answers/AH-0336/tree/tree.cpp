#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,p,ans;
int father[8010],depth[8010],tot[8010];
bool kemp[8010];
vector<int> child[8010];
void init(){
	for(int i=1;i<=n;i++){
		kemp[i]=1;
		depth[i]=0;
		tot[i]=0;
		father[i]=i;
		child[i].clear();
		child[i].push_back(0);
	}
}
int find(int x){
	if(father[x]==x)
		return x;
	return find(father[x]);
}
void add(int frm,int to){
	father[to]=frm;
	child[frm].push_back(to);
	child[frm][0]++;
}
queue<int> q;
int temp;
void dep(){
	depth[1]=1;
	q.push(1);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		for(int k=1;k<=child[temp][0];k++){
			depth[child[temp][k]]=depth[temp]+1;
			q.push(child[temp][k]);
		}
	}
	return;
}
int lcnode;
void find2(int x){
	lcnode=x;
	while(tot[father[lcnode]]==0 && lcnode!=1 && kemp[lcnode])
		lcnode=father[lcnode];
	return;
}
int flag,fans,flag2;
void solve(int nwnode){
	if(child[nwnode][0]==0){
		lcnode=nwnode;
		fans=0;
		while(flag2!=1 && lcnode!=1){
			while(lcnode!=1 && !kemp[lcnode])
				lcnode=father[lcnode];
			flag2=lcnode;
			find2(flag2);
			fans=max(depth[fans]-depth[lcnode]+1,fans);
		}
		find2(nwnode);
		if(fans<=depth[lcnode]-depth[nwnode]){
			ans+=(depth[lcnode]-depth[nwnode]);
			lcnode=nwnode;
			while(lcnode!=1 && kemp[lcnode]){
				tot[lcnode]=1;
				ans++;
				lcnode=father[lcnode];
			}
		}
		else{
			flag=tot[lcnode]+depth[lcnode]-depth[nwnode];
			ans+=fans;
		}
	}
	else{
		for(int k=1;k<=child[nwnode][0];k++)
			solve(child[nwnode][k]);
		find2(nwnode);
		if(kemp[nwnode]){
			for(int k=1;k<=child[nwnode][0];k++)
				tot[nwnode]=max(tot[nwnode],tot[child[nwnode][i]+1];
			ans+=(depth[lcnode]-depth[nwnode]);
		}
		else{
			fans=0;
			while(flag2!=1 && lcnode!=1){
				while(lcnode!=1 && !kemp[lcnode])
					lcnode=father[lcnode];
				flag2=lcnode;
				find2(flag2);
				fans=max(depth[fans]-depth[lcnode]+1,fans);
			}
			ans+=fans;
		}
	}
	return;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		init();
		for(int i=1;i<=n;i++){
			cin>>p;
			add(i,p);
		}
		dep();
		solve(1);
		cout<<ans<<endl;
	}
    return 0;
}
