#include<iostream>

#define MAX_DIST 999999
#define MAX_VERTICES 8
int cost[MAX_VERTICES][MAX_VERTICES];

int distance[MAX_VERTICES];
bool visit[MAX_VERTICES];

int choose( int n )
{

	int i, min, minpos;
	min = MAX_DIST;
	minpos = -1;
	for ( i = 0; i < n; i++ )
		if ( distance[i] < min && visit[i] == false ) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void Dijkstra( int start )
{
	int i, shtDist, w;

	for ( i = 0; i < MAX_VERTICES; i++ )
	{
		visit[i] = false;
		distance[i] = cost[start][i];	//연결된 곳의 비용을 distance에 넣는다.
	}
	visit[start] = true;
	distance[start] = 0;
	for ( i = 0; i < MAX_VERTICES -2; i++ ) {
		shtDist = choose( MAX_VERTICES ); // 연결된 경로 중, 최단 경로 선택

		visit[shtDist] = true;

		//현재까지 계산한 비용으로 최단거리 다시 계산
		for ( w = 0; w < MAX_VERTICES; w++ )
			if ( visit[w] == false)
				if ( distance[shtDist] + cost[shtDist][w] < distance[w] )
					 distance[w] = distance[shtDist] + cost[shtDist][w];
	}
}

void makeGraph()
{
	for ( int i = 0; i < MAX_VERTICES; i++ )
		for ( int j = 0; j < MAX_VERTICES; j++ )
			cost[i][j] = MAX_DIST;

	cost[1][0] = 300;
	cost[2][0] = 1000;
	cost[2][1] = 800;
	cost[3][2] = 1200;
	cost[4][3] = 1500;
	cost[4][5] = 250;
	cost[5][3] = 1000;
	cost[5][6] = 900;
	cost[5][7] = 1400;
	cost[6][7] = 1000;
	cost[7][0] = 1700;
}

void main()
{
	makeGraph();

	int start = 4;
	Dijkstra( start );

	int shtDist;
	for(int i=0; i<MAX_VERTICES ; i++)
	{
		if ( i == start ) continue;
		shtDist = distance[i];
		if( shtDist == MAX_DIST )
			printf( "%d -> %d 최단거리:없음 \n", start, i );
		else
			printf( "%d -> %d 최단거리:%d \n", start, i, shtDist );
	}
	return;
}