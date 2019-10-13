#include <iostream>
#include <cstdlib>

using namespace std;

int N;
int queenPos[100];


// 0 -- k-1�ж��Ѿ����ں�
void NQueen(int k)
{
	if (k == N) // N ���ʺ��Ѿ��ں�
	{
		for (int i = 0; i < N; ++i)
		{
			cout << queenPos[i] + 1 << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; ++i) //������Ե�k���ʺ��λ��
	{
		int j;
		for (j = 0; j < k; ++j)
		{	
			//���Ѿ��ںõ� k ���ʺ��λ�ñȽ�, ���Ƿ��ͻ
			if (i == queenPos[j] || abs(queenPos[j] - i) == abs(k - j))
			{
				break;
			}
		}
		if (j == k) //˵������������������ѭ��, i����ͻ
		{
			queenPos[k] = i;//���� k ���ʺ�ڷ���λ��i
			NQueen(k + 1);
		}
	}
}

int main_2()
{
	cin >> N;
	NQueen(0);

	system("pause");
	return 0;
}