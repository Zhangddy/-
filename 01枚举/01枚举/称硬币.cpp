#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//��12öӲ��, ������һöΪ��  A ---- L
//�ٱ������������ͬ, ����֪���ٱұ�����ỹ����
//������һ����ƽ������Щ������, ������ƵĽ��, ���ҳ��ٱҲ�ȷ���ٱ��ػ�����

char g_left[3][7];
char g_right[3][7];
char g_result[3][7];

bool isFake(char c, bool light)
{
	for (int i = 0; i < 3; ++i)
	{
		char* pLeft;
		char* pRight;

		if (light)
		{
			pLeft = g_left[i];
			pRight = g_right[i];
		}
		else
		{
			pRight = g_left[i];
			pLeft = g_right[i];
		}

		if (g_result[i][0] == 'u')
		{
			if (strchr(pRight, c) == NULL)
			{
				return false;
				break;
			}
		}
		else if (g_result[i][0] == 'e')
		{
			if (strchr(pRight, c) || strchr(pLeft, c))
			{
				return false;
				break;
			}
		}
		else if (g_result[i][0] == 'd')
		{
			if (strchr(pLeft, c) == NULL)
			{
				return false;
				break;
			}
		}

	}
	return true;
}

int main_3()
{
	for (int i = 0; i < 3; ++i)
	{
		cin >> g_left[i] >> g_right[i] >> g_result[i];
	}
	
	for (char c = 'A'; c <= 'L'; ++c)
	{
		if (isFake(c, true))
		{
			cout << c << " is the counterfeit coin and it is light. \n";
			break;
		}

		if (isFake(c, false))
		{
			cout << c << " is the counterfeit coin and it is heavy. \n";
			break;
		}
	}

	system("pause");
	return 0;
}