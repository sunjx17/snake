#include"conh.h"
#include <memory.h>
int delay;//SleepMilsec
//const int shead='';
char mapc[20][41];
#ifdef VK_UP
#undef VK_UP
#define VK_UP 72
#endif
#ifdef VK_DOWN
#undef VK_DOWN
#define VK_DOWN 80
#endif
#ifdef VK_LEFT
#undef VK_LEFT
#define VK_LEFT 75
#endif
#ifdef VK_RIGHT
#undef VK_RIGHT
#define VK_RIGHT 77
#endif
typedef struct npyy{
	SHORT X;
	SHORT Y;
	struct npyy* last;
	struct npyy* next;
	}COORD2;
COORD2 *headxy;
COORD2 *bodies;
COORD bds[400];
int headpos;
int lens;
#define headc (BACKGROUND_BLUE|BACKGROUND_GREEN)
#define initlc (FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE)
#define blackc (BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED)
#define setc SetConsoleColor
BOOL SetConsoleColor(WORD wAttributes);
BOOL SetConsoleColor(WORD wAttributes)  
	{  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
	if (hConsole == INVALID_HANDLE_VALUE)  
		return FALSE;
	return SetConsoleTextAttribute(hConsole, wAttributes);  
	}
void fillxy(COORD cords[],int n,WORD color,int x);
void fillxy(COORD cords[],int n,WORD color,int x){
	int i;
	COORD cx;
	setc(color);
	for(i=1;i<=n;++i){
		cx.X =2*cords[i-1].X-1;
		cx.Y =cords[i-1].Y ;
		gotoc(cx);
		putc(x,stdout);
		putc(x,stdout);
		}
	}

void givemap();
void givemap(){
	int x,y;
	for(x=0;x<20;++x){
		for(y=0;y<41;++y)printf("%c",mapc[x][y]);
		printf("\n");
		}
	}

void randxy(WORD,WORD,COORD*);
void randxy(WORD xlim,WORD ylim,COORD*c){
	WORD x,y;

	xlim--;
	ylim--;
	x=(bodies->X +rand())%xlim+1;
	y=(bodies->Y +rand())%ylim+1;
	c->X =x;
	c->Y =y;


	}


void gofo();
void gofo(){
	COORD2*tmp=headxy;
	COORD corx[1],*cor=&corx[0];
	headxy=(COORD2*)malloc(sizeof(COORD2));
	int x=0,y=0,i,flag=0;
	switch(headpos){
		case VK_UP:y=-1;break;
		case VK_DOWN:y=1;break;
		case VK_LEFT:x=-1;break;
		case VK_RIGHT:x=1;break;
		}
	headxy->X =x+tmp->X;
	headxy->Y =y+tmp->Y;
	headxy->last =NULL;
	headxy->next =tmp;
	mapc[tmp->Y][tmp->X*2]='#';
	mapc[tmp->Y][tmp->X*2-1]='#';

	if(mapc[headxy->Y][2*headxy->X ]=='a'||mapc[headxy->Y][2*headxy->X-1]=='a')
		{lens++;
	flag++;
	do{
		randxy(19,19,cor);
		}while(mapc[cor->Y][2*cor->X ]=='#'||mapc[cor->Y][2*cor->X ]=='1');
	fillxy(cor,1,blackc,'a');
	mapc[cor->Y][cor->X*2]='a';
	mapc[cor->Y][cor->X*2-1]='a';
		}
	cor[0].X =headxy->X;
	cor[0].Y =headxy->Y;
	fillxy(cor,1,headc,' ');
	cor[0].X =tmp->X;
	cor[0].Y =tmp->Y;
	tmp->last=headxy;

	fillxy(cor,1,blackc,' ');

	if(!flag){
		COORD2*tm=bodies;
		bodies=bodies->last;
		cor[0].X =tm->X;
		cor[0].Y =tm->Y;
		fillxy(cor,1,initlc,' ');	
		mapc[tm->Y][tm->X*2]=' ';
		mapc[tm->Y][tm->X*2-1]=' ';
		}


	}

void starts();
void starts(){
	char c[][41]={
		{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
		};
	memcpy(mapc,c,820);
	givemap();
	COORD cor[1];
	headpos=VK_DOWN;
	headxy=(COORD2*)malloc(sizeof(COORD2));
	headxy->X =10;
	headxy->Y =10;
	mapc[10][20]='1';
	mapc[10][19]='1';
	cor[0].X =headxy->X;
	cor[0].Y =headxy->Y;
	fillxy(cor,1,headc,' ');
	lens=2;
	bodies=(COORD2*)malloc(sizeof(COORD2));
	bodies->next =NULL;
	bodies->X =10;
	bodies->Y =9;
	cor->X =10;
	cor->Y =9;
	fillxy(cor,1,blackc,' ');
	mapc[9][20]='#';
	mapc[9][19]='#';
	headxy->next =bodies;
	bodies->last =headxy;
	headxy->last =NULL;
	do{
		randxy(19,19,cor);
		}while(mapc[cor->Y][2*cor->X ]=='#'||mapc[cor->Y][2*cor->X ]=='1');
	fillxy(cor,1,blackc,'a');
	mapc[cor->Y][cor->X*2]='a';
	mapc[cor->Y][cor->X*2-1]='a';
	}

int bitmyself(){
	if(headxy->Y>=19||headxy->Y<=0||headxy->X>19||headxy->X<=0)return 1;
	else if(mapc[headxy->Y][headxy->X*2]=='#')return 1;
	else {

		mapc[headxy->Y][headxy->X*2]='1';
		mapc[headxy->Y][headxy->X*2-1]='1';
		return 0;
		}
	}