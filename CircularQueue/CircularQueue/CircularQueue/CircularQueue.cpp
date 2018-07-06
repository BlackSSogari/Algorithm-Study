// CircularQueue.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
}Node;

typedef struct tagCircularQueue
{
	int Capacity;
	int Front;
	int Rear;
	Node* Nodes;
}CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, int Capacity)
{
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));

	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_DestroyQueue(CircularQueue* Queue)
{
	free(Queue->Nodes);
	free(Queue);
}

void CQ_Enqueue(CircularQueue* Queue, ElementType Data)
{
	int Position = 0;

	if (Queue->Rear == Queue->Capacity + 1)
	{
		Position = Queue->Rear;
		Queue->Rear = 0;
	}
	else
	{
		Position = Queue->Rear++;
		Queue->Nodes[Position].Data = Data;
	}
}

ElementType CQ_Dequeue(CircularQueue* Queue)
{
	int Position = Queue->Front;

	if (Queue->Front == Queue->Capacity)
	{
		Queue->Front = 0;
	}
	else
	{
		Queue->Front++;
	}

	return Queue->Nodes[Position].Data;
}

int CQ_IsEmpty(CircularQueue* Queue)
{
	return (Queue->Front == Queue->Rear);
}

int CQ_IsFull(CircularQueue* Queue)
{
	if (Queue->Front < Queue->Rear)
	{
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	}
	else
	{
		return (Queue->Rear + 1) == Queue->Front;
	}
}

int CQ_GetSize(CircularQueue* Queue)
{
	if (Queue->Front <= Queue->Rear)
		return Queue->Rear - Queue->Front;
	else
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

int main()
{
	int i = 100;
	CircularQueue* Queue;

	CQ_CreateQueue(&Queue, 10);

	CQ_Enqueue(Queue, 1);
	CQ_Enqueue(Queue, 2);
	CQ_Enqueue(Queue, 3);
	CQ_Enqueue(Queue, 4);

	printf("Dequeue : %d, Front : %d, Rear : %d\n", CQ_Dequeue(Queue), Queue->Front, Queue->Rear);
	printf("Dequeue : %d, Front : %d, Rear : %d\n", CQ_Dequeue(Queue), Queue->Front, Queue->Rear);
	printf("Dequeue : %d, Front : %d, Rear : %d\n", CQ_Dequeue(Queue), Queue->Front, Queue->Rear);

	while (CQ_IsFull(Queue) == 0)
	{
		CQ_Enqueue(Queue, i++);
	}

	printf("Capacity : %d, Size : %d\n\n", Queue->Capacity, CQ_GetSize(Queue));

	while (CQ_IsEmpty(Queue) == 0)
	{
		printf("Dequeue : %d, Front : %d, Rear : %d\n", CQ_Dequeue(Queue), Queue->Front, Queue->Rear);
	}

	CQ_DestroyQueue(Queue);

    return 0;
}

