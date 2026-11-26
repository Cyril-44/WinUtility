#include<bits/stdc++.h>
using namespace std;
long long T,n,m,p[8005],c[8005],d[8005],w[8005],wd[8005],md,va[8005],vb[8005];
vector<long long>s[8005];
void add(long long id)
{
    wd[p[id]]=max(wd[p[id]],d[id]);
    w[p[id]]++;
    if(id!=1)add(p[id]);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--)
    {
        cin>>n>>m;
        d[1]=md=0;
        w[1]=1;
        for(long long i=2;i<=n;i++)
        {
            cin>>p[i];
            w[i]=1;
            d[i]=d[p[i]]+1;
            md=max(md,d[i]);
            c[p[i]]++;
            s[p[i]].push_back(i);
            add(i);
        }
        for(long long i=md;i>=0;i--)
        {
            for(long long j=1;j<=n;j++)
            {
				if(d[j]!=i)continue;
                va[j]=w[j]*d[j];
                if(!c[j])vb[j]=1;
                else if(c[j]<2)vb[j]=vb[s[j][0]]+md-d[j]+1;
                else{
                    long long minn=LONG_LONG_MAX,sum=0;
                    for(long long k=0;k<c[j];k++)
                    {
						//cout<<vb[s[j][k]]-va[s[j][k]]<<endl;
                        sum=sum+vb[s[j][k]];
                        minn=min(minn,vb[s[j][k]]-va[s[j][k]]);
                    }
                    sum+=minn;
                    vb[j]=sum+md-d[j]+1;
                }
                //cout<<i<<' '<<j<<" "<<va[j]<<" " <<vb[j]<<endl;
            }
        }
        cout<<vb[1]<<endl;
    }
	return 0;
}
