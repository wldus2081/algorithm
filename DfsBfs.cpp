#include<iostream>
#include<queue>
#include<stack>

using namespace std;

#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 8
short int visited[MAX_VERTICES];

int graph[MAX_VERTICES][MAX_VERTICES] = 
{{0,1,1,0,0,0,0,0},
 {1,0,0,1,1,0,0,0},
 {1,0,0,0,0,1,1,0},
 {0,1,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,0},
 {0,0,1,0,0,0,0,1},
 {0,0,1,0,0,0,0,1},
 {0,0,0,0,0,1,1,0}};


bool visit[MAX_VERTICES];
void DFS( int v )
{
	visit[v] = true;
	printf( "%5d", v );

	for ( int i = 0; i < MAX_VERTICES; i++ )
	{
		if ( graph[v][i] == 1 && !visit[i] )
		{
			DFS( i );
		}
	}
}

stack<int> stk;
void DFS_s( int v )
{
	stk.push(v);
	visit[v] = true;
	while(!stk.empty())
	{
		int pop = stk.top();
		stk.pop();
		printf("%5d",pop);
		for(int i=0; i<8;i++)
		{
			if(graph[pop][i]==1 && visit[i]==false)
			{
				stk.push(i);
				visit[i] = true;
			}
		}
	}
}



queue<int> que;
void BFS( int v )
{
	int i;

	visit[v] = true;
	printf( "%5d", v );
	que.push( v );
	while ( !que.empty() )
	{
		v = que.front();
		que.pop();
		for ( i = 0; i < MAX_VERTICES; i++ )
		{
			if ( graph[v][i] == 1 && !visit[i] )
			{
				visit[i] = true;
				printf( "%5d", i );
				que.push( i );
			}
		}
	}
}

int main()
{
	DFS(0);
	printf( "\n" );

	for ( int i = 0; i<MAX_VERTICES; i++ )
	{
		visit[i] = false;
	}

	DFS_s(0);
	printf( "\n" );
	for ( int i = 0; i<MAX_VERTICES; i++ )
	{
		visit[i] = false;
	}

	BFS(0);
	printf( "\n" );

	return 0;
}