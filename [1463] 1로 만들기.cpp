#include <iostream>
using namespace std;

int D[1000000];	//D[N]: N을 1로 만드는데 사용한 연산의 최소횟수
int N;

/*
1. D[N] = D[N/3] + 1
2. D[N] = D[N/2] + 1
3. D[N] = D[N-1] + 1

정답: D[N] = min( D[N/3] + 1, D[N/2] + 1, D[N-1] + 1 )
*/

int go(int n)
{
	int temp, min = 0;
	if (D[n] > 0) return D[n];
	if (n == 1) return 0;
	min = go(n - 1) + 1;
	if (n % 3 == 0)
	{
		temp = go(n / 3) + 1;
		if (min > temp)
			min = temp;
	}


	if (n % 2 == 0)
	{
		temp = go(n / 2) + 1;
		if (min > temp)
			min = temp;
	}
	D[n] = min;
	return D[n];
}

int main()
{
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &N);

	go(N);

	printf("%d", D[N]);
		
	return 0;
}


/*
	d[1] = 0;
	for( int i=2 ; i<=n; i++)
	{
		d[i] = d[i-1] +1;
		if(i%2 ==0 && d[i] > d[i/2] +1) 
		{
			d[i] = d[i/2] +1;
		}
		if(i%3 ==0 && d[i] > d[i/3] +1) 
		{
			d[i] = d[i/3] +1;
		}
*/
