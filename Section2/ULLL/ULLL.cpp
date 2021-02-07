// 本文件为ULLL（全称Universal Linked List Library（通用链表库））的测试代码
//

#include <iostream>
#include "ULLL.h"

int main()
{
    DoublyNode* Head = NULL;
    DoublyNode* NowNode = NULL;

    int a[10] = { 1, 5, 6, 3, 2, 7, 9, 0, 8, 4 };
    
    DataSpace* Buffer = (DataSpace*)malloc(sizeof(DataSpace));

    Buffer->num = a[0];
    NowNode = NewNode_Doubly(*Buffer, NowNode, NULL);
    Head = NowNode;

    for (int i = 1; i < 10; i++)
    {
        Buffer->num = a[i];
        NowNode = NewNode_Doubly(*Buffer, NowNode, NULL);
    }

    SinglyListSort(Head, 10, MAXtoMIN);

    NowNode = Head;
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", NowNode->Data.num);
        NowNode = NowNode->next;
    }

    return 0;
}