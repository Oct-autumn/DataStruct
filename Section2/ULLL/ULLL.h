//ULLL（全称Universal Linked List Library（通用链表库））

#pragma once

#include <stdio.h>
#include <stdlib.h>

//排序顺序
#define MAXtoMIN 0
#define MINtoMAX 1

#define KEY_NUM(M) M->Data.num

typedef struct DataSpace
{
	int num;
	char str[20];
};



//以下为单向链表部分
typedef struct SinglyNode	//单向链表节点
{
	//数据区（请在下面定义每个节点中的数据变量）
	DataSpace Data;
	//指向下一节点的指针
	SinglyNode* next;
};

//新建节点函数
SinglyNode* NewNode_Singly(DataSpace data, SinglyNode* Before)	//该函数将在 Before节点后 插入新节点
{
	SinglyNode* NewNode = (SinglyNode*)calloc(1, sizeof(SinglyNode));

	//以下代码将数据存入新节点
	NewNode->Data = data;

	if (Before)
	{
		NewNode->next = Before->next;
		Before->next = NewNode;
	}

	return NewNode;
}

//删除节点函数
void DeleteNode(SinglyNode* NodeToDelete)	//该函数将删除NodeToDelete节点
{
	SinglyNode* NextNode = NodeToDelete->next;

	NodeToDelete = NextNode;

	free(NextNode);
}

void SinglyListSort(SinglyNode* Start, int count, int SortOrder)
{//归并排序，使用递归结构
	if (!count || count == 1) return;

	int Count1 = count / 2;
	int Count2 = count - Count1;

	SinglyNode* Start1 = Start;
	SinglyNode* Start2 = Start1;
	for (int i = 0; i < Count1; i++)
	{
		Start2 = Start2->next;
	}

	SinglyListSort(Start1, Count1, SortOrder);
	SinglyListSort(Start2, Count2, SortOrder);

	SinglyNode* Head = NULL;
	SinglyNode* NowNode = NULL;

	if (SortOrder == MAXtoMIN)
	{//降序
		DataSpace* Buffer = (DataSpace*)malloc(sizeof(DataSpace));

		while (Count1 && Count2)
		{
			

			if (KEY_NUM(Start1) > KEY_NUM(Start2))
			{
				*Buffer = Start1->Data;
				NowNode = NewNode_Singly(*Buffer, NowNode);
				Start1 = Start1->next;
				Count1--;
			}
			else
			{
				*Buffer = Start2->Data;
				NowNode = NewNode_Singly(*Buffer, NowNode);
				Start2 = Start2->next;
				Count2--;
			}
			if (!Head) Head = NowNode;
		}

		while (Count1)
		{
			*Buffer = Start1->Data;
			NowNode = NewNode_Singly(*Buffer, NowNode);
			Start1 = Start1->next;
			Count1--;
		}
		while (Count2)
		{
			*Buffer = Start2->Data;
			NowNode = NewNode_Singly(*Buffer, NowNode);
			Start2 = Start2->next;
			Count2--;
		}

		SinglyNode* NowNode_S = Start;
		NowNode = Head;
		for (int i = 0; i < count; i++)
		{
			NowNode_S->Data = NowNode->Data;
			NowNode_S = NowNode_S->next;
			NowNode = NowNode->next;
		}

		free(Buffer);
	}
	else
	{//升序
		DataSpace* Buffer = (DataSpace*)malloc(sizeof(DataSpace));

		while (Count1 && Count2)
		{


			if (KEY_NUM(Start1) < KEY_NUM(Start2))
			{
				*Buffer = Start1->Data;
				NowNode = NewNode_Singly(*Buffer, NowNode);
				Start1 = Start1->next;
				Count1--;
			}
			else
			{
				*Buffer = Start2->Data;
				NowNode = NewNode_Singly(*Buffer, NowNode);
				Start2 = Start2->next;
				Count2--;
			}
			if (!Head) Head = NowNode;
		}

		while (Count1)
		{
			*Buffer = Start1->Data;
			NowNode = NewNode_Singly(*Buffer, NowNode);
			Start1 = Start1->next;
			Count1--;
		}
		while (Count2)
		{
			*Buffer = Start2->Data;
			NowNode = NewNode_Singly(*Buffer, NowNode);
			Start2 = Start2->next;
			Count2--;
		}

		SinglyNode* NowNode_S = Start;
		NowNode = Head;
		for (int i = 0; i < count; i++)
		{
			NowNode_S->Data = NowNode->Data;
			NowNode_S = NowNode_S->next;
			NowNode = NowNode->next;
		}

		free(Buffer);
	}
	
}


//以下为双向链表部分
typedef struct DoublyNode	//单向链表节点
{
	//指向上一节点的指针
	DoublyNode* before;
	//数据区（请在下面定义每个节点中的数据变量）
	DataSpace Data;
	//指向下一节点的指针
	DoublyNode* next;
};

DoublyNode* NewNode_Doubly(DataSpace data, DoublyNode* Before, DoublyNode* Next)	//该函数将在 Before节点后 或 Next节点前 或 Before与Next节点之间 插入新节点
{
	DoublyNode* NewNode = (DoublyNode*)calloc(1, sizeof(DoublyNode));

	//以下代码将数据存入新节点
	NewNode->Data = data;

	if (Before) Before->next = NewNode;
	NewNode->before = Before;
	if (Next) Next->before = NewNode;
	NewNode->next = Next;	

	return NewNode;
}

void DeleteNode(DoublyNode* NodeToDelete)	//该函数将删除NodeToDelete节点
{
	DoublyNode* BeforeNode = NodeToDelete->before;
	DoublyNode* NextNode = NodeToDelete->next;	
	
	if (BeforeNode) BeforeNode->next = NextNode;
	if (NextNode) NextNode->before = BeforeNode;

	NodeToDelete = NextNode;

	free(NextNode);
}