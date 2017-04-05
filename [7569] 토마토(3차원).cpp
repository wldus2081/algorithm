#include <iostream>
#include <queue>
using namespace std;

int box[102][102][102];	//-1:토마토 없음, 0:안익은 토마토, 1:첫번째익은 토마토, 2,3,4...
int maxDay;
int tomato;		//익은 토마토 개수
int totalTmt;	//토마토개수

int ROW;
int COL;
int HEIGHT;

struct point
{
	point(){};
	point(int h, int r, int c)
	{
		height = h;
		row = r;
		col = c;
	}
	int height;
	int row;
	int col;
};
queue<point> que;

void input()
{
	cin >> COL >> ROW >> HEIGHT;
	
	for(int k=0; k<HEIGHT+2 ; k++)
	{
		for(int i=0 ; i<ROW+2 ; i++)
		{
			for(int j=0 ; j<COL+2 ; j++)
			{
				box[k][i][j] = -1;
			}
		}
	}
	
	for(int k=0; k<HEIGHT ; k++)
	{
		for(int i=0 ; i<ROW ; i++)
		{
			for(int j=0 ; j<COL ; j++)
			{
				cin >> box[k+1][i+1][j+1];
				if( box[k+1][i+1][j+1]==1 )
					que.push(point(k+1,i+1,j+1));
				if(box[k+1][i+1][j+1]!=-1)
					totalTmt++;
			}
		}
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
		tomato++;	//익은토마토수 증가
		day = box[p.height][p.row][p.col];		//day: 며칠만에 익은 토마토인가
		if(maxDay < day)	maxDay = day;
		if(box[p.height][p.row+1][p.col]==0)
		{
			box[p.height][p.row+1][p.col] = day+1;
			que.push(point(p.height,p.row+1,p.col));
		}
		if(box[p.height][p.row-1][p.col]==0)
		{
			box[p.height][p.row-1][p.col] = day+1;
			que.push(point(p.height,p.row-1,p.col));
		}
		if(box[p.height][p.row][p.col+1]==0)
		{
			box[p.height][p.row][p.col+1] = day+1;
			que.push(point(p.height,p.row,p.col+1));
		}		
		if(box[p.height][p.row][p.col-1]==0)
		{
			box[p.height][p.row][p.col-1] = day+1;
			que.push(point(p.height,p.row,p.col-1));
		}
				
		if(box[p.height+1][p.row][p.col]==0)
		{
			box[p.height+1][p.row][p.col] = day+1;
			que.push(point(p.height+1,p.row,p.col));
		}	
		if(box[p.height-1][p.row][p.col]==0)
		{
			box[p.height-1][p.row][p.col] = day+1;
			que.push(point(p.height-1,p.row,p.col));
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