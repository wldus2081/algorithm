#include <iostream>
using namespace std;

int D[1001];		//2*N ũ���� ���簢���� 1*2, 2*1 Ÿ�Ϸ� ä��� ����� ��
int N;			//1<=n<=1000
#define MOD 10007

/*
D[N]: 2*N ũ���� ���簢���� 1*2, 2*1 Ÿ�Ϸ� ä��� ����� ��
1. D[N] = D[N-1] -> (2*(N-1) ũ���� ���簢���� 2*1 Ÿ�� 1�� ä���
2. D[N] = D[N-2] -> (2*(N-1) ũ���� ���簢���� 1*2 Ÿ�� 2�� ä���

���� : D[N] = sum( D[N-1], D[N-2] ) 
*/

int topDown(int n)
{
	int a=0, b=0;
	if (D[n] > 0) return D[n];
	
	if (n > 0)
		a = (topDown(n - 1));
	if (n > 1)
		b = (topDown(n - 2));

	D[n] = ((a % MOD) + (b % MOD)) % MOD;
	return D[n];
}

void bottomUp()
{
	for (int i = 2; i <= N; i++)
	{
		D[i] = ((D[i - 1] % MOD) + (D[i - 2] % MOD)) % MOD;
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