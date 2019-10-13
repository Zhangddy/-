#include <iostream>
#include <cstdlib>

using namespace std;

//逆波兰表达式是一种把运算符前置的算数表达式,
//例如 2 + 3  => + 2 3
//他的好处是可以不用括号而保证它的优先级
//例如 (2 + 3) * 4   =>  * + 2 3 4


//一个数为逆波兰表达式, 值为该数
//"运算符 逆波兰表达式 逆波兰表达式"
//为逆波兰表达式的值, 值为两个逆波兰表达式的运算结果
double exp()
{
	char s[20];
	cin >> s;

	if (s[0] == '+')
	{
		return exp() + exp();
	}
	else if (s[0] == '-')
	{
		return exp() - exp();
	}
	else if (s[0] == '*')
	{
		return exp() * exp();
	}
	else if (s[0] == '/')
	{
		return exp() / exp();
	}
	else
	{
		return atof(s);//返回数字
	}
}

int main_3()
{

	cout << exp();

	system("pause");
	return 0;
}