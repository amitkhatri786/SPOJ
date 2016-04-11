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

	scanf("%d",&T);
	while(T--)
	{
		end_points=0;
		scanf("%d%d",&M,&N);
		for(i=0;i<M;i++)
		{	getchar();
			for(j=0;j<N;j++)
			{
				x = getchar();
				if(x=='#')
					mat[i][j]=1;
				if(x=='.')
					mat[i][j]=0;
				if((i==0 || j==0 || i == M-1 || j==N-1) && mat[i][j]==0)
					end_points++;
			}
		}
		if(end_points>2 || (end_points ==1 && N== 1 && M==1))
			printf("invalid\n");
		else
		{
			bfs(mat,M,N)
		}

	}


	return(0);
}

void bfs(int mat[][21], int start_x, int start_y, int V)
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
    //	front = front + 1;

    while(front <= rear )
    {
	v_x = queue[front].x;
	v_y = queue[front].y;
	front++;
	printf("%d %d -->",v_x+1,v_y+1);
	visited[v_x][v_y] = 1;

	if(v_x-1>=0 && visited[v_x-1][v_y] == 0 && mat[v_x-1][v_y]==1)
	{
	    visited[v_x-1][v_y] = 1;
	    t = ++rear;
	    queue[t].x = v_x-1;
	    queue[t].y = v_y;
	}	
	if(v_x+1 <= V-1 && visited[v_x+1][v_y] == 0 && mat[v_x+1][v_y]==1)
	{
	    visited[v_x+1][v_y] = 1;
	    t = ++rear;
	    queue[t].x = v_x + 1;
	    queue[t].y = v_y;
	}	
	if(v_y-1>=0 && visited[v_x][v_y-1] == 0 && mat[v_x][v_y-1]==1)
	{
	    visited[v_x][v_y-1] = 1;
	    t = ++rear;
	    queue[t].x = v_x;
	    queue[t].y = v_y - 1;
	}	
	if(v_y+1 <= V-1 && visited[v_x][v_y+1] == 0 && mat[v_x][v_y+1]==1)
	{
	    visited[v_x][v_y+1] = 1;
	    t = ++rear;
	    queue[t].x = v_x;
	    queue[t].y = v_y + 1;
	}	


#if 0
	for(i=0;i<V;i++)
	{
	    if(mat[v][i] == 1 && visited[i] == 0)
	    {
		visited[i] = 1;
		queue[++rear] = i;

	    }
	} 
#endif 
    }
}



