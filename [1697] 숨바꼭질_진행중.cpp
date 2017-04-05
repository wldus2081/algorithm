#include <iostream>
using namespace std;

int subin, sister;
int d[100000];

int go(int n)
{
	if (n == sister) return 0;
	if (n == 0) return 0;
	if (n == 100000) return 0;

	int temp;

	if (d[n] > 0) return d[n];
	d[n] = go(n - 1) + 1;
	temp = go(n + 1) + 1;
	if (d[n] > temp) d[n] = temp;

	temp = go(n*2) + 1;
	if (d[n] > temp) d[n] = temp;

	return d[n];
}

int main()
{
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d %d", &subin, &sister);

	go(subin);
	printf("%d", d[sister]);
		
	return 0;
}