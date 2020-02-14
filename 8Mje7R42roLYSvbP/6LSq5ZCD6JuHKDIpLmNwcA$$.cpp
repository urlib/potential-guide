//(C)2017 HZH2HS Baimahu
#include<iostream> 
#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#define N 21
int wall[N+2][N+2]={{0}};
void gotoxy(int x,int y)//位置函数
{
COORD pos;
pos.X=2*x;
pos.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void color(int a)//颜色函数
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void init(int apple[2])//初始化函数（初始化围墙、显示信息、苹果）
{
int i,j;//初始化围墙
for(i=1;i<=N;i++)
{
for(j=1;j<=N;j++)
wall[i][j]=1;
}
color(11);
for(i=0;i<N+2;i++)
{
for(j=0;j<N+2;j++)
{
if(wall[i][j])
printf("■");
else printf("□");
}
printf("\n");
}
gotoxy(N+3,1);//显示信息
color(11);
printf("按 W S A D 移动方向\n");
gotoxy(N+3,2);
color(11);
printf("按其他的键暂停\n");
gotoxy(N+3,3);
color(11);
printf("得分：\n");
gotoxy(N+3,5);
color(11);
printf("穿墙：\n");
gotoxy(N+3,7);
color(11);
printf("穿身：\n");
apple[0]=rand()%N+1;//苹果
apple[1]=rand()%N+1;
gotoxy(apple[0],apple[1]);
color(12);
printf("■\n");
}
int main()
{
gotoxy(N+6,3);
color(11);
printf("%d\n",0);
gotoxy(N+6,5);
color(11);
printf("%d\n",0);
gotoxy(N+6,7);
color(11);
printf("%d\n",0);
gotoxy(0,0);
color(11);
int i,j;
int** snake=NULL;
int apple[2];
int score=0;
int tail[2];
int len=3;
int cq=0;
int cs=0;
char ch='p';
srand((unsigned)time(NULL));
init(apple);
snake=(int**)realloc(snake,sizeof(int*)*len);
for(i=0;i<len;i++)
snake[i]=(int*)malloc(sizeof(int)*2);

for(i=0;i<len;i++)
{
snake[i][0]=N/2;
snake[i][1]=N/2+i;
gotoxy(snake[i][0],snake[i][1]);
color(14);
printf("■\n");
}

while(1)//进入消息循环
{
gotoxy(apple[0],apple[1]);
color(12);
printf("■\n");
tail[0]=snake[len-1][0];
tail[1]=snake[len-1][1];
gotoxy(tail[0],tail[1]);
color(11);
if(wall[tail[0]][tail[1]])
printf("■\n");
else printf("□\n");
for(i=len-1;i>0;i--)
{
snake[i][0]=snake[i-1][0];
snake[i][1]=snake[i-1][1];
gotoxy(snake[i][0],snake[i][1]);
color(14);
printf("■\n");
}
if(kbhit())
{
gotoxy(0,N+2);
ch=getche();
}
switch(ch)
{
case 'w':snake[0][1]--;break;
case 's':snake[0][1]++;break;
case 'a':snake[0][0]--;break;
case 'd':snake[0][0]++;break;
default: break;
}
for(i=1;i<len;i++)
{
if(snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1] && (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd')){
cs++;

}
}
gotoxy(N+6,7);
color(11);
printf("%d\n",cs);
gotoxy(snake[0][0],snake[0][1]);
color(15);
printf("■\n");
Sleep(abs(200-0.5*score));
if(snake[0][0]==apple[0]&&snake[0][1]==apple[1])//吃掉苹果后蛇分数加1，蛇长加1
{
score++;
len++;
snake=(int**)realloc(snake,sizeof(int*)*len);
snake[len-1]=(int*)malloc(sizeof(int)*2);
snake[len-1][0]=snake[len-2][0];
snake[len-1][1]=snake[len-2][1];
apple[0]=rand()%N+1;
apple[1]=rand()%N+1;
gotoxy(apple[0],apple[1]);
color(12);
printf("■\n");
gotoxy(N+6,3);
color(11);
printf("%d\n",score);
}
if(snake[0][1]<=0||snake[0][1]>=N+1||snake[0][0]<=0||snake[0][0]>=N+1)//撞到围墙后失败
{
cq++;
if(snake[0][1]<=0){
gotoxy(snake[0][0],0);
color(11);
printf("□\n");
snake[0][1]=N+1;
}else if(snake[0][1]>=N+1){
gotoxy(snake[0][0],N+1);
color(11);
printf("□\n");
snake[0][1]=0;
}if(snake[0][0]<=0){
gotoxy(0,snake[0][1]);
color(11);
printf("□\n");
snake[0][0]=N+1;
}else if(snake[0][0]>=N+1){
gotoxy(N+1,snake[0][1]);
color(11);
printf("□\n");
snake[0][0]=0;
}
gotoxy(N+6,5);
color(11);
printf("%d\n",cq);
}
}
return 0;
}
