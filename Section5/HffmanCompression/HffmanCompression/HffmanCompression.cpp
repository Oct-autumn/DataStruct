// HffmanCompression.cpp : 哈夫曼压缩测试
//
#define MAX_STRING_LONG 1024

#include <stdio.h>

#include "CMDctrl.h"
#include "Functions.h"

int main()
{
    FILE* FileP_open = NULL;
    FILE* FileP_save = NULL;
Menu:switch (menu())
    {
    case 1://压缩
        cls();

        //打开待压缩文件
        FileP_open = file_open();
        if (!FileP_open) goto Menu;

        //选择压缩类型
        int Comp_type;
        printf("Please select the Compress type:(4/8/16) ");
        scanf_s("%d", &Comp_type);

        //确定压缩后文件保存位置
        FileP_save = file_save();
        if (FileP_save == NULL)
        {
            exit(FileP_open, FileP_save);
            return 0;
        }

        //开始压缩文件
        filecompress(FileP_open, FileP_save, Comp_type);
        break;
    case 2://解压缩
        cls();
        FileP_open = file_open();
        if (!FileP_open) goto Menu;
        break;
    case 0://退出
        exit(FileP_open,FileP_save);
        return 0;
    default:
        goto Menu;
        break;
    }

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
