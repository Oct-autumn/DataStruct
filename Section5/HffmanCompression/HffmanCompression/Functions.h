#pragma once
#include <string.h>

char FilePath_open[MAX_STRING_LONG] = { "D:\\TestFile.tes" };
char FilePath_save[MAX_STRING_LONG] = { "D:\\TestFile.hff" };

void error_p(const char* msg, const char* func_name)
{
	setcolor(LWHITE, LRED);
	printf("Error:");
	setcolor(LRED);
	printf(" %s\n", msg);
	setcolor(LWHITE, LRED);
	printf("From:");
	setcolor(LRED);
	printf(" %s\n", func_name);
	setcolor();
}

void exit(FILE* FileP_open, FILE* FileP_save)
{
	cls();
	//善后收尾，关闭打开的文件
	if (FileP_open) fclose(FileP_open);
	if (FileP_save) fclose(FileP_save);
	printf("EXIT\n");
	PETC(2);
}

int menu()
{
	cls();
	printf("********************************\n");
	printf("*            Welcome           *\n");
	printf("* Functions:                   *\n");
	printf("*   1:Compression              *\n");
	printf("*   2:DeCompression            *\n");
	printf("*                              *\n");
	printf("*   0:Exit                     *\n");
	printf("********************************\n");
	printf("\n");
L1:	printf("Please select function: ");
	int option;
	scanf_s("%d", &option);
	switch (option)
	{
	case 0:case 1:case 2:
		return option;
	default:
		goto L1;
	}
	
}

FILE* file_open()
{
	FILE* FileP;
	
	/*
	printf("Pleas Enter the path of file that you want to Compression:(Example: D:\\TestFile.txt)\n");
	scanf_s("%s", FilePath_open, MAX_STRING_LONG);
	*/
	fopen_s(&FileP, FilePath_open, "rb");

	if (!FileP)
	{
		error_p("File does not exit", "file_open");
		PETC(2);
		return NULL;
	}
	else
	{
		return FileP;
	}
}

FILE* file_save()
{
	char option;
	FILE* FileP;

L2:	printf("Do you want to save the compressed file at the same floder?(Y/N) ");
	
	scanf_s("%c", &option);
	switch (option)
	{
	case 'Y':case 'y'://将源文件的路径更改后缀名后存入FilePath_save中
		strcpy_s(FilePath_save, "");
		for (int i = 0; i < strlen(FilePath_open); i++)
		{
			if (FilePath_open[i] == '.') break;
			FilePath_save[i] = FilePath_open[i];
			FilePath_save[i + 1] = '\0';
		}		
		strcat_s(FilePath_save, ".hff");
		break;
	case 'N':case 'n'://由用户输入存储路径
L3:		printf("Pleas Enter the path of file that you want to save:(Example: D:\\TestFloder\\TestFile)\n");
		scanf_s("%s", FilePath_save, MAX_STRING_LONG);
		strcat_s(FilePath_save, ".hff");
		break;
	default:
		goto L2;
		break;
	}
	
	fopen_s(&FileP, FilePath_save, "wb");
	if (!FileP)
	{
		error_p("Fail to creat new file.", "file_save");
		getchar();
L4:		printf("Do you want to retry?(Y/N) ");		
		scanf_s("%c", &option);
		switch (option)
		{
		case 'Y':case 'y':
			goto L3;
			break;
		case 'N':case 'n':
			PETC(2);
			return NULL;
			break;
		default:
			goto L4;
			break;
		}
	}
	return FileP;
}

void filecompress(FILE* File_open, FILE* File_save, int mode)
{
	FILE
}