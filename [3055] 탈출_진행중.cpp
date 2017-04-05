#include <iostream>
#include <vector>
#include <queue>
int ROW; // <= 50
int COL; // <= 50
using namespace std;
enum m{ EMPTY=0, ROCK, BEAVER, WATER, HOG };
int map[52][52];	//-1: map아님 , 0:비어있는칸 , 1:돌 , 2:비버 굴, 3: 물, 4: 고슴도치 위치 

struct point {
	point() {};
	point(int r, int c)
	{
		row = r;
		col = c;
	}
	int row;
	int col;
};

queue<point> w;		//물 위치
queue<point> q;		//고슴도치 위치

void input()
{
	char str[51];
	scanf("%d %d", &ROW, &COL);


	for (int i = 0; i < ROW+2; i++)
		for (int j = 0; j < COL+2; j++)
			map[i][j] = -1;


	for (int i = 0; i < ROW; i++)
	{
		scanf("%s", str);
		for (int j = 0; j < COL; j++)
		{
			if (str[j] == 'D')
				map[i + 1][j + 1] = BEAVER;
			else if (str[j] == '.')
				map[i + 1][j + 1] = EMPTY;
			else if (str[j] == 'X')
				map[i + 1][j + 1] = ROCK;
			else if (str[j] == '*')
			{
				map[i + 1][j + 1] = WATER;
				w.push(point(i + 1, j + 1));
			}
			else//S
			{
				map[i + 1][j + 1] = HOG;
				q.push(point(i + 1, j + 1));
			}
		}
	}

}

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void water()
{
	int cnt = w.size();
	point p;
	int r, c;
	for (int i = 0; i < cnt; i++)
	{
		p = w.front();
		w.pop();
		r = p.row; c = p.col;
		for (int j = 0; j < 4; j++)
		{
			if (map[r + dy[j]][c + dx[j]] == EMPTY || map[r + dy[j]][c + dx[j]] >= HOG)
			{
				map[r + dy[j]][c + dx[j]] = WATER;
				w.push(point(r + dy[j], c + dx[j]));
			}
		}
	}
}

void print()
{
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			cout << map[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

int bfs()
{
	point p;
	int r, c, mapInfo;
	int cnt = 0;
	int preHog = 0;
	while (!q.empty())
	{
		p = q.front();
		r = p.row; c = p.col;


		while (map[r][c] == WATER)
		{
			q.pop();
			if (q.empty())
				return 0;
			p = q.front();
			r = p.row; c = p.col;
		}


		for (int i = 0; i < 4; i++)
		{
			if (map[r + dx[i]][c + dy[i]] == EMPTY)
			{
				map[r + dx[i]][c + dy[i]] = map[r][c] + 1;
				q.push(point(r + dx[i], c + dy[i]));
			}
			else if (map[r + dx[i]][c + dy[i]] == BEAVER)
			{
				return ++cnt;
			}
		}

		if (map[r][c] >= HOG && preHog < map[r][c])
		{
			preHog = map[r][c];
			water();
			cnt++;
			//print();
		}

		
		q.pop();

	}
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);


	input();
	int cnt = bfs();
	if (cnt)
		cout << cnt << endl;
	else
		cout << "KAKTUS" << endl;
		
	return 0;
}