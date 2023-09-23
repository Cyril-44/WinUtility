#include <iostream>
#include <vector>
using std::vector;
vector<int> p;
const int N = 1e7;
const int mode = 0;
bool np[N + 5];
size_t i;
inline void initp()
{
	for (i = 2; mode || i < N; i++)
	{
		if (!np[i])
		{
			p.push_back(i);
			if (mode && p.size() == N)
				return;
		}
		for (const auto &j : p)
		{
			if (i * j >= N)
				break;
			np[i * j] = true;
			if (i % j == 0)
				break;
		}
	}
}
int main()
{

	initp();
	if (mode)
		std::cout << "last: " << i << std::endl;
	else
		std::cout << "size: " << p.size() << std::endl;
	return 0;
}