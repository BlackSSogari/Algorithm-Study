// BinaryTree.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagSBTNode
{
	struct tagSBTNode* Left;
	struct tagSBTNode* Right;
	ElementType Data;
}SBTNode;

SBTNode* SBT_CreateNode(ElementType NewData)
{
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void SBT_DestroyNode(SBTNode* Node)
{
	free(Node);
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 루트 노드 출력
	printf(" %c", Node->Data);

	// 왼쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Left);

	// 오른쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Right);
}

void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 왼쪽 하위 트리 출력
	SBT_InorderPrintTree(Node->Left);

	// 루트 노드 출력
	printf(" %c", Node->Data);

	// 오른쪽 하위 트리 출력
	SBT_InorderPrintTree(Node->Right);
}

void SBT_PostorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 왼쪽 하위 트리 출력
	SBT_PostorderPrintTree(Node->Left);

	// 오른쪽 하위 트리 출력
	SBT_PostorderPrintTree(Node->Right);

	// 루트 노트 출력
	printf(" %c", Node->Data);
}

void SBT_DestroyTree(SBTNode* Root)
{
	if (Root == NULL)
		return;

	// 왼쪽 하위 트리 소멸
	SBT_DestroyTree(Root->Left);

	// 오른쪽 하위 트리 소멸
	SBT_DestroyTree(Root->Right);

	// 루트 노드 소멸
	SBT_DestroyNode(Root);
}

int main(void)
{
	// 노드 생성
	SBTNode* A = SBT_CreateNode('A');
	SBTNode* B = SBT_CreateNode('B');
	SBTNode* C = SBT_CreateNode('C');
	SBTNode* D = SBT_CreateNode('D');
	SBTNode* E = SBT_CreateNode('E');
	SBTNode* F = SBT_CreateNode('F');
	SBTNode* G = SBT_CreateNode('G');

	// 트리에 노드 추가
	A->Left = B;
	B->Left = C;
	B->Right = D;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	// 트리 출력
	printf("Preorder...\n");
	SBT_PreorderPrintTree(A);
	printf("\n\n");

	printf("Inorder...\n");
	SBT_InorderPrintTree(A);
	printf("\n\n");

	printf("Postorder...\n");
	SBT_PostorderPrintTree(A);
	printf("\n\n");

	// 트리 소멸 시키기
	SBT_DestroyTree(A);

    return 0;
}

