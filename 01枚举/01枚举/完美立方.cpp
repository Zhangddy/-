#include <iostream>
#include <cstdlib>

using namespace std;

//���� a3 = b3 + c3 + d3
//��������������N,ʹ��������ʽ, ����a,b,c,d ����1, С�ڵ���N, �� b <= c <= d

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