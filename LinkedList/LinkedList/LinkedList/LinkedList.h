#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
} Node;

Node* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node* node);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_InsertAfter(Node* Current, Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewHead);
void SLL_RemoveNode(Node** Head, Node* Remove);
Node* SLL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);
void SLL_InsertBefore(Node** _Head, Node* _Current, Node* _NewNode);
void SLL_DestroyAllNodes(Node** _List);
