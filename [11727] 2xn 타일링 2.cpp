#include <iostream>
using namespace std;

int D[1000];	//D[N]: 2xN 직사각형을 2x1과 2x2 타일로 채우는 방법의 수
int N;
#define MOD 10007
/*
D[N] = D[N-2]*2 + D[N-1]
*/

int topDown(int n)
{
	int a, b;
	if (D[n] > 0) return D[n];
	if (n > 0)
		a = topDown(n - 1);
	if (n > 1)
		b = topDown(n - 2) * 2;

	D[n] = ((a%MOD) + (b%MOD)) % MOD;
	return D[n];
}

void bottomUp()
{
	for (int i = 2; i <= N; i++)
	{
		D[i] = (((D[i-1])%MOD) + ((D[i-2]*2)%MOD)) % MOD;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &N);

	D[0] = 1;
	D[1] = 1;
	//topDown(N);
	bottomUp();

	printf("%d", D[N]);

	return 0;
}