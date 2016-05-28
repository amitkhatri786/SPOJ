#include<stdio.h>

#define MAX_SIZE 105


int bfs(int start_x, int start_y,int end_x,int end_y, int N,int M);

struct queue{
	int x;
	int y;
};
typedef struct queue Q;

int path[4][2]={
	{1,0},
	{-1,0},
	{0,1},
	{0,-1},
};

int mat[MAX_SIZE][MAX_SIZE];

int main()
{

	int i,j,k;
	int N,M;
	int ans;
	int r,c;
	int T;
	char t;
	int start_x,start_y,end_x,end_y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&M,&N);
		//      scanf("%d%d%d%d",&start_x,&start_y,&end_x,&end_y);
		getchar();
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				if(j==N-1)
					scanf("%c\n",&t);
				else
					scanf("%c",&t);
				if(t=='$')
				{
					start_x=i;
					start_y=j;
					mat[i][j]=1;
				}
				if(t=='#')
				{
					end_x=i;
					end_y=j;
					mat[i][j]=1;
				}
				if(t=='\n')
					break;
				if(t=='O')
					mat[i][j]=1;
				if(t=='*')
					mat[i][j]=0;

			}
		}
		//      printf("start_x =%d and start_y = %d end points are %d %d\n",start_x,start_y,end_x,end_y);
		ans = bfs(start_x,start_y,end_x,end_y,M,N);
		//printf("Shortest path is %d \n",distace[end_x-1][end_y-1]);
		printf("%d\n",ans);
	}
	return(0);
}

int bfs(int start_x, int start_y,int end_x,int end_y, int M,int N)
{
	Q queue[MAX_SIZE*MAX_SIZE]={0};
	int visited[MAX_SIZE][MAX_SIZE]={0};
	int distace[MAX_SIZE][MAX_SIZE]={0};
	int front,rear;
	int v_x,v_y;
	int i;
	int t;
	int temp_x,temp_y;
	front = -1;
	rear = -1;
	visited[start_x][start_y] = 1;

	front = 0;
	rear = 0;
	queue[rear].x = start_x;
	queue[rear].y = start_y;

	while(front <= rear )
	{
		v_x = queue[front].x;
		v_y = queue[front].y;
		front++;
		//              printf("%d %d\n",v_x+1,v_y+1);

		if(v_x==end_x && v_y==end_y){
			//              printf("return from here %d %d\n",end_x,end_y);
			return(distace[end_x][end_y]);
		}

		visited[v_x][v_y] = 1;
		for(i=0;i<4;i++)
		{
			temp_x = path[i][0];
			temp_y = path[i][1];
			if(isvalid_location(v_x+temp_x,v_y+temp_y,M,N) && visited[v_x+temp_x][v_y+temp_y] == 0)
			{
				//                              printf("temp_x = %d, temp_y = %d  >>>",temp_x,temp_y);
				visited[v_x+temp_x][v_y+temp_y] = 1;
				distace[v_x+temp_x][v_y+temp_y] = distace[v_x][v_y] + 1;
				t = ++rear;
				queue[t].x = v_x+temp_x;
				queue[t].y = v_y+temp_y;
			}
		}
	}
	return(-1);
}

int isvalid_location(int x,int y,int M,int N)
{

	if(x>=0 && y>=0 && x<=M-1 && y<= N-1 && mat[x][y]==1)
		return(1);
	else
		return(0);

}
