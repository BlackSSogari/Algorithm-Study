// QuickSort.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(int* A, int* B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

int Partition(int DataSet[], int Left, int Right)
{
	int First = Left;
	int Pivot = DataSet[First];

	++Left;

	while (Left <= Right)
	{
		// 왼쪽에서 오른쪽으로 진행하면서, Pivot보다 큰값을 찾는다.
		while (DataSet[Left] <= Pivot && Left < Right)
		{
			++Left;
		}

		// 오른쪽에서 왼쪽으로 진행하면서, Pivot보다 작은값을 찾는다.
		while (DataSet[Right] > Pivot && Left < Right)
		{
			--Right;
		}

		if (Left < Right)
		{
			Swap(&DataSet[Left], &DataSet[Right]);
		}
		else
		{
			break;
		}
	}

	Swap(&DataSet[First], &DataSet[Right]);
	return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = Partition(DataSet, Left, Right);

		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}

int CompareScore(const void* _elem1, const void* _elem2)
{
	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 > *elem2)
		return 1;
	else if (*elem1 < *elem2)
		return -1;
	else
		return 0;
}

int main()
{
	int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;

	//QuickSort(DataSet, 0, Length - 1);

	qsort((void*)DataSet, Length, sizeof(int), CompareScore);

	for ( i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}
	
	printf("\n");

    return 0;
}

