#include <iostream>
#include <cstdlib>

using namespace std;

//�沨�����ʽ��һ�ְ������ǰ�õ��������ʽ,
//���� 2 + 3  => + 2 3
//���ĺô��ǿ��Բ������Ŷ���֤�������ȼ�
//���� (2 + 3) * 4   =>  * + 2 3 4


//һ����Ϊ�沨�����ʽ, ֵΪ����
//"����� �沨�����ʽ �沨�����ʽ"
//Ϊ�沨�����ʽ��ֵ, ֵΪ�����沨�����ʽ��������
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
		return atof(s);//��������
	}
}

int main_3()
{

	cout << exp();

	system("pause");
	return 0;
}