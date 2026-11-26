#include<iostream>
#include<algorithm>
using namespace std;
unsigned long long n, min_xpy, temp_sum;
unsigned long long m, res;
struct candy
{
	unsigned long long x, y, xpy;
	void print(){cout << x << "\t" << y << "\t" << xpy << "\n";}
}c[100001];
/*
	for(unsigned i = 1; i <= n; i++)
		c[i].print();
 */ 
bool comp_x(candy c1, candy c2)
	{return c1.x < c2.x;}
bool comp_y(candy c1, candy c2)
	{return c1.y < c2.y;}
bool comp_xpy(candy c1, candy c2)
	{return c1.xpy < c2.xpy;}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	cin >> n >> m;
	for(unsigned long long i = 1; i <= n; i++)
	{
		cin >> c[i].x >> c[i].y;
		c[i].xpy = c[i].x + c[i].y;
	}
	sort(c + 1, c + 1 + n, comp_xpy);
	min_xpy = c[1].xpy;
	res = (m / min_xpy) << 1, m %= min_xpy;
	//cout << "m = " << m << " res = " << res << " min_xpy = " << min_xpy <<"\n";
	sort(c + 1, c + 1 + n, comp_x);
	for(unsigned long long i = 1; i <= n; i++)
	{
		//cout << i << "," << res << "," << m << "\n";
		if(m >= c[i].x)
			res++, m -= c[i].x;
		else if(i + 2 <= n && m + min_xpy >= (temp_sum = c[i].x + c[i + 1].x + c[i + 2].x))
			res++, m = m + min_xpy - temp_sum, i += 2;
		else break;
	}
	cout << res;
	return 0;
}
/*
 * 我大抵是candy了，第7个大样例少了个1……
 * 
 * 也罢，70 + 0 + 0 + 0也行（不是）
 * 
 * Bury the light deep within!!!
 * Cast aside, there's no coming home!!!
 * We're burning chaos in the wind!!!
 * Drifting in the oceans, all alone!!!
 * 
 * 
 * 
 * 呐，莱纳，为什么那天，我的妈妈会被吃掉呢？
 * 
 * 
 * 
 * by UnknownFrisk(芙兰朵露小姐的血包)
 */
