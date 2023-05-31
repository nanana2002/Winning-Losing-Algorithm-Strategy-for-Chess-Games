/*#include<iostream>
using namespace std;
#include<queue>//ʹ��queue����
#define MAX 5
extern int i, j;
struct Node  //ÿ�����������x,y�����ͨ��������
{
	char x, y, time, dirc;
	bool no_stone;
};

char map[MAX][MAX] = { 'B','Z','Z','Z','Z','B','W','Z','Z','Z','B','W','Z','Z','Z','B','W','Z','Z','Z' ,'B','W','Z','Z','Z' }, c;//����һ����ά���飬��ʾ���̣�c��ʾ���ڵĳַ�
int dir[4][2] = { {0,1},{1,0},{1,-1},{1,1} };//�ĸ��������һ��

//BFS����
bool bfs(int x, int y) {
	int num = 0;
	queue<Node> Q;//��������ΪNode��Q����
	Node first, next;//�����һ����������һ������
	int i;
	first.x = x;
	first.y = y;
	first.no_stone = false;//�˶��������Ӳ��ǿն���
	first.time = 1;//��¼�Ѿ�ʶ�𵽼�������
	first.dirc = -1;//����
	Q.push(first);//����һ��ʶ�𵽵Ķ������

	while (!Q.empty()) {//ֻҪջ���վ�ѭ��
		first = Q.front();//��������Ԫ�ص�ֵ����first
		Q.pop();//������Ԫ�س���
		//�ӵ�һ���㿪ʼ����֤����ֻ��5��������һ��ģ���no_stone ��ʾû�ж���
		if (first.time == 5 && first.no_stone)//����Ѿ�ʶ��5����ͬ������û�ж���
		{
			return true;//Ӯ��
		}
		for (i = 0; i < 4; i++) {
			//��ʼ����ȷ��
			if (first.dirc == -1 || first.dirc == i)//��û��ʼ�������ǻ�û������
			{
				next.x = first.x + dir[i][0];//�ӵ�ǰλ����Ҫʶ��ķ�����һ��������һ������
				next.y = first.y + dir[i][1];
				if (next.x >= 0 && next.x < MAX && next.y >= 0 && next.y < MAX)//��֤û���߳�����
				{
					next.dirc = i;//��������
					next.time = first.time + 1;//ʶ�������������+1
					//����ʶ�������ӣ��Լ����ӺͿ�������no_stone����
					if (map[next.x][next.y] == c)//�������������һ�����Ӻͳַ�������ͬ��
					{
						next.no_stone = first.no_stone;
						Q.push(next);//����һ���������
						printf("�����ڶ������%d��%d��%c\n", next.x, next.y, map[next.x][next.y]);
						num = num + 1;
					}
					else if (map[next.x][next.y] == 'Z' && !first.no_stone)//�����һ�������ǿ��ҵ�һ��Ҳ�ǿ�
					{
						next.no_stone = true;
						Q.push(next);
						printf("�����ڶ������%d��%d��%c\n", next.x, next.y, map[next.x][next.y]);
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
	printf("��������������");
	scanf_s("%d", &T);//��������
	int i, j;
	int white_num = 0, black_num = 0;//��ʼ���ڰ���������
	printf("����������");
	for (i = 0; i < MAX; i++)
	{
		printf("���������ӵ�%d��",i);
		for (j = 0; j < MAX; j++)
			cin >> map[i][j];
		
	}

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (map[i][j] == 'W')
			{
				white_num++;//����������һ
			}
			else if (map[i][j] == 'B')
			{
				black_num++;
			}
		}

	}//��¼�ڰ����ӵĸ������ж����ڵĳַ��Ǻ��ǰ�
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
				if (map[i][j] == c)//��������Ϊ�ַ�������ô������㿪ʼBFS��ֱ���������ϵ����гַ����ӱ�����
				{
					flag = !bfs(i, j);//��������flag=false,���Ӳ�����flag=true
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
//�ڶ���
/*
#include<iostream>
using namespace std;
#include<queue>//ʹ��queue����
#define MAX 6
extern int i, j;
struct Node  //ÿ�����������x,y�����ͨ��������
{
	char x, y;
	bool no_stone;
};

char map[MAX][MAX] = { {'W','B','Z','Z','Z','Z'} ,{'Z','W','Z','Z','Z','B'},{'B','Z','W','Z','Z','Z'},{'B','Z','Z','W','Z' ,'Z'},{'Z','Z','Z','Z','W','Z'},{'Z','Z','Z','Z','W','Z'} }, c;//����һ����ά���飬��ʾ���̣�c��ʾ���ڵĳַ�
int dir[4][2] = { {0,1},{1,0},{1,-1},{1,1} };//�ĸ��������һ��


bool found(int x, int y) {
	int num = 1;
	queue<Node> Q;//��������ΪNode��Q����
	Node first, next;//�����һ����������һ������
	int i;
for (i = 0; i < 4; i++) {
	first.x = x;
	first.y = y;
	Q.push(first);//����һ��ʶ�𵽵Ķ������


	while (!Q.empty()) {//ֻҪ�Ӳ��վ�ѭ��
		first = Q.front();//��������Ԫ�ص�ֵ����first
		Q.pop();//������Ԫ�س���
		//�ӵ�һ���㿪ʼ����֤����ֻ��5��������һ��ģ���no_stone ��ʾû�ж���
		if (num==5)//����Ѿ�ʶ��5����ͬ������û�ж���
		{
			return true;//Ӯ��
		}

			//��ʼ����ȷ��
				next.x = first.x + dir[i][0];//�ӵ�ǰλ����Ҫʶ��ķ�����һ��������һ������
				next.y = first.y + dir[i][1];
				printf("����Ϊ��%d��%d\ti=%d\n", dir[i][0], dir[i][1], i);
				if (next.x >= 0 && next.x < MAX && next.y >= 0 && next.y < MAX)//��֤û���߳�����
				{	
					
					//����ʶ���������������
					if (map[next.x][next.y] == c)//�������������һ�����Ӻͳַ�������ͬ��
					{
						Q.push(next);//����һ���������
						printf("�����ڶ������%d��%d��%c\n", next.x, next.y, map[next.x][next.y]);
						num = num + 1;
					}
					else if (map[next.x][next.y] == 'Z' && !first.no_stone)//�����һ�������ǿ��ҵ�һ��Ҳ�ǿ�
					{
						Q.push(next);
						printf("�����ڶ������%d��%d��%c\n", next.x, next.y, map[next.x][next.y]);
					}
				}
		}
	}
	return false;
}

bool main()
{
	int T;
	printf("��������������");
	scanf_s("%d", &T);//��������
	int i, j;
	int white_num = 0, black_num = 0;//��ʼ���ڰ���������


	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (map[i][j] == 'W')
			{
				white_num++;//����������һ
			}
			else if (map[i][j] == 'B')
			{
				black_num++;
			}
		}

	}//��¼�ڰ����ӵĸ������ж����ڵĳַ��Ǻ��ǰ�
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
				if (map[i][j] == c)//��������Ϊ�ַ�������ô������㿪ʼ������ֱ���������ϵ����гַ����ӱ�����
				{
					printf("���Ϊ%d��%d��%c\n", i, j, map[i][j]);
					flag = found(i, j);//��������flag=true,���Ӳ�����flag=false
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
//������
/*
#include<iostream>
using namespace std;
#include<queue>//ʹ��queue����
#define MAX 6
extern int i, j;
struct Node  //ÿ�����������x,y�����ͨ��������
{
	char x, y;
	bool no_stone;
};

char map[MAX][MAX] = { {'W','B','Z','Z','Z','Z'} ,{'Z','W','Z','Z','Z','B'},{'B','Z','W','Z','Z','Z'},{'B','Z','Z','W','Z' ,'Z'},{'Z','Z','Z','Z','W','Z'},{'Z','Z','Z','Z','W','Z'} }, c;//����һ����ά���飬��ʾ���̣�c��ʾ���ڵĳַ�
int dir[4][2] = { {0,1},{1,0},{1,-1},{1,1} };//�ĸ��������һ��


bool found(int x, int y) {
	int num = 1;
	queue<Node> Q;//��������ΪNode��Q����
	Node first, next;//�����һ����������һ������
	int i;
	for (i = 0; i < 4; i++) {
		first.x = x;
		first.y = y;
		Q.push(first);//����һ��ʶ�𵽵Ķ������


		while (!Q.empty()) {//ֻҪ�Ӳ��վ�ѭ��
			first = Q.front();//��������Ԫ�ص�ֵ����first
			Q.pop();//������Ԫ�س���
			//�ӵ�һ���㿪ʼ����֤����ֻ��5��������һ��ģ���no_stone ��ʾû�ж���
			if (num == 5)//����Ѿ�ʶ��5����ͬ����
			{
				return true;//Ӯ��
			}

			//��ʼ����ȷ��
			next.x = first.x + dir[i][0];//�ӵ�ǰλ����Ҫʶ��ķ�����һ��������һ������
			next.y = first.y + dir[i][1];
			printf("����Ϊ��%d��%d\ti=%d\n", dir[i][0], dir[i][1], i);
			if (next.x >= 0 && next.x < MAX && next.y >= 0 && next.y < MAX)//��֤û���߳�����
			{

				//����ʶ���������������
				if (map[next.x][next.y] == c)//�������������һ�����Ӻͳַ�������ͬ��
				{
					Q.push(next);//����һ���������
					printf("�����ڶ������%d��%d��%c\n", next.x, next.y, map[next.x][next.y]);
					num = num + 1;
				}
				else //�����һ�������ǿջ���һ����
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
	printf("��������������");
	scanf_s("%d", &T);//��������
	int i, j;
	int white_num = 0, black_num = 0;//��ʼ���ڰ���������
	Node dirc[MAX / 2 + 1] ;//������ʶ�������

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
				white_num++;//����������һ
			}
			else if (map[i][j] == 'B')
			{
				black_num++;
			}
		}

	}//��¼�ڰ����ӵĸ������ж����ڵĳַ��Ǻ��ǰ�
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
				if (map[i][j] == c)//��������Ϊ�ַ�������ô������㿪ʼ������ֱ���������ϵ����гַ����ӱ�����
				{
					printf("���Ϊ%d��%d��%c\n", i, j, map[i][j]);
					flag = found(i, j);//��������flag=true,���Ӳ�����flag=false
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
struct Node  //ÿ�����������x,y�����ͨ��������
{
	char x, y;
};

char map[MAX][MAX] = { {'W','B','Z','Z','Z','Z'} ,{'Z','W','Z','Z','Z','B'},{'B','Z','W','Z','Z','Z'},{'B','Z','Z','W','Z' ,'Z'},{'Z','Z','Z','Z','W','Z'},{'Z','Z','Z','Z','W','Z'} }, c;//����һ����ά���飬��ʾ���̣�c��ʾ���ڵĳַ�
int dir[4][2] = { {0,1},{1,0},{1,-1},{1,1} };//�ĸ��������һ��

void make_next(string pattern, int* next)
{
	int q, k;               //q��ƥ���λ��,k��ǰ׺��ʼ�ĵط�
	int m = pattern.size(); //�ؼ��ֵĳ���

	next[0] = 0; //���ڼ�¼�ؼ�������ǰ׺ƥ�����ϵ�λ��
	for (q = 1, k = 0; q < m; q++)
	{ //q�Ǻ������,k��ǰ׺��ʼ�ĵط�
		while (k > 0 && pattern[q] != pattern[k])
		{ //������������ǰ׺��ͬʱ,ǰ׺��-1����ƥ��
			k = next[k - 1];
		}

		if (pattern[q] == pattern[k])
		{ // ���ǰ׺���������ͬ�ַ�
			k++;
		}
		next[q] = k; //���ڼ�¼�ؼ�������ǰ׺ƥ�����ϵ�λ��
	}
}

//kmp�㷨
int kmp(string text, string pattern, int* next)
{
	int n = MAX;    //�ı����ĳ���
	int m = 5; //�ؼ��ֵĳ���

	make_next(pattern, next); //�ڹؼ����м�¼��ǰ׺ƥ������,��¼��next����

	int i, q;
	for (i = 0, q = 0; i < n; i++)
	{ //i --> text, q --> pattern
		while (q > 0 && pattern[q] != text[i])
		{                    //���ƥ��ʧ��,��ǰ����ǰ׺��ͬ��ϵ�λ��
			q = next[q - 1]; //ֻҪnext[q-1]������0,��ô���ǻ�û�ҵ���ǰ׺��ͬ�����
		}                    //������ѭ�����ҵ���ǰ׺��ͬ�����,ֱ��next[q-1]����0

		if (pattern[q] == text[i])
		{ //���ƥ����ȷ,�ؼ���λ��+1
			q++;
		}

		if (q == m)
		{                     //���q��λ���ǹؼ��ֵĳ���,��ô�����ҵ��ַ�����
			return i - q + 1; //�����ַ�����λ��
		}
	}
	return -1; //�����ı������궼û���ҵ��ַ���,����-1
}

int found(int x, int y,char c) {
	int i;
	int j;
	int k;
	char str1[MAX];
	char str2[5] = {'c','c','c','c','c'};//�������ַ��������������鴮
	for (i = 0; i < 4; i++) {
		j = 0;
			while (j < MAX) 
			{
				if (dir[i][0] + x < MAX && dir[i][1] + y < MAX)
				{
					x = x + dir[i][0];
					y = y + dir[i][1];
					str1[j] = map[x][y];//�ӵ�ǰλ����Ҫʶ��ķ�����һ��������һ������,�����������
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
	printf("��������������");
	scanf_s("%d", &T);//��������
	int i, j;
	int white_num = 0, black_num = 0;//��ʼ���ڰ���������

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (map[i][j] == 'W')
			{
				white_num++;//����������һ
			}
			else if (map[i][j] == 'B')
			{
				black_num++;
			}
		}

	}//��¼�ڰ����ӵĸ������ж����ڵĳַ��Ǻ��ǰ�
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
				if (map[i][j] == c)//��������Ϊ�ַ�������ô������㿪ʼ������ֱ���������ϵ����гַ����ӱ�����
				{
					printf("���Ϊ%d��%d��%c\n", i, j, map[i][j]);
					flag = found(i, j,c);//��������flag=true,���Ӳ�����flag=false
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