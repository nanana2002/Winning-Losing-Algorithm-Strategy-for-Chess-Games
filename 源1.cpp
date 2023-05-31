#include<iostream>
#include<queue>//使用queue容器
using namespace std;

struct Node  //每个顶点的坐标x,y最大连通数、方向
{
	char x, y, time,dirc;
	bool no_stone;
};

char map[15][15], c;//定义一个二维数组，表示棋盘，c表示现在的持方
int dir[4][2] = { {0,1},{1,0},{1,-1},{1,1} };//四个方向解释一下

//BFS搜索
bool bfs(int x, int y) {
	quene<Node> Q;//建立类型为Node的Q队列
	Node first, next;//定义第一个顶点与下一个顶点
	int i;
	first.x = x;
	first.y = y;
	first.no_stone = false;//此顶点有棋子不是空顶点
	first.time = 1;//记录已经识别到几个棋子
	first.dirc = -1;//方向
	Q.push(first);//将第一个识别到的顶点入队

	while (!Q.empty()) {//只要栈不空就循环
		first = Q.front;//将队列首元素的值赋给first
		Q.pop();//队列首元素出队
		//从第一个点开始，保证有且只有5个是连在一起的，用no_stone 表示没有多连
		if (first.time == 5 && first.no_stone)//如果已经识别到5个相同棋子且没有多练
		{
			return true;//赢了
		}
		for (i = 0; i < 4; i++) {
		//初始方向不确定
			if (first.dirc == -1 || first.dirc == i)//还没开始遍历或是还没遍历完
			{
				next.x = first.x + dir[i][0];//从当前位置向要识别的方向走一步就是下一个顶点
				next.y = first.y + dir[i][1];
				if (next.x >= 0 && next.x < 15 && next.y >= 0 && next.y < 15)//保证没有走出棋盘
				{
					next.dirc = i;//换个方向
					next.time = first.time + 1;//识别过的棋子数量+1
					//不标识对手棋子，自己棋子和空棋子用no_stone区分
					if（map[next.x][next.y] == c）//如果这个方向的下一个棋子和持方棋子相同则
					{
						next.no_stone = first.no_stone;
						Q.push(next);//将下一个顶点入队
					}
					else if (map[next.x][next.y] == '.' && !first.no_stone)//如果下一个顶点是空且第一个也是空
					{
						next.no_stone = true;
						Q.push(next);
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);//棋子数量
	which(T--) {
		int i, j;
		int white_num = 0, black_num = 0;//初始化黑白棋子数量
		getchar();//读入一个回车键
		for (i = 0, i < 15; i++)
		{
			gets(map[i]);//按行输入棋子
		}
		for (i = 0; i < 15; i++)
		{
			for (j = 0; j < 15; j++)
			{
				if (map[i][j] == 'W')
				{
					white_num++;//白棋数量加一
				}
				else if (map[i][j] == 'B')
				{
					black_num++;
				}
			}
		}//记录黑白棋子的个数，判断现在的持方是黑是白
		if (black_num > white_num)
		{
			c = 'W';
		}
		else
		{
			c = 'B';
		}
		bool flag = true;
		for (i = 0; i < 15 && flag; i++)
		{
			for (j = 0; j < 15 && flag; j++)
			{
				if (map[i][j] == c)//如果这个点为持方棋子那么从这个点开始BFS，直到将棋盘上的所有持方棋子遍历完
				{
					flag=!bfs(i,j)；//五子连珠flag=false,五子不连珠flag=true
				}
			}
		}
		if (flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}