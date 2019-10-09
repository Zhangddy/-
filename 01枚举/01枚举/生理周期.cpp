#include <iostream>
#include <cstdlib>

using namespace std;

//人的体力, 情商, 智商 的高峰日子, 他们分别每隔23, 28, 33 天出现一次
//对于每个人, 我们想知道何时三个高峰落在同一天
//输入四个整数,p e i d  d是给定的日子, 可能小于p e i ,输出d后的最佳日子
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