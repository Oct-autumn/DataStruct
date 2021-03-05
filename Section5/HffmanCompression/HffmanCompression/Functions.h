#pragma once
#include <string.h>
#include <stdlib.h>

typedef struct DataRecord
{
	unsigned short int Data;
	unsigned int Count;
};

char FilePath_open[MAX_STRING_LONG] = { "D:\\TestFile.tes" };
char FilePath_save[MAX_STRING_LONG] = { "D:\\TestFile.hff" };

//报错函数
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

//退出函数
void exit(FILE* FileP_open, FILE* FileP_save)
{
	cls();
	//善后收尾，关闭打开的文件
	if (FileP_open) fclose(FileP_open);
	if (FileP_save) fclose(FileP_save);
	printf("EXIT\n");
	PETC(2);
}

//菜单函数
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

//打开文件函数
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

//保存文件函数
FILE* file_save()
{
	char option;
	FILE* FileP;

L2:	printf("Do you want to save the compressed file at the same floder?(Y/N) ");
	
	getchar();
	scanf_s("%c", &option);
	switch (option)
	{
	case 'Y':case 'y'://将源文件的路径更改后缀名后存入FilePath_save中
		strcpy_s(FilePath_save, "");

		for (int i = strlen(FilePath_open); i >=0; i--)//获取文件名类型分隔点的位置
		{
			if (FilePath_open[i] == '.')
			{
				for (int j = 0; j < i; j++)//将源路径(除了文件类型)复制到新路径中
				{
					FilePath_save[j] = FilePath_open[j];
				}
				strcat_s(FilePath_save, ".hff");//加上后缀名
				break;
			}
		}		
		break;
	case 'N':case 'n'://由用户输入存储路径
L3:		printf("Pleas Enter the path of file that you want to save:(Example: D:\\TestFloder\\TestFile)\n");
		scanf_s("%s", FilePath_save, MAX_STRING_LONG);
		
		for (int i = strlen(FilePath_open); i >= 0; i--)//此层循环找到文件名的起点
		{
			if (FilePath_open[i] == '\\')
			{
				int k = strlen(FilePath_save);
				for (int j = i; j <= strlen(FilePath_open); j++)//此层循环将源文件名拼接到到新路径后
				{
					if (FilePath_open[j] == '.') break;
					FilePath_save[k] = FilePath_open[j];
					k++;
				}
				FilePath_save[k] = '\0';//添加终止符，以使用strcat
				strcat_s(FilePath_save, ".hff");
				break;
			}
		}
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

//数据统计函数
DataRecord* CountData(FILE* FileP, int mode)
{
	DataRecord* DataCount = NULL;
	switch (mode)//由压缩模式创建相应大小的统计数组并进行初始化
	{
	case 4:
		DataCount = (DataRecord*)malloc(sizeof(DataRecord) * 16);
		for (unsigned short int i = 0; i < 16; i++)
		{
			DataCount[i].Data = i;
			DataCount[i].Count = 0;
		}
		break;
	case 8:
		DataCount = (DataRecord*)malloc(sizeof(DataRecord) * 256);
		for (unsigned short int i = 0; i < 256; i++)
		{
			DataCount[i].Data = i;
			DataCount[i].Count = 0;
		}
		break;
	case 16:
		DataCount = (DataRecord*)malloc(sizeof(DataRecord) * 65536);
		for (unsigned short int i = 0; i < 65536; i++)
		{
			DataCount[i].Data = i;
			DataCount[i].Count = 0;
		}
		break;
	}

	while (1)
	{
		unsigned short int Data;
		if (fread(&Data, mode / 4, 1, FileP) != mode / 4)
		{

		}

		DataCount[Data].Count++;//借由数组的有序性快速定位并计数
	}

	

	return DataCount;
}

void filecompress(FILE* File_open, FILE* File_save, int mode)
{
	
}