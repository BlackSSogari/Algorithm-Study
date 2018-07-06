#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
}Node;

typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;
}LinkedListStack;


void	LLS_CreateStack(LinkedListStack** Stack);
void	LLS_DestroyStack(LinkedListStack* Stack);

Node*	LLS_CreateNode(const char* NewData);
void	LLS_DestroyNode(Node* Node);

void	LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node*	LLS_Pop(LinkedListStack* Stack);

Node*	LLS_Top(LinkedListStack* Stack);
int		LLS_GetSize(LinkedListStack* Stack);
int		LLS_IsEmpty(LinkedListStack* Stack);