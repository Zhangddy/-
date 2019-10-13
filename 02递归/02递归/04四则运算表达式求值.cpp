#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//����һ����Ź��ʱ, ��������, +-*/()���, û�пո�
//Ҫ������ֵ, ����������������Ϊ����

//˼·
//���ʽ��һ���ݹ鶨��
//����ʽ=>�����=>�������=>���ʽ

int expression_value();

//������ֵ
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
		while (isdigit(c))//���c�ǲ���һ������,�����,���ַ����������ۼӳ�һ������
		{
			result = 10 * result + c - '0';
			cin.get();
			c = cin.peek();
		}
	}
	return result;
}
//����ֵ
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
//���ʽ��ֵ
int expression_value()
{
	int result = term_value();

	while (1)
	{
		char op = cin.peek(); //����������һ����, ��ȡ��
		if (op == '+' || op == '-')
		{
			cin.get(); //��������ȡ��һ����
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