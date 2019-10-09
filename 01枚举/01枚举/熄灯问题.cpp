#include <iostream>
#include <cstdlib>

using namespace std;

//五行六列的矩阵, 每个按钮上有一盏灯
//当按下一个按钮时, 该按钮及周围四个位置的灯都会改变状态
//原来是亮的就会变暗, 原来是暗的就会变亮
//给定每盏灯的状态, 求一种按按钮的方式

//思路
//同一个灯按两次相当于没按
//各个按钮按下的顺序不会影响结果

//如果第一行确定了
//第二行可以根据第一行的某个灯亮则下一行的灯必然要点亮
//故将第一行的所有可能结果枚举

//本题可采用位运算减小空间
//char 可使用6位bit

char oriLights[5];
char lights[5];
char result[5];

int getBit(char c, int i)
{
	return (c >> i) & 1;
}

void setBit(char & c, int i, int v)
{
	if (v)
	{
		c |= (1 << i);
	}
	else
	{
		c &= ~(1 << i);
	}
}

void flipBit(char & c, int i)
{
	c ^= (1 << i); 
}

void outputResult(int t, char result[])
{
	cout << "PUZZLE #" << t << endl;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout << getBit(result[i], j);
			if (j < 5)
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				int s;
				cin >> s;
				setBit(oriLights[i], j, s);
			}
		}
		outputResult(t, oriLights);
		for (int n = 0; n < 64; ++n)
		{
			int switchs = n;
			memcpy(lights, oriLights, sizeof(oriLights));
			for (int i = 0; i < 5; ++i)
			{
				result[i] = switchs;
				for (int j = 0; j < 6; ++j)
				{
					if (getBit(switchs, j))
					{
						if (j > 0)
						{
							flipBit(lights[i], j - 1);
						}
						flipBit(lights[i], j);
						if (j < 5)
						{
							flipBit(lights[i], j + 1);
						}
					}
				}
				if (i < 4)
				{
					lights[i + 1] ^= switchs;
				}
				switchs = lights[i];
			}
			if (lights[4] == 0)
			{
				outputResult(t, result);
				break;
			}
		}
	}



	system("pause");
	return 0;
}
