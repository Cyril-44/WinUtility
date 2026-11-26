#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node
{
    int fst,nxt;
    ll sum;
};

ll n,m,ans,mn=0x3f3f3f3f3f3f3f3f,Smn = 0x3f3f3f3f3f3f3f3f,Smni=0;
node cdy[100010];
int Fa=1,Fb=1;

bool cmp1(node x,node y)
{
    return x.fst < y.fst;
}

bool cmp2(node x,node y)
{
	return x.sum < y.sum;
}

int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);

    cin>>n>>m;
    int fst=0,nxt=0;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d",&fst,&nxt);
        cdy[i].fst=fst,cdy[i].nxt=nxt;
        cdy[i].sum = fst+nxt;
        if(cdy[i].sum < Smn)
        {
			Smn = cdy[i].sum;
			Smni = i;
		}
		if(cdy[i].sum == Smn)
        {
			if(cdy[i].fst < cdy[Smni].fst)
			{
				Smni = i;
			}
		}
      //  Smn = min(Smn,cdy[i].sum);
        mn = min(mn,(long long)(fst));
        if(Fa && fst != nxt) Fa = 0;
        if(Fb && fst < nxt) Fb = 0;
    }
    if(Fa)
    {
        sort(cdy+1,cdy+1+n,cmp1);
        cout<<m/cdy[1].fst;
    }
    else if(Fb){
		sort(cdy+1,cdy+1+n,cmp1);
		ans += (m/Smn)*2;
		ll lft = m%Smn;
		for(int i = 1;i <= n;i++)
		{
			if(lft >= cdy[i].fst)
			{
				lft -= cdy[i].fst;
				ans++;
			}
			if(lft >= cdy[i].fst) break;
		}	
		cout<<ans;
    }
	else
	{
		/*
			cout<<Smni<<" "<<cdy[Smni].fst<<" "<<cdy[Smni].nxt<<" "<<cdy[Smni].sum<<endl;
			sort(cdy+1,cdy+1+n,cmp1);
			for(int i = 1;i <= n;i++) cout<<cdy[i].fst<<" "<<cdy[i].nxt<<endl;
		*/
		sort(cdy+1,cdy+1+n,cmp1);
		ll lftt = m;
		for(int i = 1;i <= n;i++)
		{
			if(cdy[i].fst > (Smn/2)) break;
			if(lftt < cdy[i].fst && cdy[i].fst <= (Smn/2))
			{
				cout<<ans;
				return 0;
			}
			if(lftt >= cdy[i].fst && cdy[i].fst <= (Smn/2))
			{
				if(i == Smni) continue;
				ans++;
				lftt -= cdy[i].fst;    
				
				//cout<<cdy[i].fst<<endl;
				
				cdy[i].fst=INT_MAX;
			}
		}
	//	cout<<lftt<<endl;
		ans += (lftt/Smn)*2;
		ll lft = lftt%Smn;
		//cout<<lft<<endl;
		sort(cdy+1,cdy+1+n,cmp1);
		for(int i = 1;i <= n;i++)
		{
			if(cdy[i].fst == INT_MAX) continue;
			if(cdy[i].fst <= lft)
			{
				lft -= cdy[i].fst;
				ans++;
			}
			else if(cdy[i].fst > lft) break;
		}
		cout<<ans;
	}	
    return 0;
}
