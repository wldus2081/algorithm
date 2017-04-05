#include <iostream>
using namespace std;

int D[11];	//D[N]: 정수N을 1,2,3 합으로 나타내는 방법의 수
int N;
#define MOD 10007
/*
N = N-3 + 3 
N = N-2 + 2
N = N-1 + 1
D[N] = D[N/3]
*/

void bottomUp()
{
	for (int i = 4; i <= N; i++)
	{
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int tc;
	scanf("%d", &tc);
	
	D[1] = 1;	//1
	D[2] = 2;	//1+1,2
	D[3] = 4;	//1+1+1,1+2,2+1,3

	for (int i = 0; i < tc; i++)
	{
		for (int j = 4; j <= N; j++)
		{
			D[j] = 0;
		}
		scanf("%d", &N);

		bottomUp();

		printf("%d\n", D[N]);
	}

	return 0;
}