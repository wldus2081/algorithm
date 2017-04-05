#include <iostream>
using namespace std;

int allCmp;
int computer[100][100] = {0};
int zombie = 0;
bool visited[100] = {false};

void R(int cmp)
{
	visited[cmp] = true;
	for(int j=0; j<allCmp; j++)
	{
		if(visited[j]==false && computer[cmp][j] == 1)
		{	
			R(j);
			zombie++;
		}
	}
}

int main() {
	int pair,a,b;
	cin >> allCmp;
	cin >> pair;
	
	for(int i =0; i<pair ; i++)
	{
		cin >> a >> b;
		computer[a][b] = 1;
		computer[b][a] = 1;
	}
	
	R(1);
	
	cout << zombie;
	return 0;
}