/*#include<iostream>
using namespace std;
#include<queue>//使用queue容器
#define MAX 5
extern int i, j;
struct Node  //每个顶点的坐标x,y最大连通数、方向
{
	char x, y, time, dirc;
	bool no_stone;
};

char map[MAX][MAX] = { 'B','Z','Z','Z','Z','B','W','Z','Z','Z','B','W','Z','Z','Z','B','W','Z','Z','Z' ,'B','W','Z','Z','Z' }, c;//定义一个二维数组，表示棋盘，c表示现在的持方
int dir[4][2] = { {0,1},{1,0},{1,-1},{1,1} };//四个方向解释一下

//BFS搜索
bool bfs(int x, int y) {
	int num = 0;
	queue<Node> Q;//建立类型为Node的Q队列
	Node first, next;//定义第一个顶点与下一个顶点
	int i;
	first.x = x;
	first.y = y;
	first.no_stone = false;//此顶点有棋子不是空顶点
	first.time = 1;//记录已经识别到几个棋子
	first.dirc = -1;//方向
	Q.push(first);//将第一个识别到的顶点入队

	while (!Q.empty()) {//只要栈不空就循环
		first = Q.front();//将队列首元素的值赋给first
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
				if (next.x >= 0 && next.x < MAX && next.y >= 0 && next.y < MAX)//保证没有走出棋盘
				{
					next.dirc = i;//换个方向
					next.time = first.time + 1;//识别过的棋子数量+1
					//不标识对手棋子，自己棋子和空棋子用no_stone区分
					if (map[next.x][next.y] == c)//如果这个方向的下一个棋子和持方棋子相同则
					{
						next.no_stone = first.no_stone;
						Q.push(next);//将下一个顶点入队
						printf("现在在队里的是%d行%d列%c\n", next.x, next.y, map[next.x][next.y]);
						num = num + 1;
					}
					else if (map[next.x][next.y] == 'Z' && !first.no_stone)//如果下一个顶点是空且第一个也是空
					{
						next.no_stone = true;
						Q.push(next);
						printf("现在在队里的是%d行%d列%c\n", next.x, next.y, map[next.x][next.y]);
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
	printf("请输入棋子数量");
	scanf_s("%d", &T);//棋子数量
	int i, j;
	int white_num = 0, black_num = 0;//初始化黑白棋子数量
	printf("请输入棋子");
	for (i = 0; i < MAX; i++)
	{
		printf("请输入棋子第%d行",i);
		for (j = 0; j < MAX; j++)
			cin >> map[i][j];
		
	}

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
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
	if (black_num < white_num)
	{
		c = 'W';
	}
	else
	{
		c = 'B';
	}
	while(T--) {
		
		bool flag = true;
		for (i = 0; i < MAX && flag; i++)
		{
			for (j = 0; j < MAX && flag; j++)
			{
				if (map[i][j] == c)//如果这个点为持方棋子那么从这个点开始BFS，直到将棋盘上的所有持方棋子遍历完
				{
					flag = !bfs(i, j);//五子连珠flag=false,五子不连珠flag=true
				}
			}
		}
		if (flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}*/
//第二版
/*
#include<iostream>
using namespace std;
#include<queue>//使用queue容器
#define MAX 6
extern int i, j;
struct Node  //每个顶点的坐标x,y最大连通数、方向
{
	char x, y;
	bool no_stone;
};

char map[MAX][MAX] = { {'W','B','Z','Z','Z','Z'} ,{'Z','W','Z','Z','Z','B'},{'B','Z','W','Z','Z','Z'},{'B','Z','Z','W','Z' ,'Z'},{'Z','Z','Z','Z','W','Z'},{'Z','Z','Z','Z','W','Z'} }, c;//定义一个二维数组，表示棋盘，c表示现在的持方
int dir[4][2] = { {0,1},{1,0},{1,-1},{1,1} };//四个方向解释一下


bool found(int x, int y) {
	int num = 1;
	queue<Node> Q;//建立类型为Node的Q队列
	Node first, next;//定义第一个顶点与下一个顶点
	int i;
for (i = 0; i < 4; i++) {
	first.x = x;
	first.y = y;
	Q.push(first);//将第一个识别到的顶点入队


	while (!Q.empty()) {//只要队不空就循环
		first = Q.front();//将队列首元素的值赋给first
		Q.pop();//队列首元素出队
		//从第一个点开始，保证有且只有5个是连在一起的，用no_stone 表示没有多连
		if (num==5)//如果已经识别到5个相同棋子且没有多练
		{
			return true;//赢了
		}

			//初始方向不确定
				next.x = first.x + dir[i][0];//从当前位置向要识别的方向走一步就是下一个顶点
				next.y = first.y + dir[i][1];
				printf("方向为行%d列%d\ti=%d\n", dir[i][0], dir[i][1], i);
				if (next.x >= 0 && next.x < MAX && next.y >= 0 && next.y < MAX)//保证没有走出棋盘
				{	
					
					//不标识对手棋子与空棋子
					if (map[next.x][next.y] == c)//如果这个方向的下一个棋子和持方棋子相同则
					{
						Q.push(next);//将下一个顶点入队
						printf("现在在队里的是%d行%d列%c\n", next.x, next.y, map[next.x][next.y]);
						num = num + 1;
					}
					else if (map[next.x][next.y] == 'Z' && !first.no_stone)//如果下一个顶点是空且第一个也是空
					{
						Q.push(next);
						printf("现在在队里的是%d行%d列%c\n", next.x, next.y, map[next.x][next.y]);
					}
				}
		}
	}
	return false;
}

bool main()
{
	int T;
	printf("请输入棋子数量");
	scanf_s("%d", &T);//棋子数量
	int i, j;
	int white_num = 0, black_num = 0;//初始化黑白棋子数量


	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
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
	if (black_num < white_num)
	{
		c = 'W';
	}
	else
	{
		c = 'B';
	}
	while (T--) {

		bool flag = true;
		for (i = 0; i < MAX && flag; i++)
		{
			for (j = 0; j < MAX && flag; j++)
			{
				if (map[i][j] == c)//如果这个点为持方棋子那么从这个点开始遍历，直到将棋盘上的所有持方棋子遍历完
				{
					printf("起点为%d行%d列%c\n", i, j, map[i][j]);
					flag = found(i, j);//五子连珠flag=true,五子不连珠flag=false
					if (flag)
					{
						if (c == 'W')
						{
							printf("white win\n");
							return true;
						}
						else
						{
							printf("black win\n");
							return true;
						}

					}
					else if (i == 4 && j == 4 && flag == false)
					{
						printf("no\n");
						return false;
					}
				}
			}

		}
	}
}
*/
//第三版
/*
#include<iostream>
using namespace std;
#include<queue>//使用queue容器
#define MAX 6
extern int i, j;
struct Node  //每个顶点的坐标x,y最大连通数、方向
{
	char x, y;
	bool no_stone;
};

char map[MAX][MAX] = { {'W','B','Z','Z','Z','Z'} ,{'Z','W','Z','Z','Z','B'},{'B','Z','W','Z','Z','Z'},{'B','Z','Z','W','Z' ,'Z'},{'Z','Z','Z','Z','W','Z'},{'Z','Z','Z','Z','W','Z'} }, c;//定义一个二维数组，表示棋盘，c表示现在的持方
int dir[4][2] = { {0,1},{1,0},{1,-1},{1,1} };//四个方向解释一下


bool found(int x, int y) {
	int num = 1;
	queue<Node> Q;//建立类型为Node的Q队列
	Node first, next;//定义第一个顶点与下一个顶点
	int i;
	for (i = 0; i < 4; i++) {
		first.x = x;
		first.y = y;
		Q.push(first);//将第一个识别到的顶点入队


		while (!Q.empty()) {//只要队不空就循环
			first = Q.front();//将队列首元素的值赋给first
			Q.pop();//队列首元素出队
			//从第一个点开始，保证有且只有5个是连在一起的，用no_stone 表示没有多连
			if (num == 5)//如果已经识别到5个相同棋子
			{
				return true;//赢了
			}

			//初始方向不确定
			next.x = first.x + dir[i][0];//从当前位置向要识别的方向走一步就是下一个顶点
			next.y = first.y + dir[i][1];
			printf("方向为行%d列%d\ti=%d\n", dir[i][0], dir[i][1], i);
			if (next.x >= 0 && next.x < MAX && next.y >= 0 && next.y < MAX)//保证没有走出棋盘
			{

				//不标识对手棋子与空棋子
				if (map[next.x][next.y] == c)//如果这个方向的下一个棋子和持方棋子相同则
				{
					Q.push(next);//将下一个顶点入队
					printf("现在在队里的是%d行%d列%c\n", next.x, next.y, map[next.x][next.y]);
					num = num + 1;
				}
				else //如果下一个顶点是空或另一棋子
				{	
					break;
					break;
					break;
				}
			}
		}
	}
	return false;
}

bool main()
{
	int T;
	printf("请输入棋子数量");
	scanf_s("%d", &T);//棋子数量
	int i, j;
	int white_num = 0, black_num = 0;//初始化黑白棋子数量
	Node dirc[MAX / 2 + 1] ;//储存已识别的棋子

	for (i = 0; i < MAX / 2 + 1; i++)
	{
		dirc[i].x = -1;
		dirc[i].y = -1;
	}

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
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
	if (black_num < white_num)
	{
		c = 'W';
	}
	else
	{
		c = 'B';
	}
	while (T--) {

		bool flag = true;
		for (i = 0; i < MAX && flag; i++)
		{
			for (j = 0; j < MAX && flag; j++)
			{
				if (map[i][j] == c)//如果这个点为持方棋子那么从这个点开始遍历，直到将棋盘上的所有持方棋子遍历完
				{
					printf("起点为%d行%d列%c\n", i, j, map[i][j]);
					flag = found(i, j);//五子连珠flag=true,五子不连珠flag=false
					if (flag)
					{
						if (c == 'W')
						{
							printf("white win\n");
							return true;
						}
						else
						{
							printf("black win\n");
							return true;
						}

					}
					else if (i == 4 && j == 4 && flag == false)
					{
						printf("no\n");
						return false;
					}
				}
			}

		}
	}
}
*/

#include<iostream>
using namespace std;
#define MAX 6
extern int i, j;
struct Node  //每个顶点的坐标x,y最大连通数、方向
{
	char x, y;
};

char map[MAX][MAX] = { {'W','B','Z','Z','Z','Z'} ,{'Z','W','Z','Z','Z','B'},{'B','Z','W','Z','Z','Z'},{'B','Z','Z','W','Z' ,'Z'},{'Z','Z','Z','Z','W','Z'},{'Z','Z','Z','Z','W','Z'} }, c;//定义一个二维数组，表示棋盘，c表示现在的持方
int dir[4][2] = { {0,1},{1,0},{1,-1},{1,1} };//四个方向解释一下

void make_next(string pattern, int* next)
{
	int q, k;               //q是匹配的位置,k是前缀开始的地方
	int m = pattern.size(); //关键字的长度

	next[0] = 0; //用于记录关键字中与前缀匹配的组合的位置
	for (q = 1, k = 0; q < m; q++)
	{ //q是后面的数,k是前缀开始的地方
		while (k > 0 && pattern[q] != pattern[k])
		{ //当后面的组合与前缀不同时,前缀数-1继续匹配
			k = next[k - 1];
		}

		if (pattern[q] == pattern[k])
		{ // 如果前缀与后面有相同字符
			k++;
		}
		next[q] = k; //用于记录关键字中与前缀匹配的组合的位置
	}
}

//kmp算法
int kmp(string text, string pattern, int* next)
{
	int n = MAX;    //文本串的长度
	int m = 5; //关键字的长度

	make_next(pattern, next); //在关键字中记录与前缀匹配的组合,记录在next数组

	int i, q;
	for (i = 0, q = 0; i < n; i++)
	{ //i --> text, q --> pattern
		while (q > 0 && pattern[q] != text[i])
		{                    //如果匹配失败,往前找与前缀相同组合的位置
			q = next[q - 1]; //只要next[q-1]不大于0,那么就是还没找到与前缀相同的组合
		}                    //继续在循环中找到与前缀相同的组合,直到next[q-1]等于0

		if (pattern[q] == text[i])
		{ //如果匹配正确,关键字位置+1
			q++;
		}

		if (q == m)
		{                     //如果q的位置是关键字的长度,那么就是找到字符串了
			return i - q + 1; //返回字符串的位置
		}
	}
	return -1; //整个文本串找完都没有找到字符串,返回-1
}

int found(int x, int y,char c) {
	int i;
	int j;
	int k;
	char str1[MAX];
	char str2[5] = {'c','c','c','c','c'};//建立最后持方的棋子五子连珠串
	for (i = 0; i < 4; i++) {
		j = 0;
			while (j < MAX) 
			{
				if (dir[i][0] + x < MAX && dir[i][1] + y < MAX)
				{
					x = x + dir[i][0];
					y = y + dir[i][1];
					str1[j] = map[x][y];//从当前位置向要识别的方向走一步就是下一个顶点,将其存入主串
					j++;
				}
				else 
					break;
			}
			int arr[6];
			 k=kmp(str1, str2, arr);
			 return k;
		}
	}

int main()
{
	int T;
	printf("请输入棋子数量");
	scanf_s("%d", &T);//棋子数量
	int i, j;
	int white_num = 0, black_num = 0;//初始化黑白棋子数量

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
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
	if (black_num < white_num)
	{
		c = 'W';
	}
	else
	{
		c = 'B';
	}
	while (T--) {

		bool flag = true;
		for (i = 0; i < MAX && flag; i++)
		{
			for (j = 0; j < MAX && flag; j++)
			{
				if (map[i][j] == c)//如果这个点为持方棋子那么从这个点开始遍历，直到将棋盘上的所有持方棋子遍历完
				{
					printf("起点为%d行%d列%c\n", i, j, map[i][j]);
					flag = found(i, j,c);//五子连珠flag=true,五子不连珠flag=false
					if (flag)
					{
						if (c == 'W')
						{
							printf("white win\n");
							return 0;
						}
						else
						{
							printf("black win\n");
							return 0;
						}

					}
					else if (i == 4 && j == 4 && flag == false)
					{
						printf("no\n");
						return 0;
					}
				}
			}

		}
	}
}