// ArrayStack.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "ArrayStack.h"


int main()
{
	int i = 0;
	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 10);

	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);

	for (i = 0; i < 100; i++)
	{
		if (AS_IsFull(Stack))
			break;

		AS_Push(Stack, i);
	}

	printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

	for (i = 0; i < Stack->Capacity; i++)
	{
		if (AS_IsEmpty(Stack))
			break;

		printf("Popped : %d, ", AS_Pop(Stack));

		if (!AS_IsEmpty(Stack))
			printf("Current Top : %d\n", AS_Top(Stack));
		else
			printf("Stack Is Empty.\n");
	}

	AS_DestroyStack(Stack);

    return 0;
}

void AS_CreateStack(ArrayStack ** Stack, int Capacity)
{
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack * Stack)
{
	free(Stack->Nodes);

	free(Stack);
}

void AS_Push(ArrayStack * Stack, ElementType Data)
{
	int Position = Stack->Top;

	Stack->Nodes[Position].Data = Data;
	Stack->Top++;
}

ElementType AS_Pop(ArrayStack * Stack)
{
	int Position = --(Stack->Top);

	return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack)
{
	int Position = Stack->Top - 1;
	
	return Stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack * Stack)
{
	return Stack->Top;
}

int AS_IsEmpty(ArrayStack * Stack)
{
	return (Stack->Top == 0);
}

int AS_IsFull(ArrayStack* Stack)
{
	if (Stack->Capacity <= Stack->Top)
		return 1;

	return 0;
}
