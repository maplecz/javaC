#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<bios.h>
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP    0x4800
#define ESC   0x011b
#define ENTER 0x0d
void music(void);
void bear(int,int);
void draw(int,int,int);
void add(int,int,int,int);
void menu(void);
void Init(void);
void Close(void);
void DrawK(void);
void menu1(void);
void Play(void);
void Prscore(void);
int all_key(void);
int score=0,HP=5;
int board[8][8]={0};
int x,y,speed;

void Init(void)
{
      int gdriver=VGA, gmode=VGAHI;
      initgraph(&gdriver, &gmode, "C:\\TC30\\BGI");
      cleardevice();
}

void menu()
{   int n=1,m=1;
    unsigned int keycode;
    settextstyle(0,0,7);
    setcolor(8);
	setcolor(4);outtextxy(45,150,"B");setcolor(14);outtextxy(101,150,"E");
	setcolor(1);outtextxy(157,150,"A");setcolor(2);outtextxy(213,150,"R");
	setcolor(3);outtextxy(269,150,"&");setcolor(4);outtextxy(325,150,"J");
	setcolor(14);outtextxy(381,150,"A");setcolor(1);outtextxy(437,150,"W");
	setcolor(2);outtextxy(493,150,"L");setcolor(3);outtextxy(549,150,"S");
	settextstyle(2,0,9);
	setcolor(4);
	outtextxy(210,250,"START GAME");
	setcolor(14);
	outtextxy(210,300,"LEAVE GAME");
        music();
        setcolor(CYAN);
	line(205,300,390,300);
	setcolor(BLACK);
	line(205,350,390,350);
        while(n){
	bioskey(1);
	if((keycode=all_key())==DOWN){
		setcolor(BLACK);
		line(205,300,390,300);
		setcolor(CYAN);
		line(205,350,390,350);
		m=0;}
		if(keycode==ENTER&&m==0)
		exit(0);
		if(keycode==UP){
		setcolor(CYAN);
	line(205,300,390,300);
	setcolor(BLACK);
	line(205,350,390,350);
	m=1;}
	if(keycode==ENTER&&m==1)
	n=n-1;
	}
	clearviewport();
}

void menu1(void)
{
    int keycode;
    int choose=0;
    x=160,y=140;
    settextstyle(0,0,3);
    setcolor(8);
	outtextxy(240,165,"Easy");
	outtextxy(240,195,"Normal");
	outtextxy(240,225,"Hard");
	outtextxy(240,255,"Quit");
    bear(x,y);
    do
    {
	keycode=all_key();
	if(keycode == UP)
	{
	    if(choose > 0)
	    {
		choose--;
		setfillstyle(SOLID_FILL,0);bar(x,y,x+50,y+50);
		bear(x,y-=30);
	    }
	}
	else if(keycode == DOWN)
	{
	    if(choose < 3)
	    {
		choose++;
		setfillstyle(SOLID_FILL,0);bar(x,y,x+50,y+50);
		bear(x,y+=30);
	    }
	}
    }while(keycode != ENTER );
    switch(choose)
    {
	case 0:
	    speed=450;
	    break;
	case 1:
	    speed=200;
	    break;
	case 2:
	    speed=100;
	    break;
	case 3:
	    cleardevice();
	    exit(0);
    }
    cleardevice();
}

void DrawK(void)
{ int p;
  setcolor(7);
  setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  rectangle(20,20,620,460);
  rectangle(40,40,440,440);
  for(p=40;p<=440;p=p+50){
	line(p,40,p,440);
	line(40,p,440,p);}
  settextstyle(0,0,1);
  outtextxy(450,420,"MOVE:DERECTION ARROW");
  outtextxy(450,430,"Copyright @ 10070515");}


void draw(int i,int j,int a)
{
    int x=i*50+40,y=j*50+40;
    board[4][4]=5;
	board[i][j]=a;
    switch(a)
    {
	case 0:
	    setfillstyle(SOLID_FILL,0);
	    bar(x,y,x+49,y+49);
	    break;
	case 1:
	    setcolor(4);
            setfillstyle(SOLID_FILL,4);
            circle(x+15,y+20,10);
	    floodfill(x+15,y+20,4);
	    circle(x+35,y+20,10);
            floodfill(x+35,y+20,4);
            fillellipse(x+25,y+28,15,10);
            break;
	case 2:
	    setcolor(1);
	    setfillstyle(SOLID_FILL,1);
	    rectangle(x+5,y+5,x+45,y+45);
	    floodfill(x+10,y+10,1);
	    break;
	case 3:
	    setcolor(2);
            setfillstyle(SOLID_FILL,2);
            line(x+25,y+5,x+5,y+45);
            line(x+5,y+45,x+45,y+45);
            line(x+25,y+5,x+45,y+45);
            floodfill(x+25,y+25,2);
	    break;
	case 4:
	    setcolor(YELLOW);
	    setfillstyle(SOLID_FILL,YELLOW);
	    circle(x+25,y+25,20);
            floodfill(x+20,y+20,YELLOW);
		break;
}
}


void Close(void)
{
    getch();
    closegraph();
}

  void bear(int x,int y)
{
   setcolor(6);
   setfillstyle(SOLID_FILL,6);
   circle(x+25,y+30,17);
   floodfill(x+25,y+28,6);
   circle(x+11,y+11,7);
   floodfill(x+10,y+11,6);
   circle(x+40,y+11,7);
   floodfill(x+40,y+11,6);
   setcolor(15);
   setfillstyle(SOLID_FILL,15);
   fillellipse(x+25,y+38,12,8);
   floodfill(x+25,y+38,15);
   setcolor(0);
   setfillstyle(SOLID_FILL,0);
   circle(x+18,y+28,2);
   circle(x+32,y+28,2);
   circle(x+25,y+35,1);
   line(x+25,y+40,x+25,y+40);
   line(x+20,y+40,x+30,y+40);
}



    
void add(int maxh,int maxbar,int maxm,int maxs)
{
    int i,j;
    int h=0,bar=0,m=0,n=0;
    randomize();
    while(h < maxh)
    {
	i=random(8);
	j=random(8);
	if(board[i][j] == 0)
	{
	    draw(i,j,1);
	    h++;
		board[i][j]=1;
	}};
   while(bar < maxbar)
    {
	i=random(8);
	j=random(8);
	if(board[i][j] == 0)
	{
	    draw(i,j,2);
	    bar++;
		board[i][j]=2;
	}};
    while(n < maxs)
    {
	i=random(8);
	j=random(8);
	if(board[i][j] == 0)
	{
	    draw(i,j,3);
	    n++;
	    board[i][j]=3;
	}};
    while(m < maxm)
    {
	i=random(8);
	j=random(8);
	if(board[i][j] == 0)
	{
	    draw(i,j,4);
	    m++;
	    board[i][j]=4;
	}};
}
 
 void main()
{       
	Init();
	menu();
	menu1();
	DrawK();
	Play();
	Close();
}

void Play()
{ unsigned int keycode;  
  long size;
  void *buf;
  x=240,y=240;
  int a;
  int i,j,n=15,sum=15;
  buf=malloc(imagesize(0,0,50,50));
  getimage(x,y,x+50,y+50,buf);
  board[i][j]=5;
  bear(x,y);
  Prscore();
  add(2,5,5,3);

while((keycode=bioskey(0))!=ESC)
  {   putimage(x, y, buf, 0);
	  while(!bioskey(1))
	{  switch(keycode)
	   {
		case UP:y-=50;
			if(y<40){HP--;y+=50;}
			bear(x,y);
			delay(speed);
			putimage(x,y,buf,0);
			break;
		case DOWN:y+=50;
			if(y>390){HP--;y-=50;}
			bear(x,y);
			delay(speed);
			putimage(x,y,buf,0);
			break;
		case LEFT:x-=50;
			if(x<40){HP--;x+=50;}
			bear(x,y);
			delay(speed);
			putimage(x,y,buf,0);
			break;
			case RIGHT:x+=50;
			if(x>390){HP--;x-=50;}
			bear(x,y);
			delay(speed);
			putimage(x,y,buf,0);
			break;
		  }
		Prscore();
		i=(x-40)/50;
		j=(y-40)/50;
	if(board[i][j]!=0)
	{
		switch(board[i][j])
		{
			case 1:HP++;n--;board[i][j]=0;break;
			case 2:HP--;n--;board[i][j]=0;sound(900);delay(50);nosound();break;
			case 3:score+=10;n--;board[i][j]=0;break;
			case 4:score+=50;n--;board[i][j]=0;break;
		 }
	}
	i=random(8);
	j=random(8);
	if(board[i][j]==0){
	if(n<sum){
	draw(i,j,a=random(4)+1);
	n++;
	board[i][j]=a;
	Prscore();} }
		if(HP <= 0)
	{  free(buf);
	   setcolor(0);
	   bar(0,0,640,480);
	   settextstyle(0,0,7);setcolor(4);
	   outtextxy(100,80,"GameOver");
	   settextstyle(0,0,3);setcolor(7);
	   outtextxy(110,350,"Press ESC To Exit");
	   while(!bioskey(1)){
	   if(keycode == ESC)
	   closegraph(); }
	}
	}
  }
}


   




void Prscore(void)
{ gotoxy(60,8);printf("LIFE: %2d",HP);
  gotoxy(60,11);printf("SCORE: %3d",score);
}



int all_key()
{
int keycode;
keycode=bioskey(0);
if(bioskey(2)&0x04){
return keycode;
}
return keycode&0xff? keycode&0xff:keycode;
}

void music()
{	
	int freq;
	for(freq=300;freq<900;freq+=50) {
		sound (freq);
		delay(100);
	}
	nosound();
}




