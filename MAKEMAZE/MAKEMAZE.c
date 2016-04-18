#include<stdio.h>

int mat[21][21]={0};
struct queue{
	int x;
	int y;
};

typedef struct queue Q;

int main()
{

	int T;
	int M,N;
	int i,j;
	int x;
	int end_points=0;
	int start_x,start_y,end_x,end_y;
	scanf("%d",&T);
	while(T--)
	{
		end_points=0;
		scanf("%d%d",&M,&N);
		for(i=0;i<M;i++)
		{       getchar();
			for(j=0;j<N;j++)
			{
				x = getchar();
				if(x=='#')
					mat[i][j]=1;
				//if(x=='.' || x==' ')
				//      mat[i][j]=0;
				if((i==0 || j==0 || i == M-1 || j==N-1) && mat[i][j]==0)
				{
					end_points++;
					if(end_points==1)
					{
						start_x=i;start_y=j;
					}
					if(end_points==2)
					{
						end_x=i;end_y=j;
					}
				}
			}
		}
		if(!(end_points==2))
			printf("invalid\n");
		else
		{
			if(bfs(mat,start_x,start_y,end_x,end_y,M,N))
				printf("valid\n");
			else
				printf("invalid\n");
		}
		for(i=0;i<M;i++)
			for(j=0;j<N;j++)
				mat[i][j]=0;

	}

	return(0);
}

int bfs(int mat[][21], int start_x, int start_y,int end_x,int end_y, int M,int N)
{
	Q queue[1000]={0};
	int visited[21][21]={0};
	int front,rear;
	int v_x,v_y;
	int i;
	int t;
	front = -1;
	rear = -1;
	visited[start_x][start_y] = 1;

	front = 0;
	rear = 0;
	queue[rear].x = start_x;
	queue[rear].y = start_y;
	//      front = front + 1;

	while(front <= rear )
	{
		v_x = queue[front].x;
		v_y = queue[front].y;
		if(v_x==end_x && v_y == end_y)
			return(1);
		front++;
		//printf("%d %d -->",v_x+1,v_y+1);
		visited[v_x][v_y] = 1;

		if(v_x-1>=0 && visited[v_x-1][v_y] == 0 && mat[v_x-1][v_y]==0)
		{
			visited[v_x-1][v_y] = 1;
			t = ++rear;
			queue[t].x = v_x-1;
			queue[t].y = v_y;
		}
		if(v_x+1 <= M-1 && visited[v_x+1][v_y] == 0 && mat[v_x+1][v_y]==0)
		{
			visited[v_x+1][v_y] = 1;
			t = ++rear;
			queue[t].x = v_x + 1;
			queue[t].y = v_y;
		}
		if(v_y-1>=0 && visited[v_x][v_y-1] == 0 && mat[v_x][v_y-1]==0)
		{
			visited[v_x][v_y-1] = 1;
			t = ++rear;
			queue[t].x = v_x;
			queue[t].y = v_y - 1;
		}
		if(v_y+1 <= N-1 && visited[v_x][v_y+1] == 0 && mat[v_x][v_y+1]==0)
		{
			visited[v_x][v_y+1] = 1;
			t = ++rear;
			queue[t].x = v_x;
			queue[t].y = v_y + 1;
		}

	}
	return(0);
}

