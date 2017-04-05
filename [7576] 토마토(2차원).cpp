#include <iostream>
#include <queue>
using namespace std;

int box[1002][1002];	//-1:�丶�� ����, 0:������ �丶��, 1:ù��°���� �丶��, 2,3,4...
int maxDay;
int tomato;	//���� �丶�� ����
int totalTmt;	//�丶�䰳��

int ROW;
int COL;

struct point
{
	point(){};
	point(int r, int c)
	{
		row = r;
		col = c;
	}
	int row;
	int col;
};
queue<point> que;

void input()
{
	cin >> COL >> ROW;
	for(int i=0 ; i<ROW+2 ; i++)
	{
		for(int j=0 ; j<COL+2 ; j++)
		{
			box[i][j] = -1;
		}
	}
	
	for(int i=0 ; i<ROW ; i++)
	{
		for(int j=0 ; j<COL ; j++)
		{
			cin >> box[i+1][j+1];
			if(box[i+1][j+1]==1)
				que.push(point(i+1,j+1));
			if(box[i+1][j+1]!=-1)
				totalTmt++;
		}
	}
}

void print()
{
	for(int i=1; i<ROW+1; i++)
	{
		for(int j=1; j<COL+1; j++)
			cout << box[i][j] << "\t";
		cout << endl;
	}
}

void bfs()
{
	point p;
	int day;
	while(!que.empty())
	{
		p = que.front();
		que.pop();
		tomato++;	//�����丶��� ����
		day = box[p.row][p.col];		//day: ��ĥ���� ���� �丶���ΰ�
		if(maxDay < day)	maxDay = day;
		if(box[p.row+1][p.col]==0)
		{
			box[p.row+1][p.col] = day+1;
			que.push(point(p.row+1,p.col));
		}
		if(box[p.row-1][p.col]==0)
		{
			box[p.row-1][p.col] = day+1;
			que.push(point(p.row-1,p.col));
		}
		if(box[p.row][p.col+1]==0)
		{
			box[p.row][p.col+1] = day+1;
			que.push(point(p.row,p.col+1));
		}		
		if(box[p.row][p.col-1]==0)
		{
			box[p.row][p.col-1] = day+1;
			que.push(point(p.row,p.col-1));
		}	
	}
}

int main() {
	totalTmt=0;
	maxDay = 0;
	input();
	//print();
	bfs();
	if(tomato == totalTmt)
		cout << maxDay-1;
	else
		cout << -1;
	return 0;
}