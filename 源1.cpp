#include<iostream>
#include<queue>//ʹ��queue����
using namespace std;

struct Node  //ÿ�����������x,y�����ͨ��������
{
	char x, y, time,dirc;
	bool no_stone;
};

char map[15][15], c;//����һ����ά���飬��ʾ���̣�c��ʾ���ڵĳַ�
int dir[4][2] = { {0,1},{1,0},{1,-1},{1,1} };//�ĸ��������һ��

//BFS����
bool bfs(int x, int y) {
	quene<Node> Q;//��������ΪNode��Q����
	Node first, next;//�����һ����������һ������
	int i;
	first.x = x;
	first.y = y;
	first.no_stone = false;//�˶��������Ӳ��ǿն���
	first.time = 1;//��¼�Ѿ�ʶ�𵽼�������
	first.dirc = -1;//����
	Q.push(first);//����һ��ʶ�𵽵Ķ������

	while (!Q.empty()) {//ֻҪջ���վ�ѭ��
		first = Q.front;//��������Ԫ�ص�ֵ����first
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
				if (next.x >= 0 && next.x < 15 && next.y >= 0 && next.y < 15)//��֤û���߳�����
				{
					next.dirc = i;//��������
					next.time = first.time + 1;//ʶ�������������+1
					//����ʶ�������ӣ��Լ����ӺͿ�������no_stone����
					if��map[next.x][next.y] == c��//�������������һ�����Ӻͳַ�������ͬ��
					{
						next.no_stone = first.no_stone;
						Q.push(next);//����һ���������
					}
					else if (map[next.x][next.y] == '.' && !first.no_stone)//�����һ�������ǿ��ҵ�һ��Ҳ�ǿ�
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
	scanf("%d", &T);//��������
	which(T--) {
		int i, j;
		int white_num = 0, black_num = 0;//��ʼ���ڰ���������
		getchar();//����һ���س���
		for (i = 0, i < 15; i++)
		{
			gets(map[i]);//������������
		}
		for (i = 0; i < 15; i++)
		{
			for (j = 0; j < 15; j++)
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
				if (map[i][j] == c)//��������Ϊ�ַ�������ô������㿪ʼBFS��ֱ���������ϵ����гַ����ӱ�����
				{
					flag=!bfs(i,j)��//��������flag=false,���Ӳ�����flag=true
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