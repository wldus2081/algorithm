#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

long long D[91][2];	//D[N][L] : L(0�Ǵ�1)�� ������, ���̰� N�ڸ��� ��ģ���� ��
int N;
/*
D[N][0] = D[N-1][0] + D[N-1][1]
D[N][1] = D[N-1][0]

����: D[N][0]+D[N][1]
*/

void bottomUp()
{
	for (int i = 2; i <= N; i++)
	{
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &N);

	D[1][0] = 0;
	D[1][1] = 1;
	bottomUp();

	printf("%lld\n", D[N][0] + D[N][1]);

	return 0;
}