#pragma once

#include <stdio.h>
#include <stdlib.h>

//����˳��
#define MAXtoMIN 0
#define MINtoMAX 1


//����Ϊ����������
typedef struct SinglyNode	//��������ڵ�
{
	//���������������涨��ÿ���ڵ��е����ݱ�����
	int num;

	//ָ����һ�ڵ��ָ��
	SinglyNode* next;
};

//�½��ڵ㺯��
SinglyNode* NewNode_Singly(int data/*...Ӧ������洢����*/, SinglyNode* Before)	//�ú�������Before�ڵ������½ڵ�
{
	SinglyNode* NewNode = (SinglyNode*)calloc(1, sizeof(SinglyNode));

	//���´��뽫���ݴ����½ڵ�
	NewNode->num = data;

	NewNode->next = Before->next;
	Before->next = NewNode;

	return NewNode;
}

//ɾ���ڵ㺯��
void DeleteNode(SinglyNode* NodeToDelete)	//�ú�����ɾ��NodeToDelete�ڵ�
{
	SinglyNode* NextNode = NodeToDelete->next;

	NodeToDelete = NextNode;

	free(NextNode);
}

//������
void ListSort(SinglyNode* Head, int SortOrder)
{

}



//����Ϊ˫��������
typedef struct DoublyNode	//��������ڵ�
{
	//ָ����һ�ڵ��ָ��
	DoublyNode* before;
	//���������������涨��ÿ���ڵ��е����ݱ�����

	//ָ����һ�ڵ��ָ��
	DoublyNode* next;
};

