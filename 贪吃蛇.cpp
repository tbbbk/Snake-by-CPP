#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;
const int m_size=25;
int result,smap[m_size][m_size];
int dx[5]={0,0,-1,1,0},dy[5]={0,1,0,0,-1},difficulty;

class tbk
{
	public:
		int length;
		int state; 
		char head;
		char body;
		char food;
		char frame;
		int head_x;
		int head_y; 
}snake;

int random();
void init();
void set_food();
void draw();
int command();

int main()
{
	system("color 0A"); 
	printf("Welcome you to play my first game\n\n");
	Sleep(700);
	printf("                    coded by tbk \n");
	printf("                   2022/1/6 night\n\n");
	Sleep(700);
	printf("Enter the Difficulty of this game(1-5)\n");
	printf("(1 is the most difficult)\n");
	cin>>difficulty;
	Sleep(100);
	system("color 0A");
	system("cls");
	init();
	while(1)
	{
		result=command();
		if(result==0)
		{
			system("cls");
			system("color 0A");
			printf("\n             Game Over\n\n");
			Sleep(1500);
			system("pause");
			break;
		}
		else
		{
			if(result==2)
				set_food();
			system("cls");
			draw();
		}
		Sleep(100*difficulty);
	}
	return 0;
}
int random()
{
	int num=rand()%(m_size-2)+1;
	return num;
}

void init()
{
	srand((int)time(NULL));
	snake.length=3;
	snake.state=3;
	snake.head='+';
	snake.body='*'; 
	snake.food='$';
	snake.frame='?';
	snake.head_x=3;
	snake.head_y=5; 
	smap[5][3]=snake.length;
	smap[5][2]=smap[5][3]-1;
	smap[5][1]=smap[5][3]-2;
	set_food();
	for(int i=0;i<m_size;i++)
		smap[0][i]=smap[m_size-1][i]=-2;
	for(int i=1;i<=m_size-2;i++)
		smap[i][0]=smap[i][m_size-1]=-2;
	return;
}

void set_food()
{
	int x,y;
	while(1)
	{
		x=random(),y=random();
		if(smap[y][x]==0)
			break;
	}
	smap[y][x]=-1;
	return;
}

int command()
{
	int tmp;
	if(_kbhit())
	{
		switch(tolower(_getch()))
		{
			case 's':tmp=1;break;
			case 'a':tmp=2;break;
			case 'd':tmp=3;break;
			case 'w':tmp=4;break;
		}
		if(tmp+snake.state!=5)
			snake.state=tmp;
	}
	
	int new_head=smap[snake.head_y+dy[snake.state]][snake.head_x+dx[snake.state]];
	if(new_head!=0&&new_head!=-1)
		return 0;
	else
	{
		snake.head_y+=dy[snake.state],snake.head_x+=dx[snake.state];
		smap[snake.head_y][snake.head_x]=snake.length+1;
		if(new_head!=-1)
		{
			for(int i=1;i<=m_size-2;i++)
				for(int j=1;j<=m_size-2;j++)
					if(smap[i][j]>0)
						smap[i][j]--;
			return 1;
		}
		else
		{
			snake.length++;
			return 2;
		}
	}
	
}

void draw()
{
	for(int i=0;i<m_size;i++)
	{
		for(int j=0;j<m_size;j++)
			if(smap[i][j]==0)
				cout<<' ';
			else if(smap[i][j]==snake.length)
				cout<<snake.head;
			else if(smap[i][j]==-1)
				cout<<snake.food;
			else if(smap[i][j]==-2)
				cout<<snake.frame;
			else
				cout<<snake.body;
		cout<<endl;
	}
	return;
}
