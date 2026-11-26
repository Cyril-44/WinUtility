#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=100010;

int n;
LL m;
PII w[N];
vector<PII> q;
pair<LL,int> s[N];
int id=1;

LL work1()
{
	LL cnt=(m/q[0].first)*2;
	if((m%q[0].first)>w[q[0].second].first)cnt++;
	return cnt;
}

LL work3(LL mm)
{
	for(;id<=n;id++)
	{
		if(s[id].first>mm)
		{
			id--;
			return s[id].second;
		}
		if(id==q[0].second+100)break;
	} 
	return -1;
}

LL work2()
{
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		s[i]={s[i-1].first+w[i].first,i};
	}

	LL cnt=(m/q[0].first);
	m-=cnt*q[0].first;
	cnt*=2;
	if((m%q[0].first)>w[q[0].second].first)
	{
		cnt++;
		flag^=1;
		m-=w[q[0].second].first;
	}


	LL cntx=cnt,mm=m;
	LL res=0;
	for(int i=0;i<=n;i++)
	{
		if(i==0)
		{
			if(cntx<0)break;
			//cout<<cntx<<" "<<mm<<" "<<cntx+work3(mm)<<endl;
			res=max(res,cntx+work3(mm));
			continue;
		}
		if(flag==1)
		{
			cntx--;
			mm+=w[q[0].second].first;
		}
		else 
		{
			cntx--;
			mm+=w[q[0].second].second;
		}
		if(cntx<0)break;
		if(work3(mm)==-1)break;
		//cout<<cntx<<" "<<mm<<" "<<cntx+work3(mm)<<endl;
		res=max(res,cntx+work3(mm));
		flag^=1;
	}
	return res;
}

int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);

	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i].first,&w[i].second);
	}
	sort(w+1,w+1+n);
	for(int i=1;i<=n;i++)
	{
		int t=w[i].first+w[i].second;
		q.push_back({t,i});
	}
	sort(q.begin(),q.end());

	LL cnt1=work1(),cnt2=work2();

	//cout<<cnt1<<" "<<cnt2<<endl;
	LL res=max(cnt1,cnt2);

	printf("%lld\n",res);

	fclose(stdin);
	fclose(stdout);

	return 0;
}