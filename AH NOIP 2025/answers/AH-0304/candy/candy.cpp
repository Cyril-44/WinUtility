#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e4 + 10;
int f[1010][N];
int v1[N], v2[N], w[N];
int main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) scanf("%d%d", &v1[i], &v2[i]);
	for(int i = 1; i <= n; i++) w[i] = 1;

	    for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                f[i][j] = max(f[i][j], f[i-1][j]);
                for(int k = 1; ( (k%2 == 0) && (j-( (k/2)*v1[i] + (k/2)*v2[i] ) >= 0) ) ||
                ( (k%2 != 0) && (j-( (k/2+1)*v1[i] + (k/2)*v2[i] ) >= 0) ) ; k++)
                {
                    if(k%2 == 0) f[i][j] = max(f[i][j], f[i-1][j-( (k/2)*v1[i] + (k/2)*v2[i] )]+k*w[i] );
                    else f[i][j] = max(f[i][j], f[i-1][j-( (k/2+1)*v1[i] + (k/2)*v2[i] )]+k*w[i] );
                }
            }
        }

    cout << f[n][m];

    return 0;
}
