#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//输入一个表殴打时, 仅由整数, +-*/()组成, 没有空格
//要求求其值, 假设所有运算结果均为整数

//思路
//表达式是一个递归定义
//求表达式=>求各项=>求各因子=>表达式

int expression_value();

//因子求值
int factor_value()
{
	int result = 0;
	char c = cin.peek();

	if (c == '(')
	{
		cin.get();
		result = expression_value();
		cin.get();
	}
	else
	{
		while (isdigit(c))//检测c是不是一个数字,如果是,将字符串的数字累加成一个整数
		{
			result = 10 * result + c - '0';
			cin.get();
			c = cin.peek();
		}
	}
	return result;
}
//项求值
int term_value()
{
	int result = factor_value();

	while (1)
	{
		char op = cin.peek();
		if (op == '*' || op == '/')
		{
			cin.get();
			int value = factor_value();
			if (op == '*')
			{
				result *= value;
			}
			else
			{
				result /= value;
			}
		}
		else
		{
			break;
		}
	}
	return result;

}
//表达式求值
int expression_value()
{
	int result = term_value();

	while (1)
	{
		char op = cin.peek(); //从数据流读一个数, 不取走
		if (op == '+' || op == '-')
		{
			cin.get(); //从数据流取走一个数
			int value = term_value();
			if (op == '+')
			{
				result += value;
			}
			else
			{
				result -= value;
			}
		}
		else
		{
			break;
		}
	}

	return result;
}

int main()
{
	cout << expression_value() << endl;


	system("pause");
	return 0;
}