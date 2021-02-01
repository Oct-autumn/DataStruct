#pragma once

#include <stdio.h>
#include <stdlib.h>

//排序顺序
#define MAXtoMIN 0
#define MINtoMAX 1


//以下为单向链表部分
typedef struct SinglyNode	//单向链表节点
{
	//数据区（请在下面定义每个节点中的数据变量）
	int num;

	//指向下一节点的指针
	SinglyNode* next;
};

//新建节点函数
SinglyNode* NewNode_Singly(int data/*...应填入待存储数据*/, SinglyNode* Before)	//该函数将在Before节点后插入新节点
{
	SinglyNode* NewNode = (SinglyNode*)calloc(1, sizeof(SinglyNode));

	//以下代码将数据存入新节点
	NewNode->num = data;

	NewNode->next = Before->next;
	Before->next = NewNode;

	return NewNode;
}

//删除节点函数
void DeleteNode(SinglyNode* NodeToDelete)	//该函数将删除NodeToDelete节点
{
	SinglyNode* NextNode = NodeToDelete->next;

	NodeToDelete = NextNode;

	free(NextNode);
}

//排序函数
void ListSort(SinglyNode* Head, int SortOrder)
{

}



//以下为双向链表部分
typedef struct DoublyNode	//单向链表节点
{
	//指向上一节点的指针
	DoublyNode* before;
	//数据区（请在下面定义每个节点中的数据变量）

	//指向下一节点的指针
	DoublyNode* next;
};

