#include <iostream>
#include <cstdlib>

using namespace std;

int N;
int queenPos[100];


// 0 -- k-1行都已经被摆好
void NQueen(int k)
{
	if (k == N) // N 个皇后已经摆好
	{
		for (int i = 0; i < N; ++i)
		{
			cout << queenPos[i] + 1 << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; ++i) //逐个尝试第k个皇后的位置
	{
		int j;
		for (j = 0; j < k; ++j)
		{	
			//和已经摆好的 k 个皇后的位置比较, 看是否冲突
			if (i == queenPos[j] || abs(queenPos[j] - i) == abs(k - j))
			{
				break;
			}
		}
		if (j == k) //说明满足条件正常结束循环, i不冲突
		{
			queenPos[k] = i;//将第 k 个皇后摆放在位置i
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