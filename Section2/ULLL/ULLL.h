//ULLL��ȫ��Universal Linked List Library��ͨ������⣩��

#pragma once

#include <stdio.h>
#include <stdlib.h>

//����˳��
#define MAXtoMIN 0
#define MINtoMAX 1

#define KEY_NUM(M) M->Data.num

typedef struct DataSpace
{
	int num;
	char str[20];
};



//����Ϊ����������
typedef struct SinglyNode	//��������ڵ�
{
	//���������������涨��ÿ���ڵ��е����ݱ�����
	DataSpace Data;
	//ָ����һ�ڵ��ָ��
	SinglyNode* next;
};

//�½��ڵ㺯��
SinglyNode* NewNode_Singly(DataSpace data, SinglyNode* Before)	//�ú������� Before�ڵ�� �����½ڵ�
{
	SinglyNode* NewNode = (SinglyNode*)calloc(1, sizeof(SinglyNode));

	//���´��뽫���ݴ����½ڵ�
	NewNode->Data = data;

	if (Before)
	{
		NewNode->next = Before->next;
		Before->next = NewNode;
	}

	return NewNode;
}

//ɾ���ڵ㺯��
void DeleteNode(SinglyNode* NodeToDelete)	//�ú�����ɾ��NodeToDelete�ڵ�
{
	SinglyNode* NextNode = NodeToDelete->next;

	NodeToDelete = NextNode;

	free(NextNode);
}

void SinglyListSort(SinglyNode* Start, int count, int SortOrder)
{//�鲢����ʹ�õݹ�ṹ
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
	{//����
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
	{//����
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


//����Ϊ˫��������
typedef struct DoublyNode	//��������ڵ�
{
	//ָ����һ�ڵ��ָ��
	DoublyNode* before;
	//���������������涨��ÿ���ڵ��е����ݱ�����
	DataSpace Data;
	//ָ����һ�ڵ��ָ��
	DoublyNode* next;
};

DoublyNode* NewNode_Doubly(DataSpace data, DoublyNode* Before, DoublyNode* Next)	//�ú������� Before�ڵ�� �� Next�ڵ�ǰ �� Before��Next�ڵ�֮�� �����½ڵ�
{
	DoublyNode* NewNode = (DoublyNode*)calloc(1, sizeof(DoublyNode));

	//���´��뽫���ݴ����½ڵ�
	NewNode->Data = data;

	if (Before) Before->next = NewNode;
	NewNode->before = Before;
	if (Next) Next->before = NewNode;
	NewNode->next = Next;	

	return NewNode;
}

void DeleteNode(DoublyNode* NodeToDelete)	//�ú�����ɾ��NodeToDelete�ڵ�
{
	DoublyNode* BeforeNode = NodeToDelete->before;
	DoublyNode* NextNode = NodeToDelete->next;	
	
	if (BeforeNode) BeforeNode->next = NextNode;
	if (NextNode) NextNode->before = BeforeNode;

	NodeToDelete = NextNode;

	free(NextNode);
}