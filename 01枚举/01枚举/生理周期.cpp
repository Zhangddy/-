#include <iostream>
#include <cstdlib>

using namespace std;

//�˵�����, ����, ���� �ĸ߷�����, ���Ƿֱ�ÿ��23, 28, 33 �����һ��
//����ÿ����, ������֪����ʱ�����߷�����ͬһ��
//�����ĸ�����,p e i d  d�Ǹ���������, ����С��p e i ,���d����������
void menstrualCycle()
{
	int p, e, i, d;
	while (cin >> p >> e >> i >> d && p!= -1)
	{
		int k;

		for (k = d; (k - p) % 23; ++k);
		for (; (k - e) % 28; k += 23);
		for (; (k - i) % 33; k += 23 * 28);
		cout << "next day is:" << k - d;
	}
}

int main_2()
{

	menstrualCycle();

	system("pause");
	return 0;
}