#include <iostream>
#include <cstdlib>

using namespace std;

//�������еľ���, ÿ����ť����һյ��
//������һ����ťʱ, �ð�ť����Χ�ĸ�λ�õĵƶ���ı�״̬
//ԭ�������ľͻ�䰵, ԭ���ǰ��ľͻ����
//����ÿյ�Ƶ�״̬, ��һ�ְ���ť�ķ�ʽ

//˼·
//ͬһ���ư������൱��û��
//������ť���µ�˳�򲻻�Ӱ����

//�����һ��ȷ����
//�ڶ��п��Ը��ݵ�һ�е�ĳ����������һ�еĵƱ�ȻҪ����
//�ʽ���һ�е����п��ܽ��ö��

//����ɲ���λ�����С�ռ�
//char ��ʹ��6λbit

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
