#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;


int D[3][100000];		//D[0][L] : L���� ù��° �� ��, �ι�° �� �ȶ�
						//D[1][L] : L���� ù��° �� �ȶ�, �ι�° �� ��
						//D[2][L] : L���� ù��° �� �ȶ�, �ι�° �� �ȶ�
int score[2][100000];
int N;
#define MOD 10007
/*
max(D[0~2][0~99999])
*/

void bottomUp()
{
	for (int i = 1; i < 100000; i++)
	{
		D[0][i] = D[1][i - 1] > D[2][i - 1] ? D[1][i - 1] : D[2][i - 1];
		D[1][i] = D[0][i - 1] > D[2][i - 1] ? D[0][i - 1] : D[2][i - 1];
		D[2][i] = D[0][i - 1] > D[1][i - 1] ? D[0][i - 1] : D[1][i - 1];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		for (int j = 0; j < 100000; j++)
		{
			D[0][j] = 0;
			D[1][j] = 0;
			D[2][j] = 0;
		}

		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &score[0][j]);
		}
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &score[1][j]);
		}

		D[0][0] = score[0][0];
		D[1][0] = score[1][0];
		D[2][0] = 0;
		bottomUp();

		printf("%d\n", );
	}

	return 0;
}