#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

int D[1001];		//D[N]: 붕어빵 i개를 팔 때 최대 이익
int N;
int P[1001];		//붕어빵 i개로 이루어진 세트 메뉴의 가격은 Pi 원
/*
n개를 팔았을 때 최대 이익 = max(D[n-1]+P[1] , D[n-2]+P[2] , D[n-3]+P[3] ,...., D[1]+P[n-1] , P[n])
*/

void bottomUp()
{
	int tmp;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <=i ; j++ )
		{
			tmp = D[i - j] + P[j];
			if (D[i] < tmp)
				D[i] = tmp;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &N);
	int tmp;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &tmp);
		P[i] = tmp;
	}
	D[1] = P[1];
	bottomUp();

	printf("%d\n", D[N]);

	return 0;
}