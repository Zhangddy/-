#include <iostream>
#include <cstdlib>

using namespace std;

//形如 a3 = b3 + c3 + d3
//给定任意正整数N,使得满足上式, 其中a,b,c,d 大于1, 小于等于N, 且 b <= c <= d

void perfectCube(int N)
{
	int a, b, c, d;
	for (a = 2; a <= N; ++a)
	{
		for (b = 2; b <= N - 1; ++b)
		{
			for (c = b; c <= N - 1; ++c)
			{
				for (d = c; d <= N - 1; ++d)
				{
					if (a * a * a == b * b * b + c * c * c + d * d * d)
					{
						cout << "cube =	" << a << "	triple = " << b << "," << c << "," << d << endl;
					}
				}
			}
		}
	}
}

int main_1()
{

	perfectCube(30);

	system("pause");
	return 0;
}