// LinkedList.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "LinkedList.h"



int main(void)
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;
		
	/*int num = 100;
	int *ptr_num = &num;

	printf("Value : %#x\n", ptr_num);
	printf("Value : %d\n", *ptr_num);	
	printf("Value : %#x\n", &ptr_num);*/

	for (i = 0; i < 5; i++)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	NewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&List, NewNode);

	NewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&List, NewNode);

	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
	
	printf("\nInserting 3000 After [2]...\n\n");

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);

	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	printf("\nInserting 5000 Before [3]...\n\n");

	Current = SLL_GetNodeAt(List, 3);
	NewNode = SLL_CreateNode(5000);
	SLL_InsertBefore(&List, Current, NewNode);

	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	/*printf("\nDestroying List...\n\n");

	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, 0);
		if (Current != NULL)
		{
			SLL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}
	}*/

	printf("\nDestroying All Nodes...\n\n");

	SLL_DestroyAllNodes(&List);

	Count = SLL_GetNodeCount(List);
	printf("\nRemain Node Count : %d\n\n", Count);

    return 0;
}

Node * SLL_CreateNode(ElementType _newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->Data = _newData;
	newNode->NextNode = NULL;

	return newNode;
}

void SLL_DestroyNode(Node * node)
{
	free(node);
}

void SLL_AppendNode(Node ** _head, Node * _newNode)
{
	if ((*_head) == NULL)
	{
		*_head = _newNode;
	}
	else
	{
		Node* tail = (*_head);
		while (tail->NextNode != NULL)
		{
			tail = tail->NextNode;
		}

		tail->NextNode = _newNode;
	}
}

void SLL_InsertAfter(Node * Current, Node * NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node ** Head, Node * NewHead)
{
	if ((*Head) == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

void SLL_RemoveNode(Node ** Head, Node * Remove)
{
	if ( *Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
		{
			Current->NextNode = Remove->NextNode;
		}
	}
}

Node * SLL_GetNodeAt(Node * Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

int SLL_GetNodeCount(Node * Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

void SLL_InsertBefore(Node** _Head, Node* _Current, Node* _NewNode)
{
	if ((*_Head) == NULL)
	{
		*_Head = _NewNode;
	}
	else
	{
		Node* PrevNode = (*_Head);

		while (PrevNode->NextNode != _Current)
		{
			PrevNode = PrevNode->NextNode;
		}

		PrevNode->NextNode = _NewNode;
		_NewNode->NextNode = _Current;
	}
}

void SLL_DestroyAllNodes(Node** _List)
{
	if ((*_List) == NULL)
		return;

	Node* Current = (*_List);
	Node* NewHead = Current->NextNode;
	while (NewHead != NULL)
	{
		if (Current != NULL)
		{
			SLL_DestroyNode(Current);
			Current = NULL;
		}
		
		Current = NewHead;
		NewHead = Current->NextNode;
	}

	(*_List) = NewHead;
}