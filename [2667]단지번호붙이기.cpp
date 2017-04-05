#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[27][27]; // boundary�߰�
bool visited[27][27] = {false};
int size;
int part[312] = {0};//���� �� ���� ������������ �ִ� 312 ������ ����
int num; //���� ��ȣ

void R(int i, int k)
{
	visited[i][k] = true;
	part[num]++; //���� ���� ���� �� 1����
	color[i][k] = num+1;
	
	if	(map[i-1][k]==1 && visited[i-1][k]==false)		R(i-1,k);
	if	(map[i+1][k]==1 && visited[i+1][k]==false)		R(i+1,k);
	if	(map[i][k-1]==1 && visited[i][k-1]==false)		R(i,k-1);
	if	(map[i][k+1]==1 && visited[i][k+1]==false)		R(i,k+1);
}

int main() {
	cin >> size;
	string temp;
	num = 0;
	
	for(int i =0; i<27 ; i++)	//boundary���Ե� map�ʱ�ȭ
	{
		for(int k = 0; k<27 ; k++)
		{
			map[i][k] = -1;
		}
	}
	
	//mapä���
	for(int i =0; i<size ; i++)
	{
		cin >> temp;
		for(int k = 0; k<size ; k++)
		{
			map[i+1][k+1] = atoi(temp.substr(k,1).c_str());
		}
	}

	for(int i=1 ; i<=size; i++)
	{
		for(int k = 1; k<=size ;k++)
		{
			if(map[i][k]==1 && visited[i][k] == false)
			{
				R(i,k);
				num++;
			}
		}
	}
	
	cout << num << endl;
	sort(part,part+num);
	for( int i = 0; i<num ; i++)
	{
		cout << part[i] << endl;
	}

	return 0;
}