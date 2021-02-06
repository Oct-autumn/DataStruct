// 本文件为ULLL（全称Universal Linked List Library（通用链表库））的测试代码
//

#include <iostream>
#include "ULLL.h"

int main()
{
    SinglyNode* Head = NULL;
    SinglyNode* NowNode = NULL;

    int a[10] = { 1, 5, 6, 3, 2, 7, 9, 0, 8, 4 };
    
    DataSpace* Buffer = (DataSpace*)malloc(sizeof(DataSpace));

    Buffer->num = a[0];
    NowNode = NewNode_Singly(*Buffer, NowNode);
    Head = NowNode;

    for (int i = 1; i < 10; i++)
    {
        Buffer->num = a[i];
        NowNode = NewNode_Singly(*Buffer, NowNode);
    }

    SinglyListSort(Head, 10, MINtoMAX);

    NowNode = Head;
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", NowNode->Data.num);
        NowNode = NowNode->next;
    }

    return 0;
}